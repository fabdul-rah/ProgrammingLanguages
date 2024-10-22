; Input f: A function of three arguments.
; Return: A function, which is the curried version of f.
(define curry3
  (lambda (f)
    (lambda (x)
      (lambda (y)
        (lambda (z)
          (f x y z))))))


; Input c: A function, which is the curried version of some function of three arguments.
; Return: A function of three arguments, which is the uncurried version of c.
(define uncurry3
  (lambda (c)
    (lambda (x y z)
      ((c x) y z))))



; Input pred: A function of one argument that returns a Boolean.
; Input lyst: A list.
; Return: A list consisting of all list elements for which pred returns #t.
(define my-filter
  (lambda (pred lyst)
    (cond
      ((null? lyst) '())  ; If the list is empty, return an empty list.
      ((pred (car lyst))  ; Check if the first element satisfies the predicate.
       (cons (car lyst) (my-filter pred (cdr lyst))) ; Include it and recurse.
       )
      (else               ; If it doesn't satisfy the predicate, skip it.
       (my-filter pred (cdr lyst)))))) ; Recurse on the rest of the list.

; Input pred: A function of one argument that returns a Boolean.
; Input lyst: A list.
; Return: A Boolean: #t if any element of the list evaluates to #t under pred, and #f if all
; elements of the list evaluate to #f under pred.
(define exists
  (lambda (pred lyst)
    (cond
      ((null? lyst) #f)                          ; If the list is empty, return #f.
      ((pred (car lyst)) #t)                    ; If the predicate is true for the first element, return #t.
      (else (exists pred (cdr lyst))))))       ; Otherwise, recurse on the rest of the list.

; Input symb: A symbol.
; Input docs: A list of key-value pairs. A key is a symbol. A value is a list of symbols.
; Return: A list of all of the keys, such that symb is a member of the value associated to that key.
(define find-docs
  (lambda (symb docs)
    (map car                            ; Get the keys from the pairs
         (filter (lambda (pair)       ; Filter pairs based on the presence of symb
                   (memv symb (cadr pair))) ; Check if symb is in the value list
                 docs))))               ; Use the original docs list
