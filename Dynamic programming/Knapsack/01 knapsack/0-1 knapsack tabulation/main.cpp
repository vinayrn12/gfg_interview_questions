#include <bits/stdc++.h>

using namespace std;

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
    vector<vector<int>> tab(n+1, vector<int>(capacity+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=capacity; j++){
            if(weights[i-1] <= j)
                tab[i][j] = max(value[i-1] + tab[i-1][j - weights[i-1]], tab[i-1][j]);
            else
                tab[i][j] = tab[i-1][j];
        }
    }
    cout<<tab[n][capacity];
    return 0;
}
