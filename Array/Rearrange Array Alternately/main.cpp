/*
Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively
i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.
*/

#include <bits/stdc++.h>

using namespace std;

void arrange(int arr[], int &n){
    int min_index=0, max_index=n-1;
    int maximum_element = arr[max_index] + 1;

    for(int i=0; i<n; i++){
        if(i%2){//odd indices hold minimum elements
            arr[i] += (arr[min_index]%maximum_element)*maximum_element;
            min_index++;
        }
        else{
            arr[i] += (arr[max_index]%maximum_element)*maximum_element;
            max_index--;
        }
    }
    for(int i=0; i<n; i++)
        arr[i] /= maximum_element;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    arrange(arr, n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
