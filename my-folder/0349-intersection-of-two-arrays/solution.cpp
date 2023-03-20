class Solution {
public:
    vector<int> intersection(vector<int>& v1, vector<int>& v2) {
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        // 4 4 8 9 9
        // 4 5 9
        vector<int> ans;
        int i =0,j = 0;
        while( i < v1.size() && j < v2.size()){
            if(v1[i] < v2[j]){
                i++;
            }
            else if(v2[j] < v1[i]){
                j++;
            }
            else{
                if(ans.size() == 0)ans.push_back(v1[i]);
                else if(ans.size() > 0 && ans.back() != v1[i])ans.push_back(v1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
