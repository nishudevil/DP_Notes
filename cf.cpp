#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
 
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
 
 int dp[4001];
 
int rec(int len, vector<int>& cuts) {
    if(len==0) return 0;
    if(dp[len]!=-1) return dp[len];
    
    int temp=INT_MIN;
    for(int i=0;i<3;i++){
        if(len-cuts[i]>=0){
            temp=max(temp,1+rec(len-cuts[i],cuts));
        }
    }

    return dp[len]=temp;
    
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<int> cuts ={a,b,c};
    memset(dp,-1,sizeof(dp));
    cout<<rec(n,cuts);


    return 0;
}