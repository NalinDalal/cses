/*https://cses.fi/problemset/task/1070
Permutations
Time limit: 1.00 s
Memory limit: 512 MB

A permutation of integers 1,2,\ldots,n is called beautiful if there are no
adjacent elements whose difference is 1. Given n, construct a beautiful
permutation if such a permutation exists. Input The only input line contains an
integer n. Output Print a beautiful permutation of integers 1,2,\ldots,n. If
there are several solutions, you may print any of them. If there are no
solutions, print "NO SOLUTION". Constraints

1 \le n \le 10^6

Example 1
Input:
5

Output:
4 2 5 3 1
Example 2
Input:
3

Output:
NO SOLUTION
 */

// given n, print 1 to n in a manner that diff of adjacent elements is not 1

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  // what if we create a 2d table
  // store all permutation of 1 to n in a single row
  // then remove all permutation where diff of adjacent elements is 1
  // then print any of permutation
  // edit, optimisation: diff b/w any of consecutive odd or even is 2
  if (n == 1)
    cout << 1 << endl;
  else if (n == 2 || n == 3)
    cout << "NO SOLUTION" << endl;
  else {
    for (int i = 2; i <= n; i += 2) {
      cout << i << " ";
    }

    for (int i = 1; i <= n; i += 2) {
      cout << i << " ";
    }
  }
  return 0;
}

// 5
// 2 4 1 3 5
// 7
// 2 4 6 1 3 5 7
// sub: https://cses.fi/problemset/result/17112434/
