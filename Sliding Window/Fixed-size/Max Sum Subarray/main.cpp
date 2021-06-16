//Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin>>N>>K;
    vector<int> Arr(N);
    for(int i=0; i<N; i++)
        cin>>Arr[i];
    int max_across_windows = INT_MIN;
    int sum_window = 0;
    int i = 0, j =0;
    while(j < N){
        sum_window += Arr[j];

        if(j-i+1 < K)
            j++;

        else if(j-i+1 == K){
            max_across_windows = max(max_across_windows, sum_window);
            sum_window -= Arr[i];
            i++;
            j++;
        }
    }
    cout<<max_across_windows;
    return 0;
}
