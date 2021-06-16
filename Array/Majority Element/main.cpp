// A majority element in an array A of size N is an element that appears more than N/2 times in the array.

// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{

    // your code here
    //Use boyer-moore voting algorithm
    int max_index=0, count=1;
    for(int i=1; i<size; i++){
        if(a[i] != a[max_index])
            count--;
        else
            count++;

        if(count == 0){
            max_index = i;
            count = 1;
        }
    }

    int ele = a[max_index];
    count = 0;
    for(int i=0; i<size; i++)
        if(a[i] == ele)
            count ++;

    if(count > (size/2))
        return a[max_index];
    return -1;

}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];

        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
  // } Driver Code Ends
