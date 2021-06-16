/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searched
    int searchInSorted(int arr[], int N)
    {

       // Your code here
       if(N == 1)
            return 0;
       int low=0, high=N-1;
       while(low <= high){
            int mid = (low+high)/2;
            int next = (mid+1)%N;
            int prev = (mid-1+N)%N;
            if(arr[mid] < arr[prev] && arr[mid] < arr[next]) //minimum element
                return mid;
            else if(arr[mid] < arr[high]) //right sorted, element is in left array
                high = mid-1;
            else//left sorted, element is in right array
                low = mid+1;
       }
    }

    int bs(int arr[], int low, int high, int K)
    {

       // Your code here
       while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == K)
                return mid;
            else if(arr[mid] < K)
                low = mid+1;
            else
                high = mid-1;
       }
       return -1;

    }
};

// { Driver Code Starts.


int main(void)
{
    int n, k;
    cin >> n >> k ;

    int arr[n];

    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }

    Solution ob;
    int min_index = ob.searchInSorted(arr, n);
    //The array is sorted from beg to mid_index and mid_index to end
    if(k >= arr[min_index] && k <= arr[n-1])
        cout<<ob.bs(arr, min_index, n-1, k);
    else
        cout<<ob.bs(arr, 0, min_index-1, k);

	return 0;
}
