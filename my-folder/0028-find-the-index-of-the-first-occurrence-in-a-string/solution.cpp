class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(),m = needle.size();
        int i = 0,j=0;
        if(needle == "")
            return 0;
        int found = haystack.find(needle);
        if(found!= string::npos){ // If found
            return found;
        }
        return -1;
        
    }
};
