/*
    Given an array of coins and a target. How many coins can we use(minimum) to realize the target
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
    for(int i=0; i<=n; i++)
        tab[i][0] = 0;
    for(int i=0; i<=target; i++)
        tab[0][i] = INT_MAX-1;
    for(int i=1; i<=target; i++){
        if(i%coins[0] == 0)
            tab[1][i] = i/coins[0];
        else
            tab[1][i] = INT_MAX-1;
    }
    for(int i=2; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(coins[i-1] <= j)
                tab[i][j] = min(1 + tab[i][j-coins[i-1]], tab[i-1][j]);
            else
                tab[i][j] = tab[i-1][j];
        }
    }
    cout<<tab[n][target];
    return 0;
}
