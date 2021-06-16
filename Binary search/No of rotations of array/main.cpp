// Find the Rotation Count in Rotated Sorted array
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
};

// { Driver Code Starts.


int main(void)
{
    int n;
    cin >> n ;

    int arr[n];

    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }

    Solution ob;
    cout << ob.searchInSorted(arr, n) << endl;

	return 0;
}
  // } Driver Code Ends
