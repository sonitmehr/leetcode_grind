class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        int sing = nums[0];
        
        for(int i = 0;i<n+1;i++){
            temp.push_back(i);            
        }int sing1 = temp[0];
        for(int i = 1;i<n+1;i++){
            sing1 = sing1^temp[i];
        }
        for(int i = 1;i<n;i++){
            sing = sing^nums[i];
        }
        return sing^sing1;
    }
};
