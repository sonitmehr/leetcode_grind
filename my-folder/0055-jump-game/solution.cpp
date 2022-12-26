class Solution {
public:
    bool canJump(vector<int>& v) {
        int n = v.size();
        int reachable = v[0];
        if(n == 1)return true;
        if(reachable < 1)return false;
        for(int i = 1;i<n;i++){
            if(reachable >= i){
                reachable = max(reachable,i + v[i]);
            }
            else break;
        }
        if(reachable >= n -1 )return true;
        return false;
    }
};
