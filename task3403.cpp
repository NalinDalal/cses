// https://cses.fi/problemset/task/3403
/*Longest Common Subsequence

Time limit: 1.00 s
Memory limit: 512 MB

Given two arrays of integers, find their longest common subsequence.
A subsequence is a sequence of array elements from left to right that can
contain gaps. A common subsequence is a subsequence that appears in both arrays.

Input
The first line has two integers n and m: the sizes of the arrays.
The second line has n integers a_1,a_2,\dots,a_n: the contents of the first
array. The third line has m integers b_1,b_2,\dots,b_m: the contents of the
second array.

Output
First print the length of the longest common subsequence.
After that, print an example of such a sequence. If there are several solutions,
you can print any of them. Constraints

1 \le n,m \le 1000
1 \le a_i, b_i \le 10^9

Example
Input:
8 6
3 1 3 2 7 4 8 2
6 5 1 2 3 4

Output:
3
1 2 4
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;

  // dp[i][j] = LCS length using first i elements of a
  // and first j elements of b
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  // build dp table
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      if (a[i - 1] == b[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;

      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  // reconstruct sequence
  vector<int> lcs;

  int i = n, j = m;

  while (i > 0 && j > 0) {

    if (a[i - 1] == b[j - 1]) {
      lcs.push_back(a[i - 1]);
      i--;
      j--;
    }

    else if (dp[i - 1][j] > dp[i][j - 1])
      i--;

    else
      j--;
  }

  reverse(lcs.begin(), lcs.end());

  // output
  cout << dp[n][m] << "\n";

  for (int x : lcs)
    cout << x << " ";

  cout << "\n";
}
// sub: https://cses.fi/problemset/result/16720381/
