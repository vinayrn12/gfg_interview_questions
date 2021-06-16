// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    vector<int> bfs;
	    vector<bool> visited(V, false);
	    queue<int> q;
	    q.push(0);
	    visited[0] = true;

	    while(! q.empty()){
	        int u = q.front();
	        q.pop();

	        bfs.push_back(u);

	        for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
	            if(! visited[*it]){
	                q.push(*it);
	                visited[*it] = true;
	            }
	    }

	    return bfs;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends