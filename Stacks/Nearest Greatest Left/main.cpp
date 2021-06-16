/*

    Given an array, print the Greatest Element to the left (NGE) for every element.
    The left greater Element for an element x is the first greater element on the left side of x in the array.
    Elements for which no greater element exist, consider left greater element as -1.

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
    vector<int> next_greater(n);
    stack<int> s;
    for(int i=0; i<n; i++){
        if(s.empty())
            next_greater[i] = -1;
        else{
            if(s.top() > arr[i])
                next_greater[i] = s.top();
            else{
                while(!s.empty() && s.top() <= arr[i])
                    s.pop();
                if(s.empty())
                    next_greater[i] = -1;
                else
                    next_greater[i] = s.top();
            }
        }
        s.push(arr[i]);
    }
    for(int i=0; i<n; i++)
        cout<<next_greater[i]<<" ";
    return 0;
}
