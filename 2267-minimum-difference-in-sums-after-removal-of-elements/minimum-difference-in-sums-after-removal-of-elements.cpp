class Solution {
public:
    long long minimumDifference(vector<int>& nums){
        int n=nums.size()/3;
        vector<long long>left(3*n);
        vector<long long>right(3*n);
        priority_queue<int>left_maxheap;
        long long sum=0;
        for(int i=0;i<2*n;i++){
            left_maxheap.push(nums[i]);
            sum+=nums[i];
            if(left_maxheap.size()>n){
                sum-=left_maxheap.top();
                left_maxheap.pop();
            }
            if(left_maxheap.size()==n) left[i]=sum;
        }
        priority_queue<int,vector<int>,greater<int>>right_minheap;
        sum=0;
        for(int i=3*n-1;i>=n;i--){
            right_minheap.push(nums[i]);
            sum+=nums[i];
            if(right_minheap.size()>n){
                sum-=right_minheap.top();
                right_minheap.pop();
            }
            if(right_minheap.size()==n) right[i]=sum;
        }
        long long ans=LLONG_MAX;
        for(int i=n-1;i<2*n;i++){
            ans=min(ans,left[i]-right[i+1]);
        }
        return ans;
    }
};