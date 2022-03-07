class Solution {
public:// s.find() != string::npos ->  matches found
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0)return "";
        int flag = 0;
        string prefix = strs[0];
        for(int i = 1;i<n;i++){
            int found = strs[i].find(prefix);
            while(found!=0){
                prefix = prefix.substr(0,prefix.size()-1);
                found = strs[i].find(prefix);
                if(prefix.size()==0){
                    flag =1;
                    break;
                }
            }
            
        }
        if(flag==1)return "";
        return prefix;
    }
};
