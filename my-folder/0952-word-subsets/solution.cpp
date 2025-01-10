class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();

        vector<unordered_map<char,int>> vec1(n);
        unordered_map<char,int> mp2;

        for(int i = 0;i<n;i++){
            for(char &c : words1[i]){
                vec1[i][c]++;
            }
        }
        for(int i = 0;i<m;i++){
        unordered_map<char,int> temp;

            for(char &c : words2[i]){
                // mp2[c]++;
                temp[c]++;
                mp2[c] = max(mp2[c],temp[c]);
            }
        }
        int ind = 0;
        vector<string> ans;
        for(auto &mp1 : vec1){
            bool check = true;
            // cout << words1[ind] << endl;

            for(auto &i : mp2){
                // cout << i.first << " " << i.second << endl;
                // cout << mp1[i.first] << " " << mp2[i.first] << endl;
                if(mp1[i.first] < mp2[i.first]){
                    check = false;
                    break;
                }
            }
            // cout << "check : " << check << endl; 
            if(check){
                ans.push_back(words1[ind]);
            }
            ind ++;
        }
        return ans;
    }
};
