/*https://cses.fi/problemset/task/1069
Time limit: 1.00 s
Memory limit: 512 MB

You are given a DNA sequence: a string consisting of characters A, C, G, and T.
Your task is to find the longest repetition in the sequence. This is a
maximum-length substring containing only one type of character. Input The only
input line contains a string of n characters. Output Print one integer: the
length of the longest repetition. Constraints

1 \le n \le 10^6

Example
Input:
ATTCGGGA

Output:
3
 */

// given a string, find length of longest repetition
// like go through the string, check for string where we have same char
// store it's length
// when you encounter a new string, store it's length, compare with prev like in
// maxLen, with currLen maxLen=max(maxlen,currLen) do this till end of string
// return maxLen

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int maxLen = 0, currLen = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == s[i + 1])
      currLen++;
    else if (s[i] != s[i + 1]) {
      // break it there, again do currLen=0 and then check again till the
      // pattern breaks
      maxLen = max(maxLen, currLen);
      currLen = 0;
    }
  }
  cout << maxLen + 1 << endl;

  return 0;
}
// https://cses.fi/problemset/result/17102430/
