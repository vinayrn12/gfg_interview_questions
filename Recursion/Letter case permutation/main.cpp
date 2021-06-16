/*


Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

*/

#include <bits/stdc++.h>

using namespace std;

void solve(string input, string output){
    if(input.length() == 0){
        cout<<output<<endl;
        return;
    }
    if(isdigit(input[0])){
        output += input[0];
        input.erase(input.begin());
        solve(input, output);
        return;
    }
    string op1 = output;
    string op2 = output;
    if(islower(input[0])){
        op1 += input[0];
        op2 += toupper(input[0]);
    }
    else{
        op1 += input[0];
        op2 += tolower(input[0]);
    }
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
