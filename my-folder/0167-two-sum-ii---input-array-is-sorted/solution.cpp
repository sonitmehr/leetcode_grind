class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0,j = n-1;
        while(i<j){
            if(numbers[i]+numbers[j] > target){
                j--;
            }else if(numbers[i]+numbers[j] < target){
                i++;
            }else if(numbers[i]+numbers[j] == target){
                numbers.erase(numbers.begin(),numbers.end());
                numbers.push_back(i+1);
                numbers.push_back(j+1);
                break;
            }
        }return numbers;
    }

   
    
};
