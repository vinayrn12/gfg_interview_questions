// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	void DFS(int u, vector<bool> &visited, vector<int> adj[], stack<int> &s){
	    visited[u] = true;

	    for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
	        if(! visited[*it])
	            DFS(*it, visited, adj, s);

	   s.push(u);
	}

	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
	    vector<int> dfs;
	    vector<bool> visited(V, false);
	    stack<int> s;

	    for(int i=0; i<V; i++)
	        if(! visited[i])
	            DFS(i, visited, adj, s);

	    while(! s.empty()){
	        dfs.push_back(s.top());
	        s.pop();
	    }
	    return dfs;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;

        cout<<"Topo sort : ";
        for(size_t i=0; i<res.size(); i++)
            cout<<res[i]<<" ";

    }

    return 0;
}  // } Driver Code Ends
