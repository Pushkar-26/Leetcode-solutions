class Solution {
public:
    typedef pair<double,pair<int,int>> p;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr,int k) {
        int n=arr.size();
        priority_queue<p> pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double fraction=(double)arr[i]/arr[j];
                pq.push({fraction,{arr[i],arr[j]}});
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return {pq.top().second.first,pq.top().second.second};
    }
};