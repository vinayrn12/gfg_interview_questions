/*

    Given an array and a number k where k is smaller than size of array,
    we need to find the k’th smallest element in the given array. It is given that all array elements are distinct.

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    priority_queue<int> max_heap;
    for(int i=0; i<n; i++){
        max_heap.push(arr[i]);
        if(max_heap.size() > k)
            max_heap.pop();
    }
    cout<<max_heap.top();
    return 0;
}
