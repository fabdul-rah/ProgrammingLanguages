;Input nums: A list of numbers (possibly empty).
;Return: A number. The sum of the numbers in nums (0 if nums is empty).


(define sum                  ;defining the function and its name
  (lambda (nums)             ;making a variable (nums)
    (if (null? nums)         ;if the the variable is empty/NULL then it return zero
        0                    
        (+ (car nums) (sum (cdr nums))))))         ;else it get the car (first element) and adds it to the sum of the cdr (all the values that follow)


;Input n: An integer.
;Input lyst: A list.
;Return: A list consisting of the first n items from lyst.
;If n is 0, then the empty list is returned.
;If n is negative or greater than the length of lyst, then an empty list is returned.


(define keep-first-n :                    ;defining the functions name
  (lambda (n lyst)                        ;parameters/ variable 
    (if (or (<= n 0) (> n (length lyst))) ;adding our conditional if statements to work as instructed
        '()                               ;returns an empty list if conditionals are met
        (cons (car lyst)                  ;Takes the car of the lyst and cons's the values recursiveley
              (keep-first-n (- n 1) (cdr lyst))))))    