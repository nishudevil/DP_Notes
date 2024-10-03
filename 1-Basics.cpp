/*
1. Choice must be there include/not include => recursion => if overlapping (2 recursive calls) then DP 
Single rec function shouldn't be considered DP

2. Optimal -> Min/Max/Largest kind of problems

Recursive -> Memoize -> Top-down

Fractional Knapsack -> Greedy

Patterns:
0/1 Knapsack (Subset sum/target sum) - some items would be given pick/not pick and find max/min
Unbounded knapsack
Fibonacci
LCS/LIS
Matrix Chain Multiplication
DP on tree
DP on grid


-------------------
Knapsack:
items {weight,val} with maxWeight W capacity of bag
Maximize value 
0/1 -> pick or not pick looking into contraints (no multiple)
Unbounded -> any item can be placed unlimited number of times

0/1 Knapsnack Recursive -> Base Cond: Think of smallest valid I/P
Memoize
if two variables are changing in recursion, initialize int[n+1][w+1]={-1}
and store it in dp[n][w] the result of every recursion

Top-down -> https://www.youtube.com/watch?v=ntCGbPMeqgg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=6
We dont want to perform any recursive call, only use the dp table.
Sometimes too many recursive calls can fill up the stack space //stack overflow

Recursive base condition is used to fill top-down initialization i.e for n=0/w=0
For rest of the rows replace (n,w) with (i,j) within the two for loops to access all the overlapping situations for(i=1->n;j=1->w): t[i][j]=max()
Replace rec(n-1,w-wi) = dp[n-1][w-wi], basically if you choose to pick or not pick, it will poitn to the respective subproblem in the matrix 
We fill the current block using some previously filled block
return t[n][w];

Reference: https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

*/

/*
Think from index n, make base for index 0 => if(ind==0) retrun 0; => dp[n-1]/....
Handle with conditions like if(ind-j)>=0, then only do recursion calls
simply convert rec(n-1) to dp [i-1]
return dp[n-1];
TC -> Number of States
SC -> Recursion Stack Space (path length) + dp[][]
----------------------
    Declare base case
    Express all states inf for loops
    Copy the recurrence
----------------------

Recursion and Tabulation are in opposite direction=> (n-1 to 0) rec then (0 to n-1) is tab
*/

// Cool Stuff: unordered_map<int, unordered_map<int,int>>mp; if(mp[s].count(k))return mp[s][k];

// vector<string> split(string s){
//         vector<string> res;
//         int pos = 0;
//         while(true){
//             pos = s.find("/");
//             if(pos==string::npos){
//                 res.push_back(s);
//                 break;
//             } 
//             res.push_back(s.substr(0,pos));
//             s.erase(0,pos+1); 
//         }
//         return res;
//     }