// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool has_cycle(int u, vector<int> adj[], vector<bool> &visited, vector<bool> &recStack){
        visited[u] = true;
        recStack[u] = true;

        for(auto i:adj[u]){
            if(! visited[i]){
                if(has_cycle(i, adj, visited, recStack))
                    return true;
            }
            else if(recStack[i])
                return true;
        }
        recStack[u] = false;
        return false;
    }

	bool isCyclic(int V, vector<int> adj[]){
	    // Code here
	    vector<bool> visited(V, false);
	    vector<bool> recStack(V, false);

	    for(int i=0; i<V; i++){
	        if(! visited[i])
    	        if(has_cycle(i, adj, visited, recStack))
    	            return true;
	    }

	    return false;
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
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
