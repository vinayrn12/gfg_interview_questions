/*

    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

        Input: arr[]   = {2, 0, 2}
        Output: 2
         _   _
        | | | |
        |_|_|_|

        Input: arr[]   = {3, 0, 2, 0, 4}
        Output: 7

                 _
         _      | |
        | |  _  | |
        | | | | | |
        |_|_|_|_|_|
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> buildings(n);
    for(int i=0; i<n; i++)
        cin>>buildings[i];

    vector<int> max_left(n);
    vector<int> max_right(n);

    max_left[0] = buildings[0];
    for(int i=1; i<n; i++)
        max_left[i] = max(buildings[i], max_left[i-1]);

    max_right[n-1] = buildings[n-1];
    for(int i=n-2; i>-1; i--)
        max_right[i] = max(buildings[i], max_right[i+1]);

    vector<int> water_trapped(n);
    for(int i=0; i<n; i++)
        water_trapped[i] = min(max_left[i], max_right[i]) - buildings[i];

    int water = 0;
    for(int i=0; i<n; i++)
        water += water_trapped[i];
    cout<<water;

    return 0;
}
