/*https://cses.fi/problemset/task/1094
Increasing Array
Time limit: 1.00 s
Memory limit: 512 MB

You are given an array of n integers. You want to modify the array so that it is
increasing, i.e., every element is at least as large as the previous element. On
each move, you may increase the value of any element by one. What is the minimum
number of moves required? Input The first input line contains an integer n: the
size of the array. Then, the second line contains n integers x_1,x_2,\ldots,x_n:
the contents of the array. Output Print the minimum number of moves. Constraints

1 \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9

Example
Input:
5
3 2 5 1 7

Output:
5
 */

// modify the array so that it is increasing, i.e., every element is at least as
// large as the previous element.

// every element is at least as large as the previous element.

/*traverse the array,
 init ans=0;
  if curr is less than prev element, then count=prev-curr
  ans=ans+count
  return ans
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  long long ans = 0;
  for (int i = 1; i < n; i++) {
    if (v[i] < v[i - 1]) {
      int count = v[i - 1] - v[i];
      ans += count;
      v[i] = v[i - 1];
    }
  }
  cout << ans << endl;
  return 0;
}
// sub: https://cses.fi/problemset/result/17110712/
