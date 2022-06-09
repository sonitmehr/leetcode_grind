class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> a = numbers;
        int n = numbers.size();
        
        int i = 0,j=n-1;
        while(i<j){
            int sum1 = numbers[i] + numbers[j];
            if(sum1 == target){
                
                return {i+1,j+1}; 
            }
            else if(sum1 < target){
                i++;
            }
            else j--;
        }
        return {};
        
    }
};
