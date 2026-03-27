// link : https://cses.fi/problemset/task/2422
/*given a input integer n,
 build a nxn multiplecation table
 need to find the middle element when elements are sorted in increasing order
 n is odd
 */

/*
 3x3 table
 1 2 3
 2 4 6
 3 6 9

 what i noticed that a[i][j] =i*j {when u consider like 1,2,3}
 but array or vector are 0 indexed
 so do a[i][j]=(i+1)*(j+1)

 hence now traverse this array row wise and push it to a vector

 size of the vector is n*n

 return the middle element
 that would be [[(n*n)-1]/2] index position




 */
/*
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

//given a input int n
//build a nxn matrix where each element is a[i][j]=(i+1)*(j+1)

vector<vector<long long>> buildMatrix(long long n) {
  vector<vector<long long>> matrix(n, vector<long long>(n));

  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      matrix[i][j] = (i + 1) * (j + 1);
    }
  }
  return matrix;
}

// now push the matrix to a vector
vector<long long> matrixtoVector(vector<vector<long long>> matrix) {
  vector<long long> arr;
  for (size_t i = 0; i < matrix.size(); i++) {
    for (size_t j = 0; j < matrix[i].size(); j++) {
      arr.push_back(matrix[i][j]);
    }
  }

  // sort the vector
  sort(arr.begin(), arr.end());

  return arr;
}

int main() {
  long long n;
  cin >> n;

  // buildMatrix(n);
  vector<long long> arr = matrixtoVector(buildMatrix(n));
  cout << arr[arr.size() / 2] << endl;

  return 0;
}*/

// not optimal cause building matrix for large n will screw over ram
// so apply binry search
// For a given value x, count how many numbers in multiplication table are ≤ x:
// For each row i: i*1, i*2, i*3, ... i*n
// Count numbers ≤ x: floor(x / i)
// But max per row is n.
// So: count += min(n, x / i)

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;

  long long k = (n * n + 1) / 2;

  long long lo = 1;
  long long hi = n * n;

  while (lo < hi) {
    long long mid = (lo + hi) / 2;

    long long count = 0;

    for (long long i = 1; i <= n; i++) {
      count += min(n, mid / i);
    }

    if (count < k)
      lo = mid + 1;
    else
      hi = mid;
  }

  cout << lo << endl;
}
