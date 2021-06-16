#include <bits/stdc++.h>

using namespace std;

int toh(int n, int src, int dest, int aux){
    if(n == 1){
        cout<<"move disk "<<n<<" from rod "<<src<<" to rod "<<dest<<endl;
        return 1;
    }
    int n1 = toh(n-1, src, aux, dest);
    cout<<"move disk "<<n<<" from rod "<<src<<" to rod "<<dest<<endl;
    int n2 = toh(n-1, aux, dest, src);
    return 1 + n1 + n2;
}

int main()
{
    int n;
    cin>>n;
    cout<<toh(n, 1, 3, 2);
    return 0;
}
