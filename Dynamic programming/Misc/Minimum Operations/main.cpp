// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        if(n == 0)
            return 0;
        int min_ways = 0;
        if(n % 2 == 0)
            min_ways += minOperation(n / 2) + 1;
        else
            min_ways += minOperation(n - 1) + 1;
        return min_ways;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends
