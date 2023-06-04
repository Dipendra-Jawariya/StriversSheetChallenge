bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m  = mat[0].size();
    //BRUTE O(NXN)
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         if(mat[i][j] == target) {
    //             return true;
    //         }
    //     }
    // }
    // return false;
    
    // Binary Search
    int low = 0;
    int high = n * m -1;
    while(low <= high) {
        int mid = low + (high- low) / 2;
        if(target == mat[mid/m][mid%m]) return true;
        else {
            if(target > mat[mid/m][mid%m]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
    }
    return false;
}