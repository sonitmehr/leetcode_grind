class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        
        //Set prefix as the first element.
        string prefix = strs[0];
        
        for(int i =1;i<strs.size();i++){
            size_t found = strs[i].find(prefix);
            while(found != 0){
                prefix = prefix.substr(0,prefix.size()-1);
                found = strs[i].find(prefix);
            }
            
        }
        return prefix;
    }
};
