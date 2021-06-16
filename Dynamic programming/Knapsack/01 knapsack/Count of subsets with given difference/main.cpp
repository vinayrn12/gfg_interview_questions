/*
    Given an array and a difference. Return number of different subsets that satisfy this diff.


    This question can also be framed as follows:
        Given an array and an output. You have a choice to assign either a +/- to each input
    in the array. After assignment the operations should yield the output.
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int diff, sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    cin>>diff;
    int subset1 = (diff + sum)/2;
    sum = subset1;
    vector<vector<int>> tab(n+1, vector<int>(sum+1));
    for(int i=0; i<=sum; i++)
        tab[0][i] = 0;
    for(int i=0; i<=n; i++)
        tab[i][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i - 1] <= j)
                tab[i][j] = tab[i-1][j-arr[i-1]] + tab[i-1][j];
            else
                tab[i][j] = tab[i-1][j];
        }
    }
    cout<<tab[n][sum];
    return 0;
}
