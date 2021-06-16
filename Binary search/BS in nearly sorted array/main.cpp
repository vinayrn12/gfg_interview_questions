/*
Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions, i.e., arr[i] may be present at arr[i+1]
or arr[i-1]. Write an efficient function to search an element in this array. Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].
*/

#include <bits/stdc++.h>

using namespace std;

int bs(int arr[], int n, int k){
    int low=0, high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == k)
            return mid;
        else if(mid-1 >= low && arr[mid-1] == k)
            return mid-1;
        else if(mid+1 <= high && arr[mid+1] == k)
            return mid+1;
        else if(k < arr[mid])
            high = mid-2;
        else
            low = mid+2;
    }
}

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<bs(arr, n, k);
    return 0;
}
