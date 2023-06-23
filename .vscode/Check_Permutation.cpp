#include <bits/stdc++.h> 

//BRUTE
// O(3N)
//O(2N)
bool areAnagram(string &str1, string &str2){
    map<char,int> mpp1;
    for(char &it : str1) mpp1[it]++;
    map<char,int> mpp2;
    for(char &it : str2) mpp2[it]++;
    
    if(mpp1.size() != mpp2.size()) return false;
    for(auto it : str1) {
        if(mpp1[it] != mpp2[it]) {
            return false;
        }
    }
    return true;
}


// Sorting
// O(2nlogn)
// O(1)
#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
   sort(str1.begin(),str1.end());
   sort(str2.begin(),str2.end());
   return str1 == str2;
}