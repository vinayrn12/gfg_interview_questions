// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}

		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

bool myComp(val a, val b){
    return b.second > a.second;
}

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    //Your code here
    sort(p, p + n, myComp);
    int max_chain = 1, chain_index = 0;
    for(auto it=1; it<n; it++)
        if(p[it].first > p[chain_index].second){
            max_chain ++;
            chain_index = it;
        }
    return max_chain;
}
