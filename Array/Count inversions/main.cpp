// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long _merge(long long arr[], long long low, long long mid, long long high, long long temp[]){


        long long i=low;
        long long j=mid+1;
        long long k=low;
        long long inv=0;

        while(i <= mid && j <= high){
            if(arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else{
                temp[k++] = arr[j++];
                inv += (mid-i+1);
            }
        }

        while(i <= mid)
            temp[k++] = arr[i++];

        while(j <= high)
            temp[k++] = arr[j++];

        for(long long i=low; i<=high; i++)
            arr[i] = temp[i];

        return inv;
    }

    long long mergesort(long long arr[], long long low, long long high, long long temp[]){
        if(low >= high)
            return 0;

        long long mid = low + (high - low)/2;
        long long inversions = 0;
        inversions += mergesort(arr, low, mid, temp);
        inversions += mergesort(arr, mid+1, high, temp);
        inversions += _merge(arr, low, mid, high, temp);
        return inversions;
    }

    long long inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        return mergesort(arr, 0, N-1, temp);
    }

};

// { Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while(T--){
        long long N;
        cin >> N;

        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }

    return 0;
}
  // } Driver Code Ends
