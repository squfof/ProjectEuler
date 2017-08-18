(define mult-of-3?
  (lambda (x)
    (= (remainder x 3) 0)))

(define mult-of-5?
  (lambda (x)
    (= (remainder x 5) 0)))

(define sum-3-5-iter
  (lambda (sum index end)
    (cond
     ((> index end) sum)
     ((mult-of-3? index) (sum-3-5-iter (+ sum index) (+ index 1) end))
     ((mult-of-5? index) (sum-3-5-iter (+ sum index) (+ index 1) end))
     (else (sum-3-5-iter sum (+ index 1) end)))))

(define sum-3-5
  (lambda (end)
    (sum-3-5-iter 0 1 end)))

; Run with (sum-3-5 999)
