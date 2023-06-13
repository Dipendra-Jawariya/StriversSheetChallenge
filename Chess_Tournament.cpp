#include <bits/stdc++.h>
bool ispossible(vector<int> positions , int n ,  int c, int mid){
    int players = 1;
    int roomcnt = positions[0];
    for(int i =0;i<positions.size();i++){
          if (positions[i] - roomcnt >= mid) {
            players++;
            if (players == c) {
              return true;
            }
            roomcnt = positions[i];
          }
        }
        return false;
}
int chessTournament(vector<int> positions, int n, int c) {
  if (positions.size() < c)
    return -1;
  sort(positions.begin(), positions.end());
  int s = 1;
  int maxi = -1;
  for (int i = 0; i < positions.size(); i++) {
    maxi = max(maxi, positions[i]);
  }
  int e = maxi;
  int ans = -1;
  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (ispossible(positions, n, c, mid)) {
      ans = mid;
      s = mid + 1;
    }
    else {
      e = mid - 1;
    }
  }
  return ans;
}