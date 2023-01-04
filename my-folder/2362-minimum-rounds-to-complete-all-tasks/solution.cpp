class Solution {
public:
// 4 -> 2 + 2
// [1,2] 
    int minimumRounds(vector<int>& v) {
        int n = v.size();
        priority_queue<int> q;
        map<int,int> m;
        for(int i =0;i<n;i++){
            m[v[i]]++;
        }
        for(auto i : m){
            q.push(i.second);
            if(i.second == 1)return -1;
        }
        int ans = 0;
        while(!q.empty()){
            int p = q.top();
            q.pop();
            if(p > 3){
                q.push(p - 3);
            }
            ans++;
        }
        return ans;
    }
};
