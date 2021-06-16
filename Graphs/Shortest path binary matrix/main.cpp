// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
struct point{
    int x;
    int y;
};

struct Node{
    point pt;
    int dist;
};



class Solution {
  public:
    int row_pos[4] = {-1, 0, 1, 0};
    int col_pos[4] = {0, -1, 0, 1};

    bool isvalid(int &row, int &col, int &rows, int &cols){
        return (row >= 0) && (row < rows) && (col >= 0) && (col < cols);
    }

    int bfs(vector<vector<int>> &A, point &src, point &dest){
        if(!A[src.x][src.y] || !A[dest.x][dest.y])
            return -1;

        int rows = A.size();
        int cols = A[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        visited[src.x][src.y] = true;

        queue<Node> q;
        Node s = {src, 0};
        q.push(s);

        while(! q.empty()){
            Node curr = q.front();
            q.pop();

            point p = curr.pt;

            if (p.x == dest.x && p.y == dest.y)
                return curr.dist;

            for(int i=0; i<4; i++){
                int row = p.x + row_pos[i];
                int col = p.y + col_pos[i];

                if(isvalid(row, col, rows, cols) && A[row][col] && !visited[row][col]){
                    visited[row][col] = true;
                    Node temp = {{row, col}, curr.dist + 1};
                    q.push(temp);
                }
            }
        }

        return -1;
    }

    int shortestDistance(int N, int M, vector<vector<int>> &A, int X, int Y) {
        // code here

        point src = {0, 0};
        point dest = {X, Y};

        return bfs(A, src, dest);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends
