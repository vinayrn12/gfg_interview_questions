// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    int m = 0; //count of negative numbers
	    for(int i=0; i<n; i++)
            if(arr[i] < 0)
                m++;
        int neg[m], pos[n-m];
        int j = 0, k =0;
        for(int i=0; i<n; i++){
            if(arr[i] < 0)
                neg[j++] = arr[i];
            else
                pos[k++] = arr[i];
        }
        int i=0;
        j=0, k=0;
        for(; i<n; i++){
            if(i%2 == 0){
                if(k < n-m)
                    arr[i] = pos[k++];
                else
                    arr[i] = neg[j++];
            }
            else{
                if(j < m)
                    arr[i] = neg[j++];
                else
                    arr[i] = pos[k++];
            }
        }

	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
