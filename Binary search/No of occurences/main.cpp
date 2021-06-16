// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searched
    int firstOccurence(int arr[], int N, int K)
    {

       // Your code here
       int low=0, high=N-1, pos = -1;
       while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == K){
                pos = mid+1;
                high = mid-1;
            }
            else if(arr[mid] < K)
                low = mid+1;
            else
                high = mid-1;
       }
       if(pos > 0)
            return pos;
       return -1;

    }

    int lastOccurence(int arr[], int N, int K)
    {

       // Your code here
       int low=0, high=N-1, pos = -1;
       while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == K){
                pos = mid+1;
                low = mid+1;
            }
            else if(arr[mid] < K)
                low = mid+1;
            else
                high = mid-1;
       }
       if(pos > 0)
            return pos;
       return -1;

    }
};

// { Driver Code Starts.


int main(void)
{
    int n, k;
    cin >> n >> k;

    int arr[n];

    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }

    Solution ob;

    cout<<(ob.lastOccurence(arr, n, k) - ob.firstOccurence(arr, n, k) + 1);


	return 0;
}
  // } Driver Code Ends
