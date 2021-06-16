//Given an array containing N positive integers and an integer K.
//Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.


#include <bits/stdc++.h>

using namespace std;

int positive_array(int arr[], int &n, int &k){
    int i=0, j=0, max_subarray=0, sum=0;
    while(j < n){
        sum += arr[j];
        if(sum < k)
            j++;
        else if(sum == k){
            max_subarray = max(max_subarray, j-i+1);
            j++;
        }
        else{
            while(sum > k){
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }
    return max_subarray;
}

int negative_array(int arr[], int &n, int &k){
    int sum=0, max_subarray=0;
    map<int, int> m;//maps sum to index
    for(int i=0; i<n; i++){
        sum += arr[i];

        if(sum == k)
            max_subarray = i+1;

        if(m.find(sum) == m.end())
            m[sum] = i;

        if(m.find(sum-k) != m.end())
            max_subarray = max(max_subarray, i-m[sum-k]);
    }
    return max_subarray;
}

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<positive_array(arr, n, k)<<endl;
    cout<<negative_array(arr, n, k);
    return 0;
}
