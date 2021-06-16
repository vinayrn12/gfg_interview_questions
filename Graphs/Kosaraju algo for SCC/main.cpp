// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	/*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    void dfs_forw(vector<int> adj[], int u, stack<int> &s, vector<bool> &visited){
        visited[u] = true;

        for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
            if(! visited[*it])
                dfs_forw(adj, *it, s, visited);

        s.push(u);
    }

    vector<vector<int>> reverse_graph(vector<int> adj[], int &V){
        vector<vector<int>> adj_rev(V);

        for(int i=0; i<V; i++){
            for(auto it=adj[i].begin(); it!=adj[i].end(); it++)
                adj_rev[*it].push_back(i);
        }

        return adj_rev;
    }

    void dfs_rev(int u, vector<vector<int>> &adj_rev, vector<bool> &visited){
        visited[u] = true;

        for(auto it=adj_rev[u].begin(); it!=adj_rev[u].end(); it++)
            if(! visited[*it])
                dfs_rev(*it, adj_rev, visited);
    }

    int kosaraju(int V, vector<int> adj[]) {
        //code here
        vector<bool> visited(V, false);
        stack<int> s;

        for(int i=0; i<V; i++)
            if(! visited[i])
                dfs_forw(adj, i, s, visited);

        vector<vector<int>> adj_rev = reverse_graph(adj, V);

        for(int i=0; i<V; i++)
            visited[i] = false;

        int scc = 0;

        while(! s.empty()){
            int u = s.top();
            s.pop();

            if(! visited[u]){
                dfs_rev(u, adj_rev, visited);
                scc++;
            }
        }

        return scc;
    }
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
