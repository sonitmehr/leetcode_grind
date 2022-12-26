class NumArray {
public:
    vector<int> fen;
    vector<int> nums;
    int sum(int i){
        int s = 0;
        while(i > 0){
            s += fen[i];
            i = i - (i & (-i));
        }
        return s;
    }
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        fen.resize(n+10,0);


        for(int i = 0;i<n;i++){
            //fen[i] = sum(nums[i]);
            updateAfterI(i + 1,nums[i]);
        }

    }
    
    void update(int i, int val) {
        int diff = val - nums[i];
        nums[i] = val;
        updateAfterI(i + 1,diff);
    }
    void updateAfterI(int i, int val) {
        while(i <= fen.size()){
            fen[i] += val;
            i = i + (i & (-i));
        }
    }
    
    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
