/*

    The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price
    for all n days.
    The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day,
    for which the price of the stock on the current day is less than or equal to its price on the given day.

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> greater_left(n);
    stack<pair<int, int>> s;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=0; i<n; i++){
        if(s.empty())
            greater_left[i] = -1;
        else{
            if(s.top().first > arr[i])
                greater_left[i] = s.top().second;
            else{
                while(!s.empty() && s.top().first <= arr[i])
                    s.pop();
                if(s.empty())
                    greater_left[i] = -1;
                else
                    greater_left[i] = s.top().second;
            }
        }
        s.emplace(arr[i], i);
    }
    for(int i=0; i<n; i++)
        greater_left[i] = i - greater_left[i];
    for(int i=0; i<n; i++)
        cout<<greater_left[i]<<" ";
    return 0;
}
