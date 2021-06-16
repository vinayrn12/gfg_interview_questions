// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    void solve(int index, int k, int &ans, vector<int> &v){
        if(v.size() == 1){
            ans = v[0];
            return;
        }
        index = (index+k)%v.size();
        v.erase(v.begin() + index);
        solve(index, k, ans, v);
    }

    int safePos(int n, int k) {
        // code here
        int ans;
        vector<int> v(n);
        for(int i=0; i<n; i++)
            v[i] = i;
        solve(0, k-1, ans, v);
        return ans+1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;

        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}  // } Driver Code Ends
