/*
Given a sorted array, find the element in the array which has minimum difference with the given number.
*/

#include <bits/stdc++.h>

using namespace std;

int bs_floor(int arr[], int n, int k){
    int low=0, high=n-1, pos;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == k){
            pos = mid;
            break;
        }
        else if(arr[mid] < k){
            low = mid+1;
            pos = mid;
        }
        else
            high = mid-1;
    }
    return pos;
}

int bs_ceil(int arr[], int n, int k){
    int low=0, high=n-1, pos;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == k){
            pos = mid;
            break;
        }
        else if(arr[mid] > k){
            high = mid-1;
            pos = mid;
        }
        else
            low = mid+1;
    }
    return pos;
}

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int f = arr[bs_floor(arr, n, k)];
    int c = arr[bs_ceil(arr, n, k)];
    if(abs(f-k) < abs(c-k))
        cout<<f;
    else
        cout<<c;
    return 0;
}
