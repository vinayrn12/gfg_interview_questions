//Given an array of size N-1 such that it can only contain distinct integers in the range of 1 to N. Find the missing element.

#include bits/stdc++.h>

using namespace std;

int missing(int arr[], int n){
    int expected_sum = (n * (n + 1))/2;
    for(int i=0; i<n-1; i++)
        expected_sum -= arr[i];
    return expected_sum;
}

int main()
{
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0; i<n-1; i++)
        cin>>arr[i];
    cout<<missing(arr, n);
    return 0;
}
