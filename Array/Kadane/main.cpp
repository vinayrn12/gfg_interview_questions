//Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers that has the largest sum.

#include <bits/stdc++.h>

using namespace std;

int max_subarray_sum(int arr[], int n){
    int max_so_far = INT_MIN, max_ending_here = 0;
    for(int i=0; i<n; i++){
        max_ending_here += arr[i];
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if(max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<max_subarray_sum(arr, n);
    return 0;
}
