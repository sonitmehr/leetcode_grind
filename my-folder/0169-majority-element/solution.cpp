class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int ele = -1,eleCnt = 0;

        for(int i = 0;i<n;i++){
            int curr = nums[i];

            if(eleCnt == 0){
                eleCnt = 1;
                ele = nums[i];
            }
            else if(ele == nums[i]){
                eleCnt++;
            }
            else {
                eleCnt--;
            }

        }
        return ele;
    }
};
