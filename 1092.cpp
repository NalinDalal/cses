/*https://cses.fi/problemset/task/1092
Time limit: 1.00 s
Memory limit: 512 MB

Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.
Input
The only input line contains an integer n.
Output
Print "YES", if the division is possible, and "NO" otherwise.
After this, if the division is possible, print an example of how to create the
sets. First, print the number of elements in the first set followed by the
elements themselves in a separate line, and then, print the second set in a
similar way. Constraints

1 \le n \le 10^6

Example 1
Input:
7

Output:
YES
4
1 2 4 7
3
3 5 6
Example 2
Input:
6

Output:
NO
*/

/*let's first try to solve this manually, try to find any pattern
say n=5
1,2,3,4,5

2 set of equal sum:
1,2,4
3,5
nah, not possible here

n=6
1,2,3,4,5,6

n<7 => no solution

n=7
1,2,3,4,5,6,7
1,2,4,7;3,5,6

n=8
1,2,3,4,5,6,7,8
1,2,3,4,7;5,6,8

if total sum is even=> no

apply greedy, it's like amount for all is 1, now need to check for Cost
classic knapsack coin problemset
except for fact the amount of coins are always 1


total=n(n+1)/2
s=total/2

sets s1,s2

for(i=n to 1){
    if(i<=s){
        s1.insert(i)
        s-=i
    }else{
        s2.insert(i)
    }
}
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define len(x) int((x).size())
#define nl endl;
#define sp ' ';

void solve() {
  int n;
  cin >> n;
  ull S = (n * 1LL * (n + 1)) / 2;
  if (S % 2 == 1) {
    cout << "NO" << endl;
    return;
  }
  S /= 2; // target sum

  set<int> st1, st2;
  for (int i = n; i >= 1; i--) {
    if (S > 0 && i <= S) {
      st1.insert(i);
      S -= i;
    } else {
      st2.insert(i);
    }
  }

  cout << "YES" << nl;
  cout << len(st1) << nl;
  for (auto a : st1)
    cout << a << sp;
  cout << nl;
  cout << len(st2) << nl;
  for (auto a : st2)
    cout << a << sp;
  cout << nl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin>>t;
  while (t--)
    solve();
}
// sub: https://cses.fi/problemset/result/17131062/
