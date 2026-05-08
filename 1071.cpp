// https://cses.fi/problemset/task/1071
/*Number Spiral
Time limit: 1.00 s
Memory limit: 512 MB

A number spiral is an infinite grid whose upper-left square has number 1. Here
are the first five layers of the spiral: 1 2 9 10 25 4 3 8 11 24 5 6 7 12 23 16
15 14 13 22 17 18 19 20 21


Your task is to find out the number in row y and column x.
Input
The first input line contains an integer t: the number of tests.
After this, there are t lines, each containing integers y and x.
Output
For each test, print the number in row y and column x.
Constraints

1 \le t \le 10^5
1 \le y,x \le 10^9

Example
Input:
3
2 3
1 1
4 2

Output:
8
1
15

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {

    long long y, x;
    cin >> y >> x;

    long long mx = max(x, y);
    long long ans;

    if (mx % 2 == 0) {

      if (y == mx) {
        ans = mx * mx - x + 1;
      } else {
        ans = (mx - 1) * (mx - 1) + y;
      }

    } else {

      if (x == mx) {
        ans = mx * mx - y + 1;
      } else {
        ans = (mx - 1) * (mx - 1) + x;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
