class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        for(int i = 0;i<n;i++){
            m[s[i]] = i;
        }
        vector<int>v;
        int end= -1;
        int count = 0;
        for(int i = 0;i<n;i++){
            end = max(end,m[s[i]]);
            count++;
            if(i == end){
                v.push_back(count);
                count=0;
            }
            
        }
        return v;
    }
};
