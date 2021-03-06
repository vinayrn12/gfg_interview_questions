// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void topoutil(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s){
        visited[u] = true;

        for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
            if(! visited[*it])
                topoutil(*it, adj, visited, s);

        s.push(u);
    }

    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>> adj(K);

        //creating the adjacency list
        for(int i=0; i<N-1; i++){
            string word1 = dict[i], word2=dict[i+1];
            for(int j=0; j<min(word1.length(), word2.length()); j++){
                if(word1[j] != word2[j]){
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    break;
                }
            }
        }

        //topo sorting
        stack<int> s;
        vector<bool> visited(K, false);
        for(int i=0; i<K; i++)
            if(! visited[i])
                topoutil(i, adj, visited, s);

        string res;
        while(! s.empty()){
            res += (char)(s.top() + 'a');
            //cout<<(char)(s.top()+'a')<<" ";
            s.pop();
        }

        return res;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
