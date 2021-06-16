/*
    Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way
    that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
    After performing all the cut operations, your total number of cut segments must be maximum.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {

    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;

        //calling function maximizeTheCuts()
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}// } Driver Code Ends


map<string, int> memo;
int compute(int n, int x, int y, int z){
    string pos = to_string(n) + "," + to_string(x) + "," + to_string(y) + "," + to_string(z);
    //Your code here
    if(n == 0)
        return 0;
    if(n < 0)
        return INT_MIN;
    if(memo.find(pos) != memo.end())
        return memo[pos];

    memo[pos] = max(1 + compute(n-x, x, y, z), max(1 + compute(n-y, x, y, z), 1 + compute(n-z, x, y, z)));

    return memo[pos];
}

//Complete this function
int maximizeTheCuts(int n, int x, int y, int z)
{
    int res = compute(n, x, y, z);
    if(res < 0)
        return 0;
    return res;
}
