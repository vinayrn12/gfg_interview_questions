//Given an unsorted array and two numbers x and k, find k closest values to x.

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int main()
{
    int n, x, k;
    cin>>n>>x>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    priority_queue<pi> max_heap;
    for(int i=0; i<n; i++){
        max_heap.emplace(abs(x - arr[i]), arr[i]);
        if(max_heap.size() > k)
            max_heap.pop();
    }
    while(!max_heap.empty()){
        cout<<max_heap.top().second<<" ";
        max_heap.pop();
    }
    cout<<endl;
    return 0;
}
