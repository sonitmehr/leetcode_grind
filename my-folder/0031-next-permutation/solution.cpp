class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());
        // return nums;
        int n = nums.size();
        int index = - 1;
        for(int i = n - 1;i >= 1; i--){
            if(nums[i - 1] < nums[i]){
                index = i - 1;
                break;
            }
        }
        cout << index << endl;
        if(index != -1){
            for(int i = n - 1;i>= 1;i--){
                if(nums[i] > nums[index]){
                    
                    swap(nums[i],nums[index]);
                    cout <<i << endl;
                    reverse(nums.begin() + index + 1,nums.end());
                    break;
                }
            }
        }
        else{
            reverse(nums.begin(),nums.end());
        }
    }
};
