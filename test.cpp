class Solution {
    public:
        int dp[2001][2001];
    
        int rec (int i, int j, string& s, string& p){
    
            if(i<0 && j<0){
                return 1;
            }
    
            if(i<0 || j<0) return 0;
    
            if (p[j]!='?' && p[j]!='*' && s[i]!=p[j]) return 0;
    
    
            if(p[j]=='?' || s[i]==p[j]) {
                if(rec(i-1,j-1,s,p)) return dp[i][j]=1;
                // this is for p[j]='*'
                }else{
                    for(int ind=0;ind<=i+1;ind++){
                        if(rec(i-ind,j-1,s,p)) return dp[i][j]=1;
                    }
            }
    
    
            return 0;
    
        }
        bool isMatch(string s, string p) {
            int m=s.size();
            int n=p.size();
    
            memset(dp,-1,sizeof(dp));
    
            return (bool) rec(m-1,n-1,s,p);
            
        }
    };