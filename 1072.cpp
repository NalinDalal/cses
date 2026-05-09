/*https://cses.fi/problemset/task/1072

Two Knights

Time limit: 1.00 s
Memory limit: 512 MB

Your task is to count for k=1,2,\ldots,n the number of ways two knights can be
placed on a k \times k chessboard so that they do not attack each other. Input
The only input line contains an integer n.
Output
Print n integers: the results.
Constraints

1 \le n \le 10000

Example
Input:
8

Output:
0
6
28
96
252
550
1056
1848
 */

// given a n, do from 1 to n
// so k runs from 1 to n,
// return no of ways to put 2 knights on k*k chessboard

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio();
  int n;
  cin >> n;

  for (int k = 1; k <= n; k++) {

    // no of ways to place 2 knights on k*k chessboard
    // knights move in l shape, 2 straight, 1 right or left
    // 1 knights has only 8 possible moves from a cell
    // just need to mind that 8 position with repect to other

    // 1x1 cell-> 0
    // 2x2 cell-> 2x2 C 2 = 6
    // tc*(tc-1)/2
    // ans=total ways-ways so that they attack
    // m*m grid => 2*3 slab=(m-2)*(m-1) ways
    //               3*2 slab=(m-1)*(m-2) ways
    // ans=total-2x3-3x2
    //   = total-[2*(m-1)*(m-2)]*2
    //   = (k^2 C 2) - [2*(m-1)*(m-2)]*2

    long long t_cells = k * k;
    if (k == 1)
      cout << 0 << endl;
    else {
      // total ways to place knights
      long long total = (t_cells * (t_cells - 1)) / 2;

      // no of 2x3 and 3x2 slabs
      long long slabs = (k - 1) * (k - 2) * 2 * 2;
      cout << total - slabs << endl;
    }
  }

  return 0;
}
// sub: https://cses.fi/problemset/result/17120262/
