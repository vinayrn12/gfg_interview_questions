//Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards.
//More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

#include <bits/stdc++.h>

using namespace std;

int palindrome(string &s1, string &s2){
    int n = s1.length();
    vector<vector<int>> tab(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1])
                tab[i][j] = 1 + tab[i-1][j-1];
            else
                tab[i][j] = 0;
        }
    }
    int longest_substring = INT_MIN;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            if(tab[i][j] > longest_substring)
                longest_substring = tab[i][j];

    return longest_substring;
}

bool is_palin(string s, int l, int r){

    while(l <= r){
        if(s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int main()
{
    int t;
    cin>>t>>ws;
    for(int z=0; z<t; z++){
        string s1, res{""};
        getline(cin, s1);
        string s2 = string(s1.rbegin(), s1.rend());
        int palin_len = palindrome(s1, s2);
        for(int i=0; (i+palin_len)<=s1.length(); i++){
            if(is_palin(s1, i, i+palin_len-1)){
                res = s1.substr(i, palin_len);
                break;
            }
        }
        cout<<res<<endl;
    }

    return 0;
}
