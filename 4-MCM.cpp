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
Out of all partitions which gives the best (i,k) (k+1,j)

*/