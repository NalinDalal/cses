// https://cses.fi/problemset/task/1754
/*Coin Piles
Time limit: 1.00 s
Memory limit: 512 MB

You have two coin piles containing a and b coins. On each move, you can either
remove one coin from the left pile and two coins from the right pile, or two
coins from the left pile and one coin from the right pile. Your task is to
efficiently find out if you can empty both the piles. Input The first input line
has an integer t: the number of tests. After this, there are t lines, each of
which has two integers a and b: the numbers of coins in the piles. Output For
each test, print "YES" if you can empty the piles and "NO" otherwise.
Constraints

1 \le t \le 10^5
0 \le a, b \le 10^9

Example
Input:
3
2 1
2 2
3 3

Output:
YES
NO
YES
 */

/*a no of coins, b no of coins
 either a-=2 and b-=1
 or a-=1 and b-=2

 find if you can empty both a,b

     // watching over testcases i feel what if we do like sum of a,b if it's
    // divisible by 3, alongwith a,b individually then possible
well wrong ans
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    bool possible = false;

    // what if we do it like , wait 2d dp
    // one way is to do -1,-2
    // another is to do -2,-1
    // like there are always 2 ways: either do a-=2,b-=1 or a-=1,b-=2
    // let's try to like actually visualise it step by step
    // you got a,b as input
    // do a-=2,b-=1
    // also if anywhere it happens like a+b%3 then not possible

    if ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a)
      possible = true;
    else {
      // like start at a[0][0] that has a,b originally
      // then either do a-=2,b-=1 to go right
      // or a-=1,b-=2 to go down
      // if anywhere we encounter a=0,b=0, we got the solution, it's possible
      // else not possible
      // too much complexity
      int n = a + b;
      // x= no of time we do, a-=2,b-=1
      // y= no of time we do, a-=1,b-=2
      // 2x + y = a
      // x + 2y = b
      // 3x+3y=a+b
      // x - y = a - b → x = (2a - b) / 3, y = (2b - a) / 3
      // 2a >= b
      // 2b >= a
      possible = false;
    }
    if (possible)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
// sub: https://cses.fi/problemset/result/17302353/
