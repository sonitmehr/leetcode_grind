#define pii pair<int,pair<int,int>>
class Solution {
public:
int vis[101];
vector<pair<int,int>> adj[101];
bool valid(int i, int j,int n,int m){
        if(i < 0 || i >=n || j < 0 || j>=m)return false;
        return true;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        for(auto i : flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> distArray(n,1e9); 
        //priority_queue<pii,vector<pii>,greater<pii>> q;
        queue<pii> q;
        int mini = 1e9;
        q.push({0,{src,k}});
        distArray[src] = 0;
        //int mini = 1e9;
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int dist = p.first;
            int node = p.second.first;
            int currK = p.second.second;
            //cout << node << " " << dist << " " <<currK <<endl;
            // if(node == dst && currK >= 0){
            //     mini = min(mini,dist);
            // }
            if(currK < 0)break;
           

            for(auto i : adj[node]){
                int addDist = i.second;
                int adjNode = i.first;
                if(currK >= 0 && distArray[adjNode] > (dist + addDist)){
                    distArray[adjNode] = dist + addDist;
                    q.push({dist + addDist,{adjNode,currK -1}});
                }
            }
            
        }
        if(distArray[dst] == 1e9)return -1;
        return distArray[dst];
    }
};
