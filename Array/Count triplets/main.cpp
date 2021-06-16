//Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

#include <bits/stdc++.h>

using namespace std;

int count_triplets(int arr[], int &n){
    sort(arr, arr+n);
    int triplets = 0;
    for(int i=n-1; i>0; i--){
        int j=0, k=i-1;
        while(j < k){
            if(arr[j]+arr[k] < arr[i])
                j++;
            else if(arr[j]+arr[k] > arr[i])
                k--;
            else{
                triplets++;
                j++;
                k--;
            }
        }
    }
    return triplets;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<count_triplets(arr, n);
    return 0;
}
