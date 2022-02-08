class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        if(n == 1){
            numbers.clear();
            numbers.push_back(1);
            return numbers;
        
        }
        int i = 0,j=n-1;
        while(i<j){
            //int diff = target - numbers[i];
            if(numbers[i]+numbers[j] == target){
                numbers.clear();
                numbers.push_back(i+1);
                numbers.push_back(j+1);
                break;
            }
            else if(numbers[i] + numbers[j] > target){
                j--;
            }else{
                i++;
            }
        }
        
        return numbers;
        
    }
};
