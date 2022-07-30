class Solution {
public:
    
    vector<int> f(string s){
        vector<int> v(26,0);
        int n = s.size();
        
        for(int i = 0;i<n;i++){
            v[s[i] - 'a']++;
        }
        return v;
    }
    
    vector<string> wordSubsets(vector<string>& s1, vector<string>& s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        vector<int> vmax(26,0);
        for(auto x:s2){
            vector<int> temp=f(x);
            for(int i=0;i<26;i++){
                vmax[i]=max(vmax[i],temp[i]);
            }
        }
        
        for(int i=0;i<26;i++){
            cout<<i+ 'a' <<" "<<vmax[i]<<endl;
        }
        cout<<endl;
        
       // vector<int> occ(26,0);
        vector<int> occ2;
        
        vector<string> ans; 
        for(auto i : s1){
            occ2 = f(i);
            int flag = 1;
            for(int j =0; j < 26; j++){
                if(vmax[j] > occ2[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag)ans.push_back(i);
            //occ2.clear();
        }
        return ans;
    }
};
