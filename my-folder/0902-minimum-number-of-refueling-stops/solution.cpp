class Solution {
public:
    int minRefuelStops(int t, int s, vector<vector<int>>& v) {
        priority_queue<int> q;
        int mini=0;
        int curr = 0;
        int totalStations = size(v);
        while(s<t)
        {
            while(curr < totalStations and v[curr][0]<=s)
            {
                q.push(v[curr][1]);
                curr++;
            }
            if(q.empty())
                return -1;
            s+=q.top();
            q.pop();
            mini++;
        }
        return mini;
    }
};
