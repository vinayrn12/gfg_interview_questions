/*

    Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
    For simplicity, assume that all bars have same width and the width is 1 unit.

    For example, consider the following histogram with 7 bars of heights {6, 2, 5, 4, 5, 1, 6}. The largest possible rectangle possible is 12

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

    vector<int> smaller_left(n);
    vector<int> smaller_right(n);
    vector<int> area(n);
    stack<pair<int, int>> s;

    //Smaller left
    for(int i=0; i<n; i++){
        if(s.empty())
            smaller_left[i] = -1;
        else{
            if(s.top().first < arr[i])
                smaller_left[i] = s.top().second;
            else{
                while(!s.empty() && s.top().first >= arr[i])
                    s.pop();
                if(s.empty())
                    smaller_left[i] = -1;
                else
                    smaller_left[i] = s.top().second;
            }
        }
        s.emplace(arr[i], i);
    }

    while(!s.empty())
        s.pop();
    //Smaller Right
    for(int i=n-1; i>-1; i--){
        if(s.empty())
            smaller_right[i] = n;
        else{
            if(s.top().first < arr[i])
                smaller_right[i] = s.top().second;
            else{
                while(!s.empty() && s.top().first >= arr[i])
                    s.pop();
                if(s.empty())
                    smaller_right[i] = n;
                else
                    smaller_right[i] = s.top().second;
            }
        }
        s.emplace(arr[i], i);
    }

    for(int i=0; i<n; i++)
        area[i] = (smaller_right[i] - smaller_left[i] - 1) * arr[i];

    int max_area = INT_MIN;
    for(int i=0; i<n; i++)
        max_area = max(max_area, area[i]);

    cout<<max_area;

    return 0;
}
