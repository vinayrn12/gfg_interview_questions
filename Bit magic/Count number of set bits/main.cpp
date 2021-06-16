// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        n = n + 1;

        int count = n / 2;

        int powerof2 = 2;

        while(powerof2 <= n){
            int pairs = n / powerof2;

            count += (pairs / 2) * powerof2;

            count += (pairs & 1) ? (n % powerof2) : 0;

            powerof2 <<= 1;
        }

        return count;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends
