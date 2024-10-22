;Generate a list of numbers from 'start' to 'stop'
(define gen-list
  (lambda (start stop)
    (if (> start stop)
        '()  ;If start is greater than stop, return an empty list
        (cons start (gen-list (+ start 1) stop)))))  ;Otherwise, add 'start' and recurse

;Check if there exists a pair in 'lyst' that sums to 'desired'
(define pair-sum?
  (lambda (lyst desired)
    (cond
      ((null? lyst) #f)  ;If the list is empty, return false
      ((null? (cdr lyst)) #f)  ;If there’s only one element, return false
      ((= (+ (car lyst) (cadr lyst)) desired) #t)  ;Check if the sum of the first two elements equals 'desired'
      (else (pair-sum? (cdr lyst) desired)))))  ;Recur with the rest of the list

;Generate a lazy list from 'start' to 'stop'
(define gen-lazy-list
  (lambda (start stop)
    (if (> start stop)
        '()  ;Return an empty list if start exceeds stop
        (cons start (lambda () (gen-lazy-list (+ start 1) stop))))))  ;Cons the current number and a thunk for the rest

;Create an infinite sequence starting from 'first'
(define inf-seq
  (lambda (first)
    (cons first (lambda () (inf-seq (+ first 1))))))  ;Cons 'first' and a thunk for the next number

;; Convert a regular list into a lazy list
(define make-lazy
  (lambda (lyst)
    (if (null? lyst)
        '()  ;Return an empty list if input list is empty
        (cons (car lyst) (lambda () (make-lazy (cdr lyst)))))))  ;Cons the first element and a thunk for the rest

;Check if a lazy list contains a pair that sums to 'desired'
(define pair-sum-lazy?
  (lambda (lazy-list desired)
    (cond
     ((null? ((cdr lazy-list)))  #f)  ;If the list has no elements left, return false
     ((= (+ (car lazy-list) (car ((cdr lazy-list)))) desired)  #t)  ;Check the sum of the first element and the second
     (else (pair-sum-lazy? ((cdr lazy-list)) desired)))))  ;Recur with the rest of the lazy list

;Retrieve the first 'n' elements from a lazy list
(define first-n
  (lambda (lazy-list n)
    (cond
      ((null? lazy-list) '())  ;If the lazy list is empty, return an empty list
      ((= n 0) '())  ;If n is zero, return an empty list
      (else (cons (car lazy-list) (first-n ((cdr lazy-list)) (- n 1)))))))  ;Cons the head and recurse

;Retrieve the nth element from a lazy list
(define nth
  (lambda (lazy-list n)
    (cond
      ((null? lazy-list) #f)  ;Return false if the lazy list is empty
      ((<= n 1) (car lazy-list))  ;If n is 1 or less, return the head of the lazy list
      (else (nth ((cdr lazy-list)) (- n 1))))))  ;Recur with the tail, decrementing n

;Filter out multiples of 'n' from a lazy list
(define filter-multiples
  (lambda (lazy-list n)
    (cond
      ((null? lazy-list) '())  ;Return an empty list if the lazy list is empty
      ((= (car lazy-list) 0) (filter-multiples ((cdr lazy-list)) n))  ;Skip zeros
      ((zero? (modulo (car lazy-list) n)) (filter-multiples ((cdr lazy-list)) n))  ;Skip multiples of n
      (else (cons (car lazy-list) (lambda () (filter-multiples ((cdr lazy-list)) n)))))))  ;Keep the element and recurse
