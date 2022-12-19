class Solution {
public:
    pair<int,int> f(vector<int> & odd,int one,int two){
        vector<int> p;
        for(auto i : odd){
            if(i !=one   && i!= two){
                p.push_back(i);
            }
        }
        pair<int,int> pr = make_pair(p[0],p[1]);
        return pr;
        
    }
    
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> adj[n+1];// = {vector<int>};
        set<pair<int,int>> st;
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            st.insert({i[0],i[1]});
            st.insert({i[1],i[0]});
        }
        
        vector<int> odd;
        for(int i = 1;i<=n;i++){
            
            if(adj[i].size()%2 == 1){
                odd.push_back(i);
            }
        }
        if(odd.size() == 0)return true;
        if(odd.size() == 1)return false;
        if(odd.size() == 3)return false;
        if(odd.size() > 4)return false;
        if(odd.size() == 2){
           for(int i = 1;i<=n;i++){
                pair<int,int> p1 = {odd[0],i};
                pair<int,int> p2 = {odd[1],i};
               
               if(st.find(p1) == st.end() && st.find(p2) == st.end())return true;
               
           }
            return false;
        }
        
        for(int i = 1;i<4;i++){
            pair<int,int> p1 = {odd[0],odd[i]};
            pair<int,int> p2 = f(odd,odd[0],odd[i]);
            
            if(st.find(p1) == st.end() && st.find(p2) == st.end())return true;
            
        }
        
        return false;
    }
};
