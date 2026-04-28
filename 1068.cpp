/* https://cses.fi/problemset/task/1068
Consider an algorithm that takes as input a positive integer n. If n is even,
the algorithm divides it by two, and if n is odd, the algorithm multiplies it by
three and adds one. The algorithm repeats this, until n is one. For example, the
sequence for n=3 is as follows:
$$ 3 \rightarrow 10 \rightarrow 5 \rightarrow 16 \rightarrow 8 \rightarrow 4
\rightarrow 2 \rightarrow 1$$ Your task is to simulate the execution of the
algorithm for a given value of n. Input The only input line contains an integer
n. Output Print a line that contains all values of n during the algorithm.
Constraints

1 \le n \le 10^6

Example
Input:
3

Output:
3 10 5 16 8 4 2 1





 */

// we need to apply algorithm till the value of n is 1
// else push back 1 to vector and break off the loop
// it's like till n!=1 we need to apply the algorithm again and again
// algorithm say:
//    if n is even then n=n/2
//    if n is odd then n=3*n+1
//
// return an array of all values of n

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;

  while (true) {
    cout << n << " ";
    if (n == 1)
      break;

    if (n % 2)
      n = 3 * n + 1;
    else
      n /= 2;
  }

  return 0;
}
