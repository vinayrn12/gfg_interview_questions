/*

    Given an array of n numbers. Your task is to read numbers from the array and keep at-most K numbers at the top
    (According to their decreasing frequency) every time a new number is read.
    We basically need to print top k numbers sorted by frequency when input stream has included k distinct elements,
    else need to print all distinct elements sorted by frequency.

*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    map<int, int> freq;
    for(int i=0; i<n; i++)
        freq[arr[i]]++;
    priority_queue<pi, vector<pi>, greater<pi>> min_heap;
    for(auto it=freq.begin(); it!=freq.end(); it++){
        min_heap.emplace(it->second, it->first);
        if(min_heap.size() > k)
            min_heap.pop();
    }
    while(!min_heap.empty()){
        cout<<min_heap.top().second<<" ";
        min_heap.pop();
    }
    cout<<endl;
    return 0;
}
