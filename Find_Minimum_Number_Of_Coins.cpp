#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    vector<int> coins= {1,2,5,10,20,50,100,500,1000};
    int n = 9;
    int min_coins = 0;
    for(int i = n-1; i >= 0; i--) {
        while(amount >= coins[i]) {
            amount -= coins[i];
            min_coins++;
        } 
    }
    return min_coins;
}
