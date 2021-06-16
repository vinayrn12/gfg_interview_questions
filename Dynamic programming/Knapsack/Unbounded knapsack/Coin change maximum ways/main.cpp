/*
    Given an array of coins and a target sum. In how many ways can that sum be realized using the coins given in arr.(Multiple coins can be used)
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0; i<n; i++)
        cin>>coins[i];
    int target;
    cin>>target;
    vector<vector<int>> tab(n+1, vector<int>(target+1));
    for(int i=0; i<=target; i++)
        tab[0][target] = 0;
    for(int i=0; i<=n; i++)
        tab[i][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(coins[i-1] <= j)
                tab[i][j] = tab[i-1][j] + tab[i][j-coins[i-1]];
            else
                tab[i][j] = tab[i-1][j];
        }
    }
    cout<<tab[n][target];
    return 0;
}
