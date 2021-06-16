//Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.

#include <bits/stdc++.h>

using namespace std;

int mah(vector<int> &arr, int n){
    vector<int> smaller_left(n);
    vector<int> smaller_right(n);
    vector<int> area(n);
    stack<pair<int, int>> s;

    //Smaller left
    for(int i=0; i<n; i++){
        if(s.empty())
            smaller_left[i] = -1;
        else{
            if(s.top().first < arr[i])
                smaller_left[i] = s.top().second;
            else{
                while(!s.empty() && s.top().first >= arr[i])
                    s.pop();
                if(s.empty())
                    smaller_left[i] = -1;
                else
                    smaller_left[i] = s.top().second;
            }
        }
        s.emplace(arr[i], i);
    }

    while(!s.empty())
        s.pop();
    //Smaller Right
    for(int i=n-1; i>-1; i--){
        if(s.empty())
            smaller_right[i] = n;
        else{
            if(s.top().first < arr[i])
                smaller_right[i] = s.top().second;
            else{
                while(!s.empty() && s.top().first >= arr[i])
                    s.pop();
                if(s.empty())
                    smaller_right[i] = n;
                else
                    smaller_right[i] = s.top().second;
            }
        }
        s.emplace(arr[i], i);
    }

    for(int i=0; i<n; i++)
        area[i] = (smaller_right[i] - smaller_left[i] - 1) * arr[i];

    int max_area = INT_MIN;
    for(int i=0; i<n; i++)
        max_area = max(max_area, area[i]);
    return max_area;
}

int main()
{
    int rows, columns;
    cin>>rows>>columns;
    vector<vector<int>> matrix(rows, vector<int>(columns));
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            cin>>matrix[i][j];

    vector<int> hist(columns);
    int max_area = INT_MIN;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(matrix[i][j] == 0)
                hist[j] = 0;
            else
                hist[j] = hist[j] + matrix[i][j];
        }
        max_area = max(max_area, mah(hist, columns));
    }
    cout<<max_area;
    return 0;
}
