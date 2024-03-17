class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0,j = height.size() -1;
        int sum = 0;
        int leftMax = height[i],rightMax = height[j];
        while(i < j){
            if(leftMax < rightMax){
                
                sum += min(leftMax,rightMax) - height[i];
                i++;
            }
            else{
                sum += min(leftMax,rightMax) - height[j];
                j--;
            }
            leftMax = max(leftMax,height[i]);
            rightMax = max(rightMax,height[j]);
        }
        return sum;
    }
};
