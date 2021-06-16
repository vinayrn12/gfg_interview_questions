// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
    {
        // code here
        vector<int> res;

        int i_r = 0, i_c = 0;

        while(i_r < r && i_c < c){
            //left->right
            for(int i=i_c; i<c; i++)
                res.push_back(matrix[i_r][i]);
            i_r++;

            //top->bottom
            for(int i=i_r; i<r; i++)
                res.push_back(matrix[i][c-1]);
            c--;

            //right->left
            if(i_r < r){
                for(int i=c-1; i>=i_c; i--)
                    res.push_back(matrix[r-1][i]);
                r--;
            }

            //bottom->up
            if(i_c < c){
                for(int i=r-1; i>=i_r; i--)
                    res.push_back(matrix[i][i_c]);
                i_c++;
            }
        }



        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;

    while(t--)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r);

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
