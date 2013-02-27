case class B[F,T](c: B[F, T] => (F => T)) extends (B[F, T] => (F => T)) {
    def apply(b: B[F, T]) = c(b);
}

def Y[F, T] = (f: (F => T) => F => T) =>
  B[F, T](x => f(x(x)(_)))(B(x => f(x(x)(_))))

/**
val factorial = Y[Int, Int](f => i => if (i <= 0) 1 else f(i - 1) * i)
*/
