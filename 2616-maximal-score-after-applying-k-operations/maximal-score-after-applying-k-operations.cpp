class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        long long score=0;
        int n=nums.size();
        for(int x:nums){
            pq.push(x);
        }while(k!=0){
            int curr=pq.top();
            pq.pop();
            score+=curr;
            k--;
            pq.push(ceil((curr+2)/3));
        }return score;
    }
};