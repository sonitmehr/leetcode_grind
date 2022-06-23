class NumArray {
public:
    vector<int> v;
    int n1;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        n1= n;
        v.push_back(0);
        v.push_back(nums[0]);
        for(int i =1 ;i<n;i++){
            nums[i] += nums[i-1];
            v.push_back(nums[i]);
        }
        
    }
    
    int sumRange(int left, int right) {
        
        return v[right+1] - v[left];
    }
};
// [0,2, -2, 1, -4, -2, -3]

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
