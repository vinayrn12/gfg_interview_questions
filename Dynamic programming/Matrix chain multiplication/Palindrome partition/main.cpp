/*
    Given a string. Return the minimum number of partitions by which each substring will be a palindrome.
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

bool palindrome(string &s, int i, int j){
    while(i <= j){
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int pp(string &s, int i, int j){
    if(memo[i][j] != -1)
        return memo[i][j];
    if(i >= j)
        return 0;
    if(palindrome(s, i, j))
        return 0;

    int minimum = INT_MAX;
    for(int k=i; k<j; k++){
        int right = 0;
        if(palindrome(s, i, k))
            right = pp(s, k+1, j);
        else{
            memo[i][k] = 0;
            continue;
        }

        int temp = right + 1;
        minimum = min(minimum, temp);
    }
    return memo[i][j] = minimum;
}

int main()
{
    string s;
    getline(cin, s);
    memo.resize(s.length(), vector<int>(s.length()));
    for(int i=0; i<memo.size(); i++)
        for(int j=0; j<memo[0].size(); j++)
            memo[i][j] = -1;
    cout<<pp(s, 0, s.length()-1);
    return 0;
}
