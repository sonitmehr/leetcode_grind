class Solution {
public:
    
    vector<pair<int,int>> twoSum(vector<int>& v, int target,int l) {
        
        int n = v.size();
        vector<pair<int,int>> p;
        int i =l, r = n-1;
        while(l < r){
            if(v[l] + v[r] == target){
                p.push_back({l,r});
                
                int L = v[l],R = v[r];
                
                while(l < r && v[l] == L){   
                        l++;
                }
                while(l < r && v[r] == R){
                        r--;
                }
                //l++;r--;
            
            }
            else if(v[l] + v[r] < target)l++;
            else r--;
        }
        return p; 
            
    }
    
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        
        vector<vector<int>> ans;
        vector<pair<int,int>> p;
        int curr;
        for(int i= 0;i<n;i++){
            if(v[i] == curr)continue;
            curr = v[i];
            p = twoSum(v,curr*-1,i+1);
            if(p.size()){
                for(int j = 0;j<p.size();j++){
                    
                    vector<int> pushIn = {v[i],v[p[j].second],v[p[j].first]};
                    
                    //if(ans.size() > 0 && pushIn == ans.back())continue;
                    
                    
                    ans.push_back(pushIn);
                    
                }
                

            }
            
            
        }
        return ans;
    }
};
