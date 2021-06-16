#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    map<int, int> freq;
    for(int i=0; i<n; i++)
        freq[arr[i]]++;
    priority_queue<pi> min_heap;
    for(auto it=freq.begin(); it!=freq.end(); it++)
        min_heap.emplace(it->second, it->first);
    while(!min_heap.empty()){
        int f = min_heap.top().first;
        int ele = min_heap.top().second;
        for(int i=1; i<=f; i++)
            cout<<ele<<" ";
        min_heap.pop();
    }
    cout<<endl;
    return 0;
}
