//Suppose you have a sorted array of infinite numbers, how would you search an element in the array?

#include <bits/stdc++.h>

using namespace std;

int bs(int arr[], int low, int high, int k){
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == k)
            return mid;
        else if(arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
}

int main()
{
    int n, k;//for coding sake we consider n
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    //we don't know the high for an infinite array.
    int low=0, high=1;
    while(k > arr[high]){
        low = high;
        high *= 2;
    }
    cout<<bs(arr, low, high, k);
    return 0;
}
