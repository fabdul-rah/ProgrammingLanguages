;Input bst: A binary search tree (possibly empty).
;Return: The integer key stored in bst's root node (or #f if bst is empty).
(define entry
  (lambda (bst)
    (if (null? bst)
	#f)
    (if  (and (list? bst) (= (length bst) 3))
	(car bst)
	#f)))

	

	
;Input bst: A binary search tree (possibly empty).
;Return: The left subtree of bst's root node (or #f if bst is empty).
(define left
  (lambda (bst)
    (if (null? bst)
	#f)
    (if (and (list? bst) (= (length bst) 3))
	(car (cdr bst))
	#f)))


;Input bst: A binary search tree (possibly empty).
;Return: The right subtree of bst's root node (or #f if bst is empty).
(define right
  (lambda (bst)
    (if (null? bst)
	#f)
    (if (and (list? bst) (= (length bst) 3))
	(car (cdr (cdr bst)))
	#f)))

;Input elt: An integer.
;Input left-bst: A binary search tree (possibly empty).
;Input right-bst: A binary search tree (possibly empty).
;Return: A binary search tree whose root contains elt as its key, and whose left and 
					;right subtrees are left-bst and right-bst.
(define make-bst
  (lambda (elt left-bst right-bst)
	(list elt left-bst right-bst)))
	       
    
    
;Input bst: A binary search tree (possibly empty).
;Return: A list of all entries in bst, ordered according to a preorder traversal.
(define preorder
  (lambda (bst)
    (if (null? bst)
        '()  ; Return an empty list for an empty tree
        (cons (entry bst)  ; Visit the root
              (append (preorder (left bst))  ; Traverse left
                      (preorder (right bst)))))))  ; Traverse right
    

;Input bst: A binary search tree (possibly empty).
;Return: A list of all entries in bst, ordered according to a inorder traversal.
(define inorder
  (lambda (bst)
    (if (null? bst)
	'() ; Return an empty list for an empty tree
	(append (inorder (left bst)) ;Traverse left
		(list (entry bst)) ;Visit the root
		(inorder (right bst)))))) ; Traverse right

;Input bst: A binary search tree (possibly empty).
;Return: A list of all entries in bst, ordered according to a postorder traversal.
(define postorder
  (lambda (bst)
    (if (null? bst)
	'() ; Return an empty list for an empty tree
	(append (postorder (left bst)) ;Traverse left
		(postorder (right bst)) ;traverse right
		(list (entry bst)))))) ;Visit root

;Input v: An integer.
;Input bst: A binary search tree (possibly empty).
;Return: A binary search tree, equal to the result of inserting v into bst. If bst 
;already contained v, then this result is identical to bst.
(define insert
  (lambda (v bst)
    (cond
      ((null? bst) (make-bst v '() '()))  ; Create a new node if bst is empty
      ((= v (entry bst)) bst)               ; Return bst if v is already present
      ((< v (entry bst))                     ; If v is less than the root key
       (make-bst (entry bst) 
                  (insert v (left bst)) 
                  (right bst)) )           ; Insert into left subtree
      (else                                   ; If v is greater than the root key
       (make-bst (entry bst) 
                  (left bst) 
                  (insert v (right bst))))))) ; Insert into right subtree
