#define pii pair<int,pair<int,int>>
class Solution {
public:
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> ans;
        vector<pii> vtr;
        priority_queue <pii, vector<pii>, greater<pii> > pq;
        for(int i= 0;i<n;i++){
            vtr.push_back({tasks[i][0],{tasks[i][1],i}});
        }
      //  int curr_time = vtr[0].first;
        sort(vtr.begin(),vtr.end());
        int ptr = 0;
        int i = 0;
        long long curr_time = vtr[i].first;
        while(i < n|| !pq.empty()){
            while(i < n && curr_time >= vtr[i].first){
                pq.push({vtr[i].second.first,{vtr[i].second.second,vtr[i].first}});
                ++i;
            }
            curr_time = curr_time += pq.top().first;
            ans.push_back(pq.top().second.first);
            pq.pop();
            if( i < n && curr_time < vtr[i].first && pq.empty())
                    curr_time = vtr[i].first;
                
        }
        return ans;

    }
};
