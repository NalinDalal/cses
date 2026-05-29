// https://cses.fi/problemset/task/2165
/*Tower of Hanoi
Time limit: 1.00 s
Memory limit: 512 MB

The Tower of Hanoi game consists of three stacks (left, middle and right) and n
round disks of different sizes. Initially, the left stack has all the disks, in
increasing order of size from top to bottom. The goal is to move all the disks
to the right stack using the middle stack. On each move you can move the
uppermost disk from a stack to another stack. In addition, it is not allowed to
place a larger disk on a smaller disk. Your task is to find a solution that
minimizes the number of moves. Input The only input line has an integer n: the
number of disks. Output First print an integer k: the minimum number of moves.
After this, print k lines that describe the moves. Each line has two integers a
and b: you move a disk from stack a to stack b. Constraints

1 \le n \le 16

Example
Input:
2

Output:
3
1 2
1 3
2 3
 */

#include <bits/stdc++.h>
using namespace std;

int moves = 0;

void hanoi(int n, int from, int to, int aux) {
  // moves n dics from 'from' to 'to',aux is temp stack
  if (n == 0)
    return;
  hanoi(n - 1, from, aux, to);
  cout << from << " " << to << endl;
  moves++;
  hanoi(n - 1, aux, to, from);
}

int main() {
  int n;
  cin >> n;                     // take the disc size
  cout << (1 << n) - 1 << endl; // no of moves
  hanoi(n, 1, 3, 2);            // call the hanoi function on no of disc
  return 0;
}
// sub: https://cses.fi/problemset/result/17344140/
