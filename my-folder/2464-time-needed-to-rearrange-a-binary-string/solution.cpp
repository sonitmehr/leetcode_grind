class Solution {
public:
    // function taken from some website. not mine.
    void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{
    // Get the first occurrence
    size_t pos = data.find(toSearch);
    // Repeat till end is reached
    while( pos != std::string::npos)
    {
        // Replace this occurrence of Sub String
        data.replace(pos, toSearch.size(), replaceStr);
        // Get the next occurrence from the current position
        pos =data.find(toSearch, pos + replaceStr.size());
    }
}
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        
        if(s.find("01")==string::npos)return 0;
        
        findAndReplaceAll(s,"01","10");
        
        return 1 + secondsToRemoveOccurrences(s);
        
        
    }
};
