(define (sum-of-squares n)
  (sum-of-squares-body 0 1 n))

(define (sum-of-squares-body s i n)
  (if (> i n)
      s
      (sum-of-squares-body (+ s (square i)) (+ i 1) n)))

(define (square x)
  (* x x))

(define (sum-of-integers n)
  (sum-of-integers-body 0 1 n))

(define (sum-of-integers-body s i n)
  (if (> i n)
      s
      (sum-of-integers-body (+ s i) (+ i 1) n)))

(define (pe-006 n)
  (- (square (sum-of-integers n))
     (sum-of-squares n)))

; Run with (pe-006 100)
