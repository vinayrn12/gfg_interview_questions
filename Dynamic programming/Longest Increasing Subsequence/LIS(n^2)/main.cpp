/*

    The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence
    such that all elements of the subsequence are sorted in increasing order.
    For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<int> lcs(n, 1);
    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++)
            if(arr[j] < arr[i])
                lcs[i] = max(lcs[i], 1 + lcs[j]);
    int res = INT_MIN;
    for(int i=0; i<n; i++)
        res = max(res, lcs[i]);
    cout<<res;
    return 0;
}
