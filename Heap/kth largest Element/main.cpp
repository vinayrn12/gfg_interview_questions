/*

    Given an array and a number k where k is smaller than size of array,
    we need to find the k’th largest element in the given array. It is given that all array elements are distinct.

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
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(int i=0; i<n; i++){
        min_heap.push(arr[i]);
        if(min_heap.size() > k)
            min_heap.pop();
    }
    cout<<min_heap.top();
    return 0;
}
