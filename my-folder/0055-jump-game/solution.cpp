class Solution {
public:



    bool canJump(vector<int>& v) {
        int n = v.size();
        int maxReach = 0;

        for(int i=0;i<n;i++){
            
            if(i > maxReach)return false;

            maxReach = max(maxReach,i + v[i]);
        }
        if(maxReach >= n -1)return true;
        return false;
    }
};
