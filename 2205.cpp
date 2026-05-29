// https://cses.fi/problemset/task/2205
/*Gray Code
Time limit: 1.00 s
Memory limit: 512 MB

A Gray code is a list of all 2^n bit strings of length n, where any two
successive strings differ in exactly one bit (i.e., their Hamming distance is
one). Your task is to create a Gray code for a given length n. Input The only
input line has an integer n. Output Print 2^n lines that describe the Gray code.
You can print any valid solution. Constraints

1 \le n \le 16

Example
Input:
2

Output:
00
01
11
10
 */

#include <bitset>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int total = 1 << n;
  for (int i = 0; i < total; i++) {
    // The i-th Gray code is computed as `i ^ (i >> 1)`, then converted to an
    // n-bit binary string using `bitset`.

    int gray = i ^ (i >> 1);
    bitset<16> bits(gray);
    string s = bits.to_string().substr(16 - n);
    cout << s << endl;
  }
  return 0;
}
// sub: https://cses.fi/problemset/result/17344042/
