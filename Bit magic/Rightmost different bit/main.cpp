//Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers.

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int rightmostsetbit(int n){
        return log2(n & -n) + 1;
    }

    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        return rightmostsetbit(m ^ n);
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;
}   // } Driver Code Ends
