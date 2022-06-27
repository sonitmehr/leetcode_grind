class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int goal = n - 1;
        
        for(int i = n-1;i>=0;i--){
            // when goal is reachable from some i;
            if(i + nums[i] >= goal){
                // Change goal closer to i = 0
                goal = min(goal,i);
            }
        }
        if(goal == 1-1)return true;
        return false;
    }
};
