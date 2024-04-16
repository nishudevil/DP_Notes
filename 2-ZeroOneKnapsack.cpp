class Solution{

    //n=no. of items,w=different sums, initliaze dp[n+1][w+1], determine the first row & column as 0 or true/flase {n,w = i,j}
    //--- I/P : wt[] and val[] and max W, find max possible val
    /*

    Base Cond: if(n==0 || W==0) return 0;
    Memoize:
    if(dp[n][W]!=-1) return dp[n][W];

    if(wt[n-1]<=W){
        return dp[n][W]=max(val[n-1] + knapsack(wt,val,n-1,W-wt[n-1]), knapsack(wt,val,n-1,W) );
    }else{
        return dp[n][W]=knapsack(wt,val,n-1,W) ;
    }


    Top-Down:
    for(int i=1;i<n+1;i++){
        for( int j=1;j<W+1;j++){

            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
            
        }
    }

    return dp[n][W];

    --------Subset Sum-------------
    Check if subset exists with required sum
    Initialize i=0 with False and then j=0 with True
    When you have only one array in i/p, consider that wt[] and rest all remains same
    Instead of max use ||, since initialized dp[][] has boolean values
    
    --------Equal sum partition -> replace max() with || --------
    --------Count subSeq with sum k -> replace || with + ------------------
    --------Minimum subset sum diff abs(s1-s2) = minimum
    Range=sum of all elements, 2 partition sums are S1 and Range-S1
    Minimize ( Range-2*S1 )
    Choose S1 such that it is less than range/2
    Use the last row of subset sum dp[][], which gives whether there is a subset for sum from 0 to range/2 when size of [] is n
    ---------No of subset with given diff----------------
    S1-S2=Diff
    S1=(Diff+TotalSum)/2
    ----------Target Sum---------------
    +/- every element to achieve target
    Just divide all + into S1 and all - into S2, then it becomes S1-S2=target
     
       
    
    
    */

};