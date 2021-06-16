/*
    Given two strings str1 and str2 and below operations that can performed on str1.
    Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

        Insert
        Remove
        Replace

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> tab(n+1, vector<int>(m+1));
    for(int i=0; i<=n; i++)
        tab[i][0] = i;
    for(int j=0; j<=m; j++)
        tab[0][j] = j;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                tab[i][j] = tab[i-1][j-1];
            else
                tab[i][j] = 1 + min(tab[i-1][j], min(tab[i][j-1], tab[i-1][j-1]));
        }
    }
    cout<<tab[n][m];
    return 0;
}
