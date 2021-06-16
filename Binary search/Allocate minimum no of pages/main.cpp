/*
Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages.
Every student is assigned to read some consecutive books.
The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
*/

#include <bits/stdc++.h>

using namespace std;

bool is_valid(int arr[], int &n, int &m, int &mid){
    int students = 1, pages = 0;
    for(int i=0; i<n; i++){
        pages += arr[i];
        if(pages > mid){
            students++;
            pages = arr[i];
        }
    }
    if(students > m)
        return false;
    return true;
}

int min_pages(int arr[], int n, int m){
    if(n < m)
        return -1;
    int max_pages = INT_MIN, sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        max_pages = max(max_pages, arr[i]);
    }
    int low = max_pages, high = sum, res = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(is_valid(arr, n, m, mid)){
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

int main()
{
    int n, m;
    cin>>n>>m;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<(min_pages(arr, n, m));
    return 0;
}
