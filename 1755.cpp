/*https://cses.fi/problemset/task/1755
Palindrome Reorder
Time limit: 1.00 s
Memory limit: 512 MB

Given a string, your task is to reorder its letters in such a way that it
becomes a palindrome (i.e., it reads the same forwards and backwards). Input The
only input line has a string of length n consisting of characters A–Z. Output
Print a palindrome consisting of the characters of the original string. You may
print any valid solution. If there are no solutions, print "NO SOLUTION".
Constraints

1 \le n \le 10^6

Example
Input:
AAAACACBA

Output:
AACABACAA
 */

// what if we do like have a hashmap, alphabets against there occurences
// odd one goes in middle
// and well even ones wrap then both side
// nah, kinda problematic, what if more than one alphabet occurs odd times
// well let's try via this method once
//
//  Builds half the palindrome from floor(freq/2) of each character
// Places the odd-frequency character (if any) in the middle
// Mirrors the half to complete the palindrome

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  vector<int> freq(26, 0);
  for (char c : s)
    freq[c - 'A']++;

  int oddCount = 0;
  char oddChar = ' ';
  for (int i = 0; i < 26; i++) {
    if (freq[i] % 2 != 0) {
      oddCount++;
      oddChar = 'A' + i;
    }
  }

  if (oddCount > 1) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  string half = "";
  for (int i = 0; i < 26; i++)
    half += string(freq[i] / 2, 'A' + i);

  string result = half;
  if (oddCount == 1)
    result += oddChar;
  reverse(half.begin(), half.end());
  result += half;

  cout << result << endl;
  return 0;
}
