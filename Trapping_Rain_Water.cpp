#include <bits/stdc++.h>
long getTrappedWater(long *arr, int n) {
  long left = 0, right = n - 1;
  long res = 0;
  long maxLeft = 0, maxRight = 0;
  while (left <= right) {

    if (arr[left] <= arr[right]) {
      if (arr[left] >= maxLeft) {
        maxLeft = arr[left];
      } else {
        res += maxLeft - arr[left];
      }
      left++;
    } else {
      if (arr[right] >= maxRight)
        maxRight = arr[right];
      else
        res += maxRight - arr[right];
      right--;
    }
  }
  return res;
} 