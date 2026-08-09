class Solution {
public:
    long long solve(int i,int j,vector<int>& piles, vector<vector<int>>&dp){
        if(i>j)return 0;
        if(i==j)return piles[i];
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long take_i=piles[i]+min(solve(i+2,j,piles,dp),solve(i+1,j-1,piles,dp));
        long long take_j=piles[j]+min(solve(i+1,j-1,piles,dp),solve(i,j-2,piles,dp));
        return dp[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        long long sum=0;
        for(int x:piles)sum+=x;
        long long player1=solve(0,n-1,piles,dp);
        long long player2=sum-player1;
        return player1>=player2;
    }
};
