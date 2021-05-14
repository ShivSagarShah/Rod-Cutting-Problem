/*
1. You are given an integer N, which represents the length of a rod, and an array of integers, which represents the prices of rod pieces of length varying from 1 to 
     N.
2. You have to find the maximum value that can be obtained by selling the rod.
3. You can sell it in pieces or as a whole.

Constraints
1 <= N <= 100000
1 <= arr[i] <= 10^8

Sample Input
8
1   
5   
8   
9  
10 
17  
17  
20

Sample Output
22
*/

#include<bits/stdc++.h>
using namespace std;
int maximumprofit(int arr[], int n){
    int dp[n+1];
    dp[0] = 0;
    dp[1] = arr[0];
    for(int i = 2; i<n+1; i++){
        dp[i] = arr[i-1];
        int start = 1;
        int end = i-1;
        while(start<=end){
            if(dp[start] + dp[end] > dp[i]){
                dp[i] = dp[start] + dp[end];
            }
                start++;
                end--;                            
        }
        
    }
    return dp[n];

}
int main(){
    int n;
    cout<<"Enter the length(N) of Rod: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the prices of length varying from 1 to N: "<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Maximum Profit is: "<<maximumprofit(arr, n);

    return 0;
}
