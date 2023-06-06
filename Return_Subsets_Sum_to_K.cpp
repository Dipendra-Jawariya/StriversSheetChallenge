 void f(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
      if (ind == arr.size()) {
        if (target == 0) {
          ans.push_back(ds);
        }
        return;
      }
    //   if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        f(ind+1, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    //   }

      f(ind + 1, target, arr, ans, ds);
    }
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    f(0, k, arr, ans, ds);
    return ans;
}