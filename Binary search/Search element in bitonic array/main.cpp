/*
Given a bitonic sequence of n distinct elements, write a program to find a given element x in the bitonic sequence in O(log n) time.
A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.
*/

#include <bits/stdc++.h>

using namespace std;

int pe(int arr[], int n){
    int low = 0, high = n-1, pos;

    if(n < 2)
        return 0;
    if(arr[0] > arr[1])
        return 0;
    if(arr[n-1] > arr[n-2])
        return n-1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(mid > 0 && mid < n-1){
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                pos = mid;
                break;
            }
            else if(arr[mid] < arr[mid+1])
                low = mid;
            else
                high = mid;
        }
    }
    return pos;
}

int bs(int arr[], int low, int high, int k){
    int pos=-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == k){
            pos = mid;
            break;
        }
        else if(arr[mid] < k)
            low = mid+1;
        else
            high = mid-1;
    }
    return pos;
}

int bs_reverse(int arr[], int low, int high, int k){
    int pos=-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == k){
            pos = mid;
            break;
        }
        else if(arr[mid] > k)
            low = mid+1;
        else
            high = mid-1;
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
    int max_index = pe(arr, n);
    int res1 = bs(arr, 0, max_index, k);
    int res2 = bs_reverse(arr, max_index+1, n-1, k);
    if(res1==-1 && res2==-1)
        cout<<-1;
    else if(res1==-1)
        cout<<res2;
    else
        cout<<res1;
    return 0;
}
