#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>

vector<int> dijkstra(vector<vector<pi>> &adj, int &v, int &source){
    vector<int> dist(v, INT_MAX);
    //vector<bool> visited(v, false);

    dist[source] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.emplace(dist[source], source);

    while(! pq.empty()){
        pi temp = pq.top();
        pq.pop();

        int u = temp.second;
        for(auto it=adj[u].begin(); it!=adj[u].end(); it++){
            int d = (*it).first;
            int w = (*it).second;
            if(dist[u] + w < dist[d]){
                dist[d] = dist[u] + w;
                pq.emplace(dist[d], d);
            }
        }

    }

    return dist;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int v, e;
        cin>>v>>e;
        vector<vector<pi>> adj(v);
        for(int i=0; i<e; i++){
            int s, d, w;
            cin>>s>>d>>w;
            adj[s].push_back(make_pair(d, w));
            adj[d].push_back(make_pair(s, w));
            int source;
            cin>>source;
            vector<int> dist = dijkstra(adj, v, source);
//            for(int i=0; i<v; i++){
//                for(auto it=adj[i].begin(); it!=adj[i].end(); it++)
//                    cout<<it->first<<" : "<<it->second<<"\t";
//                cout<<endl;
//            }
            for(int i=0; i<dist.size(); i++)
                cout<<dist[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
