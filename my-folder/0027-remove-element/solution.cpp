class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i= 0,j = nums.size()-1;        
        if(nums.size()==1 && nums[0] == val){            
            return NULL;
        }else if(nums.size()==1 && nums[0] != val){
            return 1;
        }
        while(i<=j){
            if(nums[i]!=val){
                i++;
            }
            else if(nums[i]==val && nums[j]==val){
                j--;                
            }
            else if(nums[i]==val && nums[j]!=val){
                nums[i] = nums[j];
                j--;
            }
            
        }if(i == 0){
            return NULL;
        }
        return i;
        
    }
};
