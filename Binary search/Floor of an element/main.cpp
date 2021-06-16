//Given a sorted array and a value x, the floor of x is the largest element in array smaller than or equal to x.

#include <bits/stdc++.h>

using namespace std;

int bs(int arr[], int n, int k){
    int low=0, high=n-1, pos=-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(k == arr[mid])
            pos = mid;
        else if(k < arr[mid])
            high = mid - 1;
        else{
            pos = mid;
            low = mid + 1;
        }
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
    cout<<arr[bs(arr, n, k)];
    return 0;
}
