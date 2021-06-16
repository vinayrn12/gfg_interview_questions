// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

struct point{
    int x;
    int y;
};

class Solution{
    public:
    bool canleft(vector<vector<int>> &m, point src, vector<vector<bool>> &visited){
        int x = src.x;
        int y = src.y;
        int n = m.size();
        return ((y-1 >= 0) && (y < n) && !visited[x][y-1] && m[x][y-1]==1);
    }

    bool canright(vector<vector<int>> &m, point src, vector<vector<bool>> &visited){
        int x = src.x;
        int y = src.y;
        int n = m.size();
        return ((y >= 0) && (y+1 < n) && !visited[x][y+1] && m[x][y+1]==1);
    }

    bool cantop(vector<vector<int>> &m, point src, vector<vector<bool>> &visited){
        int x = src.x;
        int y = src.y;
        int n = m.size();
        return ((x-1 >= 0) && (x-1 < n) && !visited[x-1][y] && m[x-1][y]==1);
    }

    bool canbottom(vector<vector<int>> &m, point src, vector<vector<bool>> &visited){
        int x = src.x;
        int y = src.y;
        int n = m.size();
        return ((x+1 >= 0) && (x+1 < n) && !visited[x+1][y] && m[x=1][y]==1);
    }

    void maze(string &path, vector<vector<int>> &m, vector<vector<bool>> &visited, vector<string> &res, point src, point &dest){
        if(m[src.x][src.y]==0 || m[dest.x][dest.y]==0)
            return;
        if(src.x == dest.x  &&  src.y == dest.y){
            res.push_back(path);
            return;
        }
        if(canleft(m, src, visited)){
            path += "L";
            src.y -= 1;
            visited[src.x][src.y] = true;
            maze(path, m, visited, res, src, dest);
            visited[src.x][src.y] = false;
            src.y += 1;
            path.pop_back();
        }
        if(canright(m, src, visited)){
            path += "R";
            src.y += 1;
            visited[src.x][src.y] = true;
            maze(path, m, visited, res, src, dest);
            visited[src.x][src.y] = false;
            src.y -= 1;
            path.pop_back();
        }
        if(cantop(m, src, visited)){
            path += "U";
            src.x -= 1;
            visited[src.x][src.y] = true;
            maze(path, m, visited, res, src, dest);
            visited[src.x][src.y] = false;
            src.x += 1;
            path.pop_back();
        }
        if(canbottom(m, src, visited)){
            path += "D";
            src.x += 1;
            visited[src.x][src.y] = true;
            maze(path, m, visited, res, src, dest);
            visited[src.x][src.y] = false;
            src.x -= 1;
            path.pop_back();
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string path {""};
        point src {0, 0};
        point dest{n-1, n-1};
        visited[0][0] = true;
        maze(path, m, visited, res, src, dest);
        sort(res.begin(), res.end());
        return res;
    }
};




// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
