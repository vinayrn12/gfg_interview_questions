//Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<int> first_negative_in_window;
    queue<int> q;
    int i=0, j=0;

    while(j < n){
        if(arr[j] < 0)
            q.push(arr[j]);
        if(j-i+1 < k){
            j+=1;
            continue;
        }
        else if(j-i+1 == k){
            if(q.empty())
                first_negative_in_window.push_back(0);
            else
                first_negative_in_window.push_back(q.front());
            if(arr[i] < 0)
                q.pop();
            i+=1;
            j+=1;
        }
    }

    for(size_t i=0; i<first_negative_in_window.size(); i++)
        cout<<first_negative_in_window[i]<<" ";
    return 0;
}
