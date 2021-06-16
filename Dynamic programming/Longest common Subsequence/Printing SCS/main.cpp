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
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                tab[i][j] = 1 + tab[i-1][j-1];
            else
                tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
        }
    }
    string scs = "";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            scs += s1[i-1];
            i--;
            j--;
        }
        else{
            if(tab[i-1][j] > tab[i][j-1]){
                scs += s1[i-1];
                i--;
            }
            else{
                scs += s2[j-1];
                j--;
            }
        }
    }
    while(i > 0){
        scs += s1[i-1];
        i--;
    }
    while(j > 0){
        scs += s2[j-1];
        j--;
    }
    scs = string(scs.rbegin(), scs.rend());
    cout<<scs;

    return 0;
}
