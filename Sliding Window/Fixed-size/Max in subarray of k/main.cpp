//Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<int> max_subarray;
    list<int> q;
    int i=0, j=0;
    if(k > n){
        cout<<(*max_element(arr.begin(), arr.end()));
        exit(0);
    }
    while(j < n){
        while(!q.empty() && q.back() < arr[j])
            q.pop_back();
        q.push_back(arr[j]);

        if(j-i+1 < k)
            j++;
        else if(j-i+1 == k){
            max_subarray.push_back(q.front());

            if(arr[i] == q.front())
                q.pop_front();
            i++;
            j++;
        }
    }
    for(size_t i=0; i<max_subarray.size(); i++)
        cout<<max_subarray[i]<<" ";
    return 0;
}
