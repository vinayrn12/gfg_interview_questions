// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void add_one(vector<int> &arr, int &carry, int n){
        if(arr[n] < 9){
            arr[n] += 1;
            carry = 0;
            return;
        }
        arr[n] = 0;
        carry = 1;
    }

    vector<int> increment(vector<int> arr ,int N) {
        // code here
        int carry = 0;
        for(int i=N-1; i>=0; i--){
            add_one(arr, carry, i);
            if(carry == 0)
                break;
        }
        if(arr[0] == 0 && carry == 1)
            arr.insert(arr.begin(), 1);
        return arr;
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;

        cin>>N;
        vector<int> arr(N);

        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
