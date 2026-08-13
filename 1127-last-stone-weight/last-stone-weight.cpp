class Solution{
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n=stones.size();
        for(int x:stones){
            pq.push(x);
        }
        while(pq.size()>1){
            int front_el=pq.top();
            pq.pop();
            int second_el=pq.top();
            pq.pop();
            pq.push(front_el - second_el);
        }return pq.top();
    }
};