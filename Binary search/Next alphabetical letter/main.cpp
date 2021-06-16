//Given an array of letters sorted in ascending order, find the smallest letter in the the array which is greater than a given key letter.

#include <bits/stdc++.h>

using namespace std;

int bs(char arr[], int n, int k){
    int low=0, high=n-1, pos=-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(k < arr[mid]){
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
    int n;
    char k;
    cin>>n>>k;
    char arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int res = bs(arr, n, k);
    if(res > 0)
        cout<<arr[res];
    else
        cout<<"-1";
    return 0;
}
