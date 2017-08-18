(define even-fib-sum
  (lambda (end)
    (even-fib-sum-iter 0 0 1 end)))

(define even-fib-sum-iter
  (lambda (sum a b end)  ; a = f_n+1, b = f_n
    (cond
     ((> a end) sum)
     ((even? a) (even-fib-sum-iter (+ a sum)
                                   (+ a b)
                                   a
                                   end))
     (else (even-fib-sum-iter sum
                              (+ a b)
                              a
                              end)))))

; Run with (even-fib-sum 4000000)
