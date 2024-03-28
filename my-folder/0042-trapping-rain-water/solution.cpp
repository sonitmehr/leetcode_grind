class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0,right = n - 1;
        int maxLeft = height[left],maxRight = height[right];
        int ans = 0;
        while(left < right){

            if(maxLeft < maxRight){
                ans += min(maxLeft,maxRight) - height[left];
                left++;
            }
            else{
                ans += min(maxLeft,maxRight) - height[right];
                right --;
            }
            maxLeft = max(maxLeft,height[left]);
            maxRight = max(maxRight,height[right]);


        }
        return ans;
    }
};
