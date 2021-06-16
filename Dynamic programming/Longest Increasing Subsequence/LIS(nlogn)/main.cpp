#include <bits/stdc++.h>

using namespace std;

int ceil_index(vector<int> v, int l, int h, int ele){
    while(h > l){
        int mid = (l + h)/2;
        if(v[mid] >= ele)
            h = mid;
        else
            l = mid + 1;
    }
    return h;
}

int lis(vector<int> &v, int &n){
    vector<int> tail(n);
    int length = 1;

    tail[0] = v[0];

    for(int i=1; i<n; i++){
        if(v[i] < tail[0])
            tail[0] = v[i];

        else if(v[i] > tail[length - 1])
            tail[length++] = v[i];

        else
            tail[ceil_index(tail, 0, length-1, v[i])] = v[i];
    }

    return length;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    cout<<lis(v, n);
    return 0;
}
