// Given two sequences, find the length of longest subsequence present in both of them.

#include <bits/stdc++.h>

using namespace std;

map<string, int> memo;

int lcs(string s1, string s2, int n, int m){
    string key = to_string(n) + "," + to_string(m);
    if(memo.find(key) != memo.end())
        return memo[key];
    if(n == 0 || m == 0)
        return 0;
    //Tree
    if(s1[n-1] == s2[m-1])
        memo[key] = 1 + lcs(s1, s2, n-1, m-1);
    else
        memo[key] = max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
    return memo[key];
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int n = s1.length();
    int m = s2.length();
    cout<<lcs(s1, s2, n, m);
    return 0;
}
