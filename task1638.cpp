// https://cses.fi/problemset/task/1638
/*Grid Paths I
Consider an n \times n grid whose squares may have traps. It is not allowed to
move to a square with a trap. Your task is to calculate the number of paths from
the upper-left square to the lower-right square. You can only move right or
down.

Input
The first input line has an integer n: the size of the grid.
After this, there are n lines that describe the grid. Each line has n
characters: . denotes an empty cell, and * denotes a trap. Output Print the
number of paths modulo 10^9+7.


*/

/*defind a dp state
dp[i][j]= no of ways to move from (i,j) to (n-1,m-1)

dp[i][j]=dp[i+1][j]+dp[i][j+1]

base case: dp[n-1][n-1] is 1 or 0
1 when no obstacle
0 when have obstacle

subproblem: dp[0][0]

transition time: O(1)
total states: O(n^2)

time complexity: O(n^2)

space : O(n^2)
*/
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
  int n;
  cin >> n;

  vector<string> grid(n);
  for (int i = 0; i < n; i++)
    cin >> grid[i];

  vector<vector<long long>> dp(n, vector<long long>(n, 0));

  if (grid[0][0] == '.')
    dp[0][0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      if (grid[i][j] == '*')
        continue;

      if (i > 0)
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;

      if (j > 0)
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
    }
  }

  cout << dp[n - 1][n - 1];
}
// sub: https://cses.fi/problemset/result/16703356/
