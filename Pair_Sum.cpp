#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
    //Brute
  vector <vector<int>> ans;
   sort(arr.begin(),arr.end());
   for(int i=0;i<arr.size()-1;i++){
      for(int j=i+1;j<arr.size();j++){
         if((arr[i]+arr[j]) == s){
            vector<int> temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            ans.push_back(temp);
         }
      }
   }
   return ans;
}


/*

    Time Complexity: O(N^2)
    Space COmplexity: O(N)

    Where 'N' is the size of the array.
    
*/

// #include <map>

// vector<vector<int>> pairSum(vector<int> &arr, int s){
//     int n = arr.size();

//     map<int, int> hash;
//     vector<vector<int>> ans;

//     for (int ele : arr)
//     {
//         int count = hash[s - ele];

//         vector<int> pair(2);
//         pair[0] = ele;
//         pair[1] = s - ele;

//         while (count--)
//         {
//             ans.push_back(pair);
//         }

//         hash[ele] += 1;
//     }

//     vector<vector<int>> res(ans.size(), vector<int>(2, 0));

//     for (int i = 0; i < ans.size(); i++)
//     {
//         int a = ans[i][0], b = ans[i][1];
//         res[i][0] = min(a, b);
//         res[i][1] = max(a, b);
//     }

//     sort(res.begin(), res.end());
//     return res;
// }