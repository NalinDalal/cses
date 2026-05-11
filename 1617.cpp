/*Bit Strings
Time limit: 1.00 s
Memory limit: 512 MB

Your task is to calculate the number of bit strings of length n.
For example, if n=3, the correct answer is 8, because the possible bit strings
are 000, 001, 010, 011, 100, 101, 110, and 111. Input The only input line has an
integer n. Output Print the result modulo 10^9+7. Constraints

1 \le n \le 10^6

Example
Input:
3

Output:
8
 */

/*say string is of length n
 * now each index has only 2 possible values: 0 or 1
 * so total possible string 2 /times 2 /times 2 .... n times
 * total : 2^n

 */
#include <iostream>

const long long MOD = 1e9 + 7;

long long binpow(long long a, long long b) {
  long long res = 1;

  while (b > 0) {
    if (b & 1)
      res = (res * a) % MOD;

    a = (a * a) % MOD;
    b >>= 1;
  }

  return res;
}
int main() {
  std::ios::sync_with_stdio(false);
  long long n;
  std::cin >> n;
  long long ans = binpow(2, n);

  std::cout << ans << std::endl;

  // long long ans = pow(2, n);
  // can't do this cause overflow problem
  // store only remainder instead of full value: ans MOD (10^9+7)
  // via for loop it really overflows quickly
  // hence after each iteration, apply the mod; more efficient: binary
  // exponentiation Process exponent bit by bit. Checks if current bit is odd /
  // set. Include current contribution. Move to next power by squaring. Divide
  // exponent by 2.
  // Shift bits right.
  return 0;
}
// sub: https://cses.fi/problemset/result/17131301/
