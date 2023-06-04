#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    int cnt1 = 0,cnt2 = 0;
    int el1,el2;
    for(int i = 0; i < n; i++) {
        if(cnt1 == 0 && el2 != arr[i]) {
            cnt1 = 1;
            el1 = arr[i];
        } else if(cnt2 == 0 && el1 != arr[i]) {
            cnt2 = 1;
            el2 = arr[i];
        }
        else if(el1 == arr[i]) cnt1++;
        else if(el2 == arr[i]) cnt2++;
        else {
            cnt1--,cnt2--;
        }
    }
    vector<int> ls;
    cnt1 = 0 , cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == el1) {
            cnt1++;
        } else if(arr[i] == el2) cnt2++;
    }
    int mini = (int)(n / 3) + 1;
    if(cnt1 >= mini) ls.push_back(el1);
    if(cnt2 >= mini) ls.push_back(el2);
    return ls;
}