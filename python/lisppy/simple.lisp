(label add (quote a b) (+ a b))

(label x 96)

(print (add 42 x))
(print (car (cdr (cons x (quote 2 3)))))

(label sqr (lambda (quote a) (+ a a)))
