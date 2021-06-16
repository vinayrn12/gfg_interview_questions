/*

    Print all permutations of a string keeping the sequence but changing cases.

    Examples:

    Input : ab
    Output : AB Ab ab aB

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
    op1 += input[0];
    op2 += toupper(input[0]);
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
