/*
    Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
    To scramble the string, we may choose any non-leaf node and swap its two children.

                                                 great
                                               /    \
                                              gr    eat
                                             / \    /  \
                                            g   r  e   at
                                                       / \
                                                      a   t


    For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.
    We say that “rgeat” is a scrambled string of “great”.

                                                 rgeat
                                               /    \
                                              rg    eat
                                             / \    /  \
                                            r   g  e   at
                                                       / \
                                                      a   t


    Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.
*/

#include <bits/stdc++.h>

using namespace std;

map<string, bool> memo;

bool ss(string a, string b){
    string pos = a + "," + b;
    if(memo.find(pos) != memo.end())
        return memo[pos];
    if(a.compare(b) == 0)
        return memo[pos] = true;
    if(a.length() <= 1)
        return memo[pos] = false;

    int flag = false;
    int n = a.length();
    for(int i=1; i<n; i++){
        if(ss(a.substr(0, i), b.substr(0, i)) && ss(a.substr(i, n-i), b.substr(i, n-i))
                                        ||
           ss(a.substr(0, i), b.substr(n-i, i)) && ss(a.substr(n-i, i), b.substr(0, i)))
                flag = true;
    }
    return memo[pos] = flag;
}

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    if(a.length() != b.length()){
        cout<<"False"<<endl;
        return 0;
    }
    if(a.length() == 0 && b.length() == 0){
        cout<<"True"<<endl;
        return 0;
    }
    cout<<ss(a, b)<<endl;
    return 0;
}
