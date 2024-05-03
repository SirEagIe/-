(defun sum(x y) (cond 
((and (null x)(null y)) nil) 
((and (null x) (listp y)) y) 
((and (null y) (listp x)) x)
(t (cons(+ (car x) (car y)) (sum(cdr x) (cdr y))))))

(defun rev(x) (append x (reverse x)))

(defun neg(x) (do
((iter 0 (+ iter 1)))
((eq iter (length x)) x)
(if (< (nth iter x) 0)
	(if (and (null (eq 0 iter)) (null (eq iter (- (length x) 1))))
		(setf (nth iter x) (* (nth(- iter 1) x) (nth(+ iter 1) x))) nil) nil)))

(defun swap(l i1 i2)
(setq res '(1))
(do
((i 0 (+ i 1)))
((eq i (length l)) res)
(cond ((= i1 i) (append (res) (nth i1 l)))
      ((= i2 i) (append (res) (nth i2 l)))
	  (T (append (res) (nth i l)))
)))

(defun swap (i1 i2 lst)
	(psetf (nth i1 lst) (nth i2 lst) (nth i2 lst) (nth i1 lst)) lst)
 

(defun compare(l p)
	(cond ((null l) (null p)) ((null p) t) ((equal (car l) (car p)) 
		(compare (cdr l) (cdr p)))))

(defun find(l p) 
	(cond ((null l) nil) ((compare l p) p) 
		(t (find (cdr l) p))))