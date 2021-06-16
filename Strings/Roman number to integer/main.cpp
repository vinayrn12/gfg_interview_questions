// { Driver Code Starts
// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}// } Driver Code Ends


// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int value(char c){
    if(c == 'I')
        return 1;
    else if(c == 'V')
        return 5;
    else if(c == 'X')
        return 10;
    else if(c == 'L')
        return 50;
    else if(c == 'C')
        return 100;
    else if(c == 'D')
        return 500;
    else if(c == 'M')
        return 1000;
}

int romanToDecimal(string &str) {
    // code here
    int number = 0;
    for(int i=0; i<str.length()-1; i++){
        if(value(str[i]) >= value(str[i+1]))
            number += value(str[i]);
        else
            number -= value(str[i]);
    }
    number += value(str[str.length()-1]);
    return number;
}
