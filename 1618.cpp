// https://cses.fi/problemset/task/1618
/*Trailing Zeros
Time limit: 1.00 s
Memory limit: 512 MB

Your task is to calculate the number of trailing zeros in the factorial n!.
For example, 20!=2432902008176640000 and it has 4 trailing zeros.
Input
The only input line has an integer n.
Output
Print the number of trailing zeros in n!.
Constraints

1 \le n \le 10^9

Example
Input:
20

Output:
4
 */

#include <iostream>

int main() {
  int n;
  std::cin >> n;

  long long ans = 0;
  // print no of trailing zeroes in n!
  // brute force: calculate n!
  // convert to string, count trailing zeroes:  almost overflow
  // formula: floor(n/5)+floor(n/25)+floor(n/125)...

  while (n > 0) {
    n /= 5;
    ans += n;
  }

  std::cout << ans << '\n';

  return 0;
}
// sub: https://cses.fi/problemset/result/17139245/
