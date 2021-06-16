/*
Given a bitonic array find the maximum value of the array. An array is said to be bitonic
if it has an increasing sequence of integers followed immediately by a decreasing sequence of integers.
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


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<(pe(arr, n));
    return 0;
}
