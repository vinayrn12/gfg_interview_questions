/*
Given two arrays X and Y of positive integers,
find the number of pairs such that x^y > y^x (raised to power of) where x is an element from X and y is an element from Y.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:

    // X[], Y[]: input arrau
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    long long count_pairs(int &x, int Y[], int &n, int county[]){
        if(x == 0)
            return 0;
        if(x == 1)
            return county[0];

        int ans = (Y + n) - upper_bound(Y, Y+n, x);

        ans += county[0] + county[1];

        if(x == 2)
            ans -= (county[3] + county[4]);

        if(x == 3)
            ans += county[2];

        return ans;
    }

    long long countPairs(int X[], int Y[], int M, int N)
    {
       //Your code here
       int county[5] = {0};
       for(int i=0; i<N; i++)
            if(Y[i] < 5)
                county[Y[i]]++;

        sort(Y, Y+N);

        long long total_pairs = 0;
        for(int i=0; i<M; i++){
            total_pairs += count_pairs(X[i], Y, N, county);
        }
        return total_pairs;
    }
};


// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends
