/*
    Given a boolean expression with following symbols.

    Symbols
        'T' ---> true
        'F' ---> false

    And following operators filled between symbols

    Operators
        &   ---> boolean AND
        |   ---> boolean OR
        ^   ---> boolean XOR

    Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> memo;

int eval(int &lt, int &lf, int &rt, int &rf, bool compute, char op){
    int res;
    if(op == '&'){
        if(compute)
            res = lt * rt;
        else
            res = (lf * rf) + (lt * rf) + (lf * rt);
    }
    else if(op == '|'){
        if(compute)
            res = (lt * rt) + (lt * rf) + (lf * rt);
        else
            res = lf * rf;
    }
    else if(op == '^'){
        if(compute)
            res = (lf * rt) + (lt * rf);
        else
            res = (lt * rt) + (rf * lf);
    }
    else
        res = 0;
    return res;
}

int num_ways(string &s, int i, int j, int compute){
    if(i == j){
        if(compute)
            return memo[i][j][compute] = (s[i] == 'T');
        else
            return memo[i][j][compute] = (s[i] == 'F');
    }
    if(memo[i][j][compute] != -1)
        return memo[i][j][compute];

    int ways = 0;
    for(int k=i+1; k<j; k+=2){
        /*
            We can compute each expression in four ways
                left-true op right-true
                left-true op right-false
                left-false op right-true
                left-false op right-false
        */
        int lt = num_ways(s, i, k-1, true);
        int lf = num_ways(s, i, k-1, false);
        int rt = num_ways(s, k+1, j, true);
        int rf = num_ways(s, k+1, j, false);

        ways += eval(lt, lf, rt, rf, compute, s[k]);

    }

    return memo[i][j][compute] = ways;
}

int main()
{
    string s;
    getline(cin, s);
    //Resizing vector//
    memo.resize(s.length());
    for(unsigned int i=0; i<memo.size(); i++){
        memo[i].resize(s.length());
        for(unsigned int j=0; j<memo[i].size(); j++){
            memo[i][j].resize(2);
            for(unsigned int k=0; k<memo[i][j].size(); k++)
                memo[i][j][k] = -1;
        }
    }
    //****************//
    cout<<num_ways(s, 0, s.length()-1, 1);
    return 0;
}
