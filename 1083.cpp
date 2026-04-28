/* https://cses.fi/problemset/task/1083
Time limit: 1.00 s
Memory limit: 512 MB

You are given all numbers between 1,2,\ldots,n except one. Your task is to find
the missing number. Input The first input line contains an integer n. The second
line contains n-1 numbers. Each number is distinct and between 1 and n
(inclusive). Output Print the missing number. Constraints

2 \le n \le 2 \cdot 10^5

Example
Input:
5
2 3 1 5

Output:
4
 */

/*
// given a array of numbers, there is a missing number b/w 1 and n
// find and return the missing number
// what if we do like sort the array: O(nlogn)
// apply binary search to find missing number: O(log n)
// binary search logic{
//   if(vec[n/2]==n/2) then apply in right half
//   else apply in left half
//   then check again for them in that reduced array to search in
// }

int l = 0, r = n - 1;
while (l <= r) {
  int mid = (l + r) / 2;
  if (v[mid] == mid + 1) {
    // apply in right half
    l = mid + 1;
    r = n - 1;
  } else {
    // apply in left half
    r = mid - 1;
  }

  // when it doesn't matches, we need to check for no just in previous index
  // if(v[mid]!=mid+1) then apply in left half and check for no
  // else apply in right half and check for no
  // can we optmise the checking?
  // when it breaks, need to return missing number while checking when if it
  // get's in order again it's like check where break, then check where is in
  // order again, place where it comes in order
}
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  map<long long, long long> mp;
  for (int i = 1; i < n; i++) {
    long long x;
    cin >> x;
    mp[x]++;
  }
  for (int i = 1; i <= n; i++) {
    if (mp[i] == 0) {
      cout << i << endl;
    }
  }
}
// sub: https://cses.fi/problemset/result/17027515/
