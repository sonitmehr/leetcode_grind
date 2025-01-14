class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
    int n = A.size();
    vector<int> ans;
        for(int i = 0;i<n;i++){
            int a = A[i],b = B[i];
            mp1[a]++;
            mp2[b]++;
            int cnt = 0;
            for(auto &j : mp1){
                if(mp1[j.first] == mp2[j.first])cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;

    }
};
