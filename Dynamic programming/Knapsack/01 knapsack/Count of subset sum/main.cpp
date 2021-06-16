/*
    Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int sum;
    cin>>sum;
    vector<vector<int>> tab(n+1, vector<int>(sum+1));
    for(int j=0; j<=sum; j++)
        tab[0][j] = 0;
    for(int i=0; i<=n; i++)
        tab[i][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j)
                tab[i][j] = tab[i-1][j - arr[i-1]] + tab[i-1][j];
            else
                tab[i][j] = tab[i-1][j];
        }
    }
    cout<<tab[n][sum];
    return 0;
}
