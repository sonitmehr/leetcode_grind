class NumArray {
public:
    vector<int>m;
    NumArray(vector<int>& nums) {
        int s = 0;
        m.resize(nums.size()+1);
        for(int i = 0;i<nums.size();i++){
            s+=nums[i];
            m[i+1] = s;
        }
        
    }            
    int sumRange(int left, int right) {
        return m[right+1]- m[left];
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
