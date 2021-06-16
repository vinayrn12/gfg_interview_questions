#include <bits/stdc++.h>

using namespace std;

void insert(vector<int> &arr, int &ele){
    if(arr.empty() || arr[arr.size() - 1] <= ele){
        arr.push_back(ele);
        return;
    }
    int temp = arr[arr.size() - 1];
    arr.pop_back();
    insert(arr, ele);
    arr.push_back(temp);
}

void Sort(vector<int> &arr){
    if(arr.size() == 1)
        return;
    int v = arr[arr.size() - 1];
    arr.pop_back();
    Sort(arr);
    insert(arr, v);
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    Sort(arr);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
