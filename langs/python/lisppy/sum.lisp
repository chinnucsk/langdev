(label sum x (cond (eq x 0) 0 (+ (sum (- x 1)) x)))

(label range (quote begin end) (cond (eq begin end) (quote) (cons begin (range (+ begin 1) end))))
(label len list (cond (eq list (quote)) 0 (+ 1 (len (cdr list)))))
(label map (quote fun list) (cond (eq list (quote)) (quote) (cons (fun (car list)) (map fun (cdr list)))))

(label testrange (range 1 8))

(print (len testrange))
(print testrange)
(print (map sum testrange))
