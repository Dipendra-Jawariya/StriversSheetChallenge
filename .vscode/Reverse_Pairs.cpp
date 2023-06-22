#include <bits/stdc++.h> 
int merge(vector<int>& arr,int low,int mid,int high){
	int count=0,cnt=0,temp[high-low+1];
	int i=low,j=mid+1;
	while(i<=mid && j<=high){
		if(arr[i]>2ll*arr[j]){
			count+=(mid-i+1);		
			j++;
		}
		else{		
			i++;
			
		}
	}
	i=low,j=mid+1;
	while(i<=mid && j<=high){
		if(arr[i]<arr[j]) temp[cnt++]=arr[i++];
		else temp[cnt++]=arr[j++];
	}
	
	while(i<=mid){
		temp[cnt++]=arr[i++];
	}
	while(j<=high){
		temp[cnt++]=arr[j++];
	}
	cnt=0;
	for(int k=low;k<=high;k++){
		arr[k]=temp[cnt++];
	}
	return count;
}
int mergesort(vector<int>& arr,int low,int high){
	int count=0;
	if(low<high){
		int mid=low+(high-low)/2;
		count+=mergesort(arr,low,mid);
		count+=mergesort(arr,mid+1,high);
		count+=merge(arr,low,mid,high);
	}
	return count;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	return mergesort(arr,0,n-1);	
}





#include <bits/stdc++.h>

int merge(vector<int> &arr, int low, int mid, int high) {

  int reverse_pair = 0, i, j;

  for (i = low, j = mid + 1; i <= mid; i++) {

    while (j <= high && arr[i] > 2 * (long long)arr[j])

      j++;

    reverse_pair += (j - mid - 1);
  }

  int temp[high - low + 1], k = 0;

  i = low, j = mid + 1;

  while (i <= mid || j <= high) {

    if (i > mid)

      temp[k++] = arr[j++];

    else if (j > high)

      temp[k++] = arr[i++];

    else if (arr[i] <= arr[j])

      temp[k++] = arr[i++];

    else

      temp[k++] = arr[j++];
  }

  for (i = low; i <= high; i++)

    arr[i] = temp[i - low];

  return reverse_pair;
}

int mergeSort(vector<int> &arr, int low, int high) {

  int reverse_pair = 0;

  if (low < high) {
    int mid = (low + high) / 2;
    reverse_pair += mergeSort(arr, low, mid);
    reverse_pair += mergeSort(arr, mid + 1, high);
    reverse_pair += merge(arr, low, mid, high);
  }
  return reverse_pair;
}
int reversePairs(vector<int> &arr, int n) { return mergeSort(arr, 0, n - 1); }
