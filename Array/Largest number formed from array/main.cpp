/*
Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.
The result is going to be very large, hence return the result in the form of a string.
*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings

	static bool mycomp(string &s1, string &s2){
	    return s1+s2 > s2+s1;
	}

	string printLargest(vector<string> &arr) {
	    // code here
	    sort(arr.begin(), arr.end(), mycomp);
	    string res {""};
	    for(int i=0; i<arr.size(); i++)
	        res += arr[i];
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
