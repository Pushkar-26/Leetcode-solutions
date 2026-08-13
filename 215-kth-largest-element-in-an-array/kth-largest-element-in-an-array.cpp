class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int n=nums.size();
        for(int x:nums)pq.push(x);
        while(k>1){
            pq.pop();
            k--;
        }return pq.top();
    }
};