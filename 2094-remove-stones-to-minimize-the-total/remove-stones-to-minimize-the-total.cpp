class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int x:piles)pq.push(x);
        while(k--){
            int curr=pq.top();
            pq.pop();
            curr-=curr/2;
            pq.push(curr);
        }
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};