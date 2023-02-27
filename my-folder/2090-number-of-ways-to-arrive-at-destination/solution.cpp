#define pii pair<long long,long long>
#define pi pair<int,int>
#define ll long long 
class Solution {
public:
ll mod_add(ll a,ll b,ll M){

    return (a%M + b%M)%M;

}
    vector<pair<int,int>> adj[201];
    
    long long ways[201];
    int countPaths(int n, vector<vector<int>>& roads) {
        for(auto i :roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pii,vector<pii>,greater<pii>> q;
        long long ans = 0;
        int M = 1e9 + 7;
        vector<ll> dist(n,1e18);
        ways[0] = 1;
        dist[0] = 0;
        q.push({0,0});
        
        while(!q.empty()){
            auto p = q.top();
            q.pop();

            ll d = p.first;
            ll node = p.second;
            for(auto i : adj[node]){
                ll addDist = i.second;
                ll adjNode = i.first;
                 //cout << adjNode << " " << dist[adjNode] <<  " " << d + addDist<< endl;
                if(dist[adjNode] > d + addDist){
                   
                    dist[adjNode] = d + addDist;
                    q.push({dist[adjNode],adjNode});
                    ways[adjNode] = ways[node]%M;
                }
                else if(dist[adjNode] ==  d + addDist){
                    ways[adjNode] = mod_add(ways[adjNode],ways[node],M);
                    
                    //ways[adjNode]++;
                }
            }


        }
        //for(int i = 0;i<n;i++)cout << ways[i] << " " ;
        
        return ways[n - 1]%M;
    }
};
