class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int>mp;
        for(int x:nums){
            mp[x]++;
        }priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            int freq=it.second;
            int num=it.first;
            pq.push({freq,num});
        }
        vector<int>ans;
        while(k>0){
            auto p=pq.top();
            pq.pop();
            ans.push_back(p.second);
            k--;
        }return ans;
    }
};