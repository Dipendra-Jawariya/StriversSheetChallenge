#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int low , mid = 0;
   int high = n-1;
   for(int i = 0; i < n; i++) {
      if(arr[mid] == 0 )  {
         swap(arr[low],arr[mid]);
         mid++;
         low++;
      }
      else if(arr[mid] == 1) {
         mid++;
      }
      else {
         swap(arr[high],arr[mid]);
         high--;
      }
   }
}