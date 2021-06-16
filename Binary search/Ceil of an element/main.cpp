//Given a sorted array and a value x, the ceil of x is the smallest element in array greater than or equal to x.

#include <bits/stdc++.h>

using namespace std;

int bs(int arr[], int n, int k){
    int low=0, high=n-1, pos=-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(k == arr[mid]){
            pos = mid;
            break;
        }
        else if(k < arr[mid]){
            high = mid - 1;
            pos = mid;
        }
        else
            low = mid + 1;
    }
    if(pos < 0)
        return -1;
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
