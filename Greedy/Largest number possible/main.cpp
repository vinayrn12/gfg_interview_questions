// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        string num{""};
        if(N == 1 && S == 0)
            return "0";
        if(N > 1 && S == 0)
            return "-1";
        while(N--){
            if(S >= 9){
                num += "9";
                S -= 9;
            }
            else if(S == 0)
                num += "0";
            else{
                num += to_string(S);
                S -= S;
            }
        }
        if(S > 0)
            return "-1";
        return num;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;

        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
