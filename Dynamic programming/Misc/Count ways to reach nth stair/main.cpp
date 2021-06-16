/*

    There are N stairs, a person standing at the bottom wants to reach the top.
    The person can climb either 1 stair or 2 stairs at a time.
    Count the number of ways, the person can reach the top (order does matter).

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int countWays(int);

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;

        cout<<countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends


// function to count ways to reach mth stair

map<int, int> memo;

int countWays(int m){
    // your code here
    if(memo.find(m) != memo.end())
        return memo[m];
    if(m == 0)
        return memo[m] = 1;
    if(m < 0)
        return memo[m] = 0;
    return memo[m] = (countWays(m-1) + countWays(m-2))%1000000007;
}
