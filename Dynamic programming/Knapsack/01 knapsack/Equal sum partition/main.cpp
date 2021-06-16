//Given an array. Return if it can be divided into two subsets of equal sum

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    bool is_possible;
    if(sum%2)
        is_possible = false;
    else{
        sum /= 2;
        vector<vector<bool>> tab(n+1, vector<bool>(sum+1));
        for(int j=0; j<=sum; j++)
            tab[0][j] = false;
        for(int i=0; i<=n; i++)
            tab[i][0] = true;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(arr[i-1] <= j)
                    tab[i][j] = tab[i-1][j - arr[i-1]] || tab[i-1][j];
                else
                    tab[i][j] = tab[i-1][j];
            }
        }
        is_possible = tab[n][sum];
    }
    cout<<is_possible;
    return 0;
}
