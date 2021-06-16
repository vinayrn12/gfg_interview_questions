/*
The cost of stock on each day is given in an array A[] of size N.
Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
*/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        vector<vector<int>> res;
        int buy, sell, i=0;
        while(i < n-1){
            while((i < n-1) && (A[i+1] <= A[i]))
                i++;
            if(i == n-1)
                break;

            buy = i++;

            while(i<n && A[i] >= A[i-1])
                i++;
            sell = i-1;
            vector<int> temp;
            temp.push_back(buy);
            temp.push_back(sell);
            res.push_back(temp);
        }
        return res;
    }
};

// { Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends
