// #include <bits/stdc++.h> 
// struct meeting {
//     int start;
//     int end;
//     int pos;
// };
// bool comparator(struct meeting m1,meeting m2) {
//     if(m1.end < m2.end) return true;
//     else if(m1.end > m2.end) return false;
//     else if(m1.pos < m2.pos) return true;
//     return false;
// }
// vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
//     int n = start.size();
//     struct meeting meet[n];
//     for(int i = 0; i < n; i++) {
//         meet[i].start = start[i];
//         meet[i].end = end[i];
//         meet[i].pos = i+1; // one based indexing
//     }
//     sort(meet,meet+n,comparator);

//     vector<int> answer;
//     int limit = meet[0].end;
//     answer.push_back(meet[0].pos);

//     for(int i = 1; i < n; i++) {
//         if(meet[i].start > limit) {
//             limit = meet[i].end;
//             answer.push_back(meet[i].pos);
//         }
//     }
//     return answer;
// }

#include <bits/stdc++.h> 

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<int>ans;
    vector<vector<int>>v(start.size());
    for(int i=0;i<v.size();i++) {
        v[i]={end[i],i+1,start[i]};
    }
    sort(v.begin(),v.end());
    int finish=v[0][0];
    ans.push_back(v[0][1]);
    for(int i=1;i<v.size();i++) {
        if(v[i][2]>finish) {
            finish=v[i][0];
            ans.push_back(v[i][1]);
        }
    }
    return ans;
}