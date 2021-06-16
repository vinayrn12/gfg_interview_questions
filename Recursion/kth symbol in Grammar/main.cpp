/*

    On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01,
    and each occurrence of 1 with 10.
    Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).

*/

#include <bits/stdc++.h>

using namespace std;

int grammar(int n, int k){
    if(n == 1 && k == 1)
        return 0;
    int mid = pow(2, n-1)/2;
    if(k <= mid) // mid = n for the nth row
        return grammar(n-1, k);
    return !grammar(n-1, k-mid);
}

int main()
{
    int n, k;
    cin>>n>>k;
    cout<<grammar(n, k);
    return 0;
}
