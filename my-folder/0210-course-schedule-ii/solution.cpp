class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(int i = 0;i<prerequisites.size();i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[a].push_back(b);
            // adj[b].push_back(a);
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
    vector<int> empty;
        reverse(ans.begin(),ans.end());
	    return ans.size() == V ? ans : empty;
    }
};
