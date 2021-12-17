class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> s;
        int n = nums.size();
        
        if(n == 0) {
            return s;
        }
        if(n == 1){
            return {to_string(nums[0])};
        }
        int start = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1] + 1 != nums[i]){
                if(start == nums[i-1]){
                    s.push_back(to_string(start));           
                }else{
                    s.push_back(to_string(start)+"->"+to_string(nums[i-1]));
                }
                start = nums[i];
                
            }
            
            
        }
        if(nums[n-1] == start){
            s.push_back(to_string(start));
        }
        else{ 
            
             s.push_back(to_string(start) + "->" + to_string(nums[n-1]));
        }
        return s;
    }
};
