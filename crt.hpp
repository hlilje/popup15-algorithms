/*
 * Calculate the modular multiplicative inverse `x` of `a` and `b` such that
 * (a * x) mod b = 1 using the extended Euclidian algorithm.
 *
 * @param a: The first number.
 * @param b: The second number.
 * @return:  The modular multiplicative inverse of `a` and `b`.
 */
 long long mul_inv(long long a, long long b);

 /*
  * Use the Chinese Remainder Theorem to calculate x mod K such that
  * x = a (mod n), x = b (mod m).
  *
  * @param a: x mod n.
  * @param n: First modulus.
  * @param b: x mod m.
  * @param m: Second modulus.
  * @param K: n * m.
  * @return: x mod K: x = a (mod n), x = b (mod m).
  */
 long long crt(const long long,
               const long long,
               const long long,
               const long long,
               const long long);
