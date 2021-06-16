//Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(int i=0; i<n; i++){
        min_heap.push(arr[i]);
        if(min_heap.size() > k){
            cout<<min_heap.top()<<" ";
            min_heap.pop();
        }
    }
    while(!min_heap.empty()){
        cout<<min_heap.top()<<" ";
        min_heap.pop();
    }
    cout<<endl;
    return 0;
}
