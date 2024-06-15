class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        for(int i = 0;i<V;i++){
            int from = i;
            for(int &j : graph[i]){
                int to = j;
                adj[to].push_back(from);
            }
        }
        vector<int> ans;
	    vector<int> inDeg(V,0);
	   
	    queue<int> q;
	       
	   for(int i = 0;i<V;i++){
	       for(int &node : adj[i]){
	           inDeg[node] ++;
	       }
	   }
	   
	   for(int i = 0;i<V;i++){
	       if(inDeg[i] == 0)q.push(i);
	   }
	   
	   
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(int &k : adj[node]){
	            inDeg[k]--;
	            if(inDeg[k] == 0)q.push(k);
	            
	        }
	        
	    }
        sort(ans.begin(),ans.end());
	    return ans;
    }
};
