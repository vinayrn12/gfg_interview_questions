/*
Given an infinite sorted array consisting 0s and 1s. The problem is to find the index of first ‘1’ in that array.
As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.
*/

#include <bits/stdc++.h>

using namespace std;

int bs(int arr[], int low, int high){
    int pos;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == 1){
            pos = mid;
            high = mid - 1;
        }
        else if(arr[mid] < 1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return pos;
}

int main()
{
    int n; //for the purpose of coding take n as finite
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int low=0, high=1;
    while(arr[high] != 1){
        low = high;
        high *= 2;
    }
    cout<<(bs(arr, low, high));
    return 0;
}
