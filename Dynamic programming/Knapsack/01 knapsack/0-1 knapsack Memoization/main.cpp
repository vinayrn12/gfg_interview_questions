#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tab;

int knapsack(vector<int> &weights, vector<int> &value, int capacity, int n){
    if(n==0 || capacity==0)
        return 0;
    if(tab[capacity][n] != -1)
        return tab[capacity][n];
    if(weights[n-1] <= capacity)
        tab[capacity][n] = max(value[n-1] + knapsack(weights, value, capacity - weights[n-1], n-1), knapsack(weights, value, capacity, n-1));
    else
        tab[capacity][n] = knapsack(weights, value, capacity, n-1);
    return tab[capacity][n];
}

int main()
{
    int n;
    cin>>n;
    vector<int> weights(n);
    vector<int> value(n);
    for(int i=0; i<n; i++)
        cin>>weights[i];
    for(int i=0; i<n; i++)
        cin>>value[i];
    int capacity;
    cin>>capacity;
    tab.resize(capacity+1, vector<int>(n+1));
    for(int i=0; i<=capacity; i++)
        for(int j=0; j<=n; j++)
            tab[i][j] = -1;
    cout<<knapsack(weights, value, capacity, n);
    return 0;
}
