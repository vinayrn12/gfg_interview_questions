//Given a list of points on the 2-D plane and an integer K. The task is to find K closest points to the origin and print them.

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<double, pi> ppi;

int main()
{
    int n, k;
    cin>>n>>k;
    pi arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i].first>>arr[i].second;
    priority_queue<ppi> max_heap;
    for(int i=0; i<n; i++){
        max_heap.emplace(sqrt(pow(arr[i].first, 2) + pow(arr[i].second, 2)), make_pair(arr[i].first, arr[i].second));
        if(max_heap.size() > k)
            max_heap.pop();
    }
    while(!max_heap.empty()){
        cout<<max_heap.top().second.first<<", "<<max_heap.top().second.second<<" ";
        max_heap.pop();
    }
    return 0;
}
