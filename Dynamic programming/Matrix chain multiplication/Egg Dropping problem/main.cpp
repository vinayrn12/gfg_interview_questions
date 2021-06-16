/*
You are given N floor and K eggs. You have to minimize the number of times you have to drop the eggs to find
the critical floor where critical floor means the floor beyond which eggs start to break. Assumptions of the problem:
    If egg breaks at ith floor then it also breaks at all greater floors.
    If egg does not break at ith floor then it does not break at all lower floors.
    Unbroken egg can be used again.
    Note: You have to find minimum trials required to find the critical floor not the critical floor.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tab;

int solve(int eggs, int floors){
    if(eggs == 1)
        return tab[eggs][floors] = floors;
    if(floors <= 1)
        return tab[eggs][floors] = floors;
    if(tab[eggs][floors] != -1)
        return tab[eggs][floors];

    int min_ways = INT_MAX;
    for(int k=1; k<=floors; k++){
        int low, high;

        if(tab[eggs-1][k-1] != -1)
            low = tab[eggs-1][k-1];
        else
            low = solve(eggs-1, k-1);
        if(tab[eggs][floors-k] != -1)
            high = tab[eggs][floors-k];
        else
            high = solve(eggs, floors-k);

        int temp = 1 + max(low, high);
        min_ways = min(temp, min_ways);
    }
    return tab[eggs][floors] = min_ways;
}

int main()
{
    int eggs, floors;
    cin>>eggs>>floors;
    tab.resize(eggs+1, vector<int>(floors+1, -1));
    cout<<solve(eggs, floors);
    return 0;
}
