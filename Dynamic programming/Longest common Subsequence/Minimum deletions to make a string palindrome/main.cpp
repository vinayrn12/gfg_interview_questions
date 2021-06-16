#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    s2 = string(s1.rbegin(), s1.rend());
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> tab(n+1, vector<int>(m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                tab[i][j] = 1 + tab[i-1][j-1];
            else
                tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
        }
    }
    int deletions = s1.length() - tab[n][m];
    cout<<deletions;
    return 0;
}
