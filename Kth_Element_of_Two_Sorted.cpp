// int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
//   vector<int> v;
//   for (int i = 0; i < row1.size(); i++) {
//     v.push_back(row1[i]);
//   }
//   for (int i = 0; i < row2.size(); i++) {
//     v.push_back(row2[i]);
//   }
//   sort(v.begin(), v.end());
//   return v[k - 1];
// }


//OPTIMAL APPROACH
#include <bits/stdc++.h>
int ninjaAndLadoos(vector<int> &arr1, vector<int> &arr2, int n, int m, int k) {
  if (m < n) {
    return ninjaAndLadoos(arr2, arr1, m, n, k);
  }

  int low = max(0, k - m);
  int high = min(k, n);

  while (low <= high) {
    int p1 = (low + high) / 2;
    int p2 = k - p1;

    int l1 = p1 == 0 ? INT_MIN : arr1[p1 - 1];
    int l2 = p2 == 0 ? INT_MIN : arr2[p2 - 1];
    int r1 = p1 == n ? INT_MAX : arr1[p1];
    int r2 = p2 == m ? INT_MAX : arr2[p2];

    if (l1 <= r2 && l2 <= r1) {
      return max(l1, l2);
    } else if (l1 > r2) {
      high = p1 - 1;
    } else {
      low = p1 + 1;
    }
  }
  return 1;
} 