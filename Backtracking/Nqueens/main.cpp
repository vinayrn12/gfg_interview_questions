// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isvalid(vector<int> &col_pos){
        int rowId = col_pos.size() - 1;
        for(int i=0; i<rowId; i++){
            int diff = abs(col_pos[i] - col_pos[rowId]);
            if(diff == 0 || diff == rowId-i)
                return false;
        }
        return true;
    }

    void nqueenutil(int &n, int row, vector<int> &col_pos, vector<vector<int>> &res){
        if(row > n){
            res.push_back(col_pos);
            return;
        }

        else{
            for(int col=1; col<=n; col++){
                col_pos.push_back(col);
                if(isvalid(col_pos))
                    nqueenutil(n, row+1, col_pos, res);
                col_pos.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> col_pos;
        vector<vector<int>> res;
        nqueenutil(n, 1, col_pos, res);
        sort(res.begin(), res.end());
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
