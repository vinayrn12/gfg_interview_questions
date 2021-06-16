/*
Given an unsorted array of size N.
Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int findElement(int arr[], int n) {
    int rightmin[n], leftmax[n];
    leftmax[0] = INT_MIN;
    rightmin[n-1] = INT_MAX;
    for(int i=1; i<n; i++)
        leftmax[i] = max(leftmax[i-1], arr[i-1]);
    for(int i=n-2; i>=0; i--)
        rightmin[i] = min(rightmin[i+1], arr[i+1]);
    for(int i=1; i<n-1; i++)
        if(arr[i] >= leftmax[i] && arr[i] <= rightmin[i])
            return arr[i];
    return -1;
}
