/*

    Given a set represented as string, write a recursive code to print all subsets of it. The subsets can be printed in any order.

    Printing subsequences, powersets or subsets is all the same.
    All substrings are subsequences, all subsequences are subsets.

*/

#include <bits/stdc++.h>

using namespace std;

void solve(string input, string output){
    if(input.length() == 0){
        cout<<output<<endl;
        return;
    }
    string op1 = output;
    string op2 = output;
    op2 += input[0];
    input.erase(input.begin());
    solve(input, op1);
    solve(input, op2);
}

int main()
{
    string input{""}, output{""};
    cin>>input;
    cout<<"=========================================="<<endl;
    solve(input, output);
    cout<<"==========================================";
    return 0;
}
