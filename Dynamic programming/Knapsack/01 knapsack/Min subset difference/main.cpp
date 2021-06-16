/*
    Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
    If there is a set S with n elements,
    then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.
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
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
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
    vector<int> subset1;
    for(int j=0; j<=(sum/2); j++){
        if(tab[n][j])
            subset1.push_back(j);
    }
    int minimum = INT_MAX;
    for(unsigned int i=0; i<subset1.size(); i++)
        minimum = min(minimum, sum - 2 * subset1[i]);
    cout<<minimum;
    return 0;
}
