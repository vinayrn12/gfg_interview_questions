#include <bits/stdc++.h>

using namespace std;

void solve(int open, int close, string output, vector<string> &temp){
    if(open == 0 && close == 0){
        temp.push_back(output);
        return;
    }
    if(open == close){
        output += '(';
        return solve(open-1, close, output, temp);
    }
    if(open > 0){
        string op1 = output + '(';
        solve(open-1, close, op1, temp);
    }
    if(close > 0){
        string op2 = output + ')';
        solve(open, close-1, op2, temp);
    }
}

int main()
{
    int n;
    cin>>n;
    int open = n, close = n;
    vector<string> res;
    solve(open, close, "", res);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<"\t"<<endl;
    return 0;
}
