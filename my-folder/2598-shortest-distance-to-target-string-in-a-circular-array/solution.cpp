class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        vector<int> ind;
        
        for(int i = 0;i<n;i++){
            if(words[i] == target){
                ind.push_back(i);
            }
        }
        if(ind.size() == 0)return -1;
        int mini = 1e9;
        for(int i= 0;i<ind.size();i++){
            if(ind[i] > startIndex){
                mini = min({mini,ind[i] - startIndex,n - ind[i] + startIndex});
            }
            else{
                mini = min({mini,startIndex - ind[i],n - startIndex + ind[i]});
            }
        }
        
        return mini;
        
    }
};
