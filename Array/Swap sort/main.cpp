//Given an unsorted array of size n. Array elements are in the range from 1 to n. Some numbers from set {1, 2, …n} are missing and some are repeating
//in the array. Find these two numbers in order of one space.

#include <bits/stdc++.h>

using namespace std;

int swap_sort(int arr[], int &n){
    int i=0, res;
    while(i < n){
        if(arr[i] != arr[arr[i]-1])
            swap(arr[i], arr[arr[i]-1]);
        else
            i++;
    }
    for(int i=0; i<n; i++){
        if(arr[i]-1 != i)
            res = i+1;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<swap_sort(arr, n);
    return 0;
}
