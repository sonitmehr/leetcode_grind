
class Node{
    public:
    
    int node;
    int par;
    int val;
    int time;

    Node(int node,int par,int val,int time){
        this->node = node;
        this->par = par;
        this->val = val;
        this->time = time;
    }
};

class Solution {
public:

    bool dfs(int i,int par,int t,vector<int> adj[],vector<int> &path){
        if(i == 0)return true;

        for(auto &adjNode : adj[i]){
            if(adjNode != par){
                path.push_back(adjNode);
                if(dfs(adjNode,i,t+ 1,adj,path))return true;
                path.pop_back();
            }
        }
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size();
        const int sz = 1e5 + 7;
        vector<int> adj[sz];

        for(auto &i : edges){
            int a = i[0],b = i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> time(n + 1,-1);

        time[bob] = 0;
        vector<int> path;
        path.push_back(bob);
        dfs(bob,-1,0,adj,path);
        // for(auto &i : path)cout << i << " " ;
        cout << endl;
        for(int i = 0;i<path.size();i++){
            time[path[i]] = i;
        }
        queue<Node> q;
        q.push(Node(0,-1,0,0));
        int ans =  -1e9;
        while(!q.empty()){
            auto p = q.front();

            int node = p.node;
            int val = p.val;
            int par = p.par;
            int t = p.time;

            q.pop();

            if(t == time[node]){
                val += amount[node]/2;
            }
            else if(time[node] == -1){
                val += amount[node];
            }
            else if(t > time[node]){
                
            }
            else{
                val += amount[node];
            }
            int cnt = 0;
            // cout << node << " " << t << " " << val << endl;
             for(auto &adjNode : adj[node]){
                if(adjNode != par){
                    cnt ++;
                    q.push(Node(adjNode,node,val,t + 1));
                }
            }
            if(cnt == 0){
                ans = max(ans,val);
            }
        }
        // for(int i = 0;i<n + 1;i++) {
        //     cout << i << " " << time[i] << endl;
        // }
        return ans;





    }
};
