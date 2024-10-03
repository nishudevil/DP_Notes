/*Break array in betwwen from i to j for all k values; [i,k] and [k+1,j]
Combine answer from all recursive calls

i=1 and j=arr.size()-1
Base cond: i>=j return 0;

Break solve(arr,i,j) to solve(arr,i,k) and solve(arr,k+1,j) for k = [i,j-1] and combine these multiplication costs with arr[i-1] x arr[k] x arr[j]

*/

/*
Partition DP  
Solve problem in a pattern
Different way of solving can give different answers you need the best
Out of all partitions (k=i to j-1) which gives the best (i,k) (k+1,j) 

MCM: Min cost to multiply N matrices (m,n) * (n,o) = (m * n * o) => f(1,n-1)
Start with entire block/array (start, end) -> (i,j)
Run a loop to try all partitions : (i,j) => k=[i,j-1]
Return the best possible 2 partitions


*/

#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
    
    // base condition i.e single matrix => 0 operations
    if(i == j)
        return 0;
        
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int mini = INT_MAX;
    
    // partioning loop
    for(int k = i; k<= j-1; k++){
        
        int ans = f(arr,i,k,dp) + f(arr, k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
        
        mini = min(mini,ans);
        
    }
    
    return dp[i][j]=mini;
}


int matrixMultiplication(vector<int>& arr, int N){
    
    vector<vector<int>> dp(N,vector<int>(N,-1));
    
    int i =1;
    int j = N-1;
    
    
    return f(arr,i,j,dp);
    
    
}

int main() {
	
	vector<int> arr = {10, 20, 30, 40, 50};
	
	int n = arr.size();
	
	cout<<"The minimum number of operations is "<<matrixMultiplication(arr,n);
	
	return 0;
}

/*Bottom - Up
In recursion i moves from 1 to n-1 and j moves from n-1 to 1
So, for loop for i will be n-1 to 1 and for j will be i+1 to n-1 instead of 1 as j will always be to the right of i
*/

int matrixMultiplication(vector<int>& arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, -1));

    // Initialize the diagonal elements of the DP table to 0
    for (int i = 0; i < N; i++) dp[i][i] = 0;

    // Loop for the length of the chain
    for (int i = N-1; i>=1; i--) {
        for (int j = i+1; j <= N - 1; j++) {
            int mini=1e9;
            for(int k = i; k<= j-1; k++){        
                int ans = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];                
                mini = min(mini,ans);        
            }
            dp[i][j]=mini;
        }        
    }
    // The result is stored in dp[1][N-1]
    return dp[1][N - 1];
}