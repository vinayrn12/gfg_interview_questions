/*
    Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
    Determine the maximum value obtainable by cutting up the rod and selling the pieces.

    Similar to unbounded knapsack in everything.
        Rod problem             Unbounded knapsack

        * len array             * weights array
        * price array           * values array
        * maximize profit       * maximize val in knapsack
        * Total length of rod   * Capacity of knapsack
*/


#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> weights(n);
    vector<int> values(n);
    for(int i=0; i<n; i++)
        cin>>weights[i];
    for(int i=0; i<n; i++)
        cin>>values[i];
    int capacity = n;
    vector<vector<int>> tab(n+1, vector<int>(capacity+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=capacity; j++){
            if(weights[i-1] <= j)
                tab[i][j] = max(tab[i-1][j], values[i-1] + tab[i][j-weights[i-1]]);
            else
                tab[i][j] = tab[i-1][j];
        }
    }
    cout<<tab[n][capacity];
    return 0;
}
