/*

    Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

*/

#include <bits/stdc++.h>

using namespace std;

void solve(int ones, int zeros, int n, vector<string> &res, string output){
    if(n == 0){
        res.push_back(output);
        return;
    }
    string op = output + '1';
    solve(ones+1, zeros, n-1, res, op);
    if(ones > zeros){
        string op2 = output + '0';
        solve(ones, zeros+1, n-1, res, op2);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<string> res;
    solve(0, 0, n, res, "");
    for(size_t i=0; i<res.size(); i++)
        cout<<res[i]<<endl;
    return 0;
}
