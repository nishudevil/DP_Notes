/*
    If element is not picked, then its processed, you can't come to it again
    If element is picked, it is unprocessed, you can pick again and again until its processed i.e decision is made not to pick it

    dp[n+1][w+1]
    Same initialization as in 0/1 Knapsack fill with 0s
    Just this changes : val[i-1]+dp[i-1][j-wt[i-1] -> val[i-1]+dp[i][j-wt[i-1]

    ------------Rod Cutting-------------
    Length(N) of entire rod
    All posible lentghs of rod after cut and their prices (1->N) length[], price[]
    Maximise profit
    dp[size+1][N+1]
    --------------Coin Change-------------
    Max no. of ways -> Make subset sum into unbounded knapsack, i-1 to i 
    Min no. of coins -> 

*/

/*
Max LCS = Min Edit Distance (least gaps are found which are chars deleted from both strings)

LIS = Binary Search is nlogn rest are n^2
There is a tabulation method:
    dp[i]=LIS at index i
    LIS=max of all(dp[i])

lower_bound -> arr[ind]>=x
upper_bound -> arr[ind]>x



*/