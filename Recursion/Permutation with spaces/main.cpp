/*

    Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them.
    Output should be printed in sorted increasing order of strings.

    Input:  str[] = "ABC"
    Output: (A B C)(A BC)(AB C)(ABC)
*/

#include <bits/stdc++.h>

using namespace std;

void solve(string input, string output){
    if(input.length() == 0){
        cout<<output<<endl;
        return;
    }
    string op1 = output, op2 = output;
    op1 += input[0];
    op2 += ' ';
    op2 += input[0];
    input.erase(input.begin());
    solve(input, op1);
    solve(input, op2);
}

int main()
{
    string input{""}, output{""};
    cin>>input;
    output += input[0];
    input.erase(input.begin());
    cout<<"=========================================="<<endl;
    solve(input, output);
    cout<<"==========================================";
    return 0;
}
