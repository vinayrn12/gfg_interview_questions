/*
    Given a string of arithmetic expression. Return the max value that can be generated from it(by placing braces accordingly).
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

int eval(int a, int b, char op){
    if(op == '+')
        return a+b;
    else if(op == '-')
        return a-b;
    else if(op == '*')
        return a*b;
    else if(op == '/')
        return a/b;
    else
        return 0;
}

int max_exp(string &s, int i, int j){
    if(memo[i][j] != -1)
        return memo[i][j];
    if(i == j)
        return memo[i][j] = (s[i] - 48);

    int maximum = INT_MIN;
    for(int k=i+1; k<j; k+=2){
        int left = max_exp(s, i, k-1);
        int right = max_exp(s, k+1, j);
        int temp = eval(left, right, s[k]);
        maximum = max(maximum, temp);
    }

    return memo[i][j] = maximum;
}

int main()
{
    string s;
    getline(cin, s);
    memo.resize(s.length(), vector<int>(s.length()));
    for(unsigned int i=0; i<memo.size(); i++)
        for(unsigned int j=0; j<memo[0].size(); j++)
            memo[i][j] = -1;
    cout<<max_exp(s, 0, s.length()-1);

    return 0;
}
