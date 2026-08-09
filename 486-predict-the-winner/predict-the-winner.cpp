class Solution{
public:
    long long solve(int i,int j,vector<int>& nums, vector<vector<int>>&dp){
        if(i>j)return 0;
        if(i==j)return nums[i];
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long take_i=nums[i]+min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
        long long take_j=nums[j]+min(solve(i+1,j-1,nums,dp),solve(i,j-2,nums,dp));
        return dp[i][j]=max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        long long sum=0;
        for(int x:nums)sum+=x;
        long long player1=solve(0,n-1,nums,dp);
        long long player2=sum-player1;
        return player1>=player2;
    }
};