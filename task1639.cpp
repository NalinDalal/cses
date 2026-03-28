// https://cses.fi/problemset/task/1639
/*Edit Distance
Time limit: 1.00 s
Memory limit: 512 MB

The edit distance between two strings is the minimum number of operations
required to transform one string into the other. The allowed operations are:

Add one character to the string.
Remove one character from the string.
Replace one character in the string.

For example, the edit distance between LOVE and MOVIE is 2, because you can
first replace L with M, and then add I. Your task is to calculate the edit
distance between two strings. Input The first input line has a string that
contains n characters between A–Z. The second input line has a string that
contains m characters between A–Z. Output Print one integer: the edit distance
between the strings. Constraints

1 \le n,m \le 5000

Example
Input:
LOVE
MOVIE

Output:
2





 */

#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  int n = a.length(); // n <= 100
  int m = b.length(); // m <= 10^5
  // O(min(n, m))
  if (n < m) {
    swap(a, b);
    swap(n, m);
  }
  // base case
  vector<int> prev(m + 1); // currently stores dp[0][j]
  for (int j = 0; j <= m; j++) {
    prev[j] = j;
  }

  for (int i = 1; i <= n; i++) {
    vector<int> current(m + 1);
    current[0] = i; // means dp[i][0] = i
    for (int j = 1; j <= m; j++) {
      char x = a[i - 1];
      char y = b[j - 1];

      // transition
      if (x == y) { // don't do anything
        current[j] = prev[j - 1];
        // current[j] = dp[i][j]
        // prev[j - 1] = dp[i - 1][j - 1]
      } else { // replace character to match
        current[j] = prev[j - 1] + 1;
      }

      // skip ith character or add one character after jth character
      current[j] = min(current[j], prev[j] + 1);

      // skip jth character or add one character after ith character
      current[j] = min(current[j], current[j - 1] + 1);
    }
    prev = current;
  }

  // final subproblem
  cout << prev[m] << endl;
  return 0;
}
// sub: https://cses.fi/problemset/result/16709353/
