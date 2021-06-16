/*
    Given an arr[] = [10, 20, 30, 10] say.
    Three matrices of size 10*20, 20*20, 30*10 are present from the given array.
    Return minimum cost of multiplication(Theoretically by placing braces).
    cost of multiplication = a * b * c for two matrices of size a*b and b*c
*/

#include <bits/stdc++.h>

using namespace std;

map<string, int> memo;

int mcm(vector<int> &arr, int i, int j){
    string pos = to_string(i) + "," + to_string(j);
    if(memo.find(pos) != memo.end())
        return memo[pos];
    if(i >= j)
        return 0;
    int minimum = INT_MAX;
    for(int k=i; k<j; k++){
        int temp = mcm(arr, i, k) + mcm(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
        minimum = min(minimum, temp);
    }
    memo[pos] = minimum;
    return memo[pos];
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<mcm(arr, 1, n-1);
    return 0;
}
