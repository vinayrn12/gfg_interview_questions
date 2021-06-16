/*

    Given an array of integers, find the closest (not considering distance, but value) smaller on left of every element.
    If an element has no smaller on the left side, print -1.

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> smaller_left(n);
    stack<int> s;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=0; i<n; i++){
        if(s.empty())
            smaller_left[i] = -1;
        else{
            if(s.top() < arr[i])
                smaller_left[i] = s.top();
            else{
                while(!s.empty() && s.top() >= arr[i])
                    s.pop();
                if(s.empty())
                    smaller_left[i] = -1;
                else
                    smaller_left[i] = s.top();
            }
        }
        s.push(arr[i]);
    }
    for(int i=0; i<n; i++)
        cout<<smaller_left[i]<<" ";
    return 0;
}
