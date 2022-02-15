class Solution {
public:
    
    int minimumOperations(vector<int>& nums) {
        int freqEven[100001] = {0};
        int freqOdd[100001] = {0};
        int maxInt = nums[0], n =nums.size();
        for(int i = 0;i<nums.size();i++){
            if(i%2==0){
                freqEven[nums[i]]++;
                
            }else{
                freqOdd[nums[i]]++;
            }
            maxInt = max(maxInt,nums[i]);
        }
       // maxInt = *max_element(nums, nums + nums.size());
        int firstMaxEveni = 0, freqFirstMaxEven = 0;
        int firstMaxOddi = 0, freqFirstMaxOdd = 0;
        
        int secondMaxEveni = 0, freqSecondMaxEven = 0;
        int secondMaxOddi = 0, freqSecondMaxOdd = 0;
        
        for(int i = 1;i<=maxInt;i++){
            if(freqEven[i] >= freqFirstMaxEven){
                secondMaxEveni = firstMaxEveni;
                freqSecondMaxEven = freqFirstMaxEven;
                
                freqFirstMaxEven = freqEven[i];
                firstMaxEveni = i;
            }
            else if(freqEven[i] > freqSecondMaxEven && freqEven[i] <= freqFirstMaxEven){
                freqSecondMaxEven = freqEven[i];
                secondMaxEveni = i;
            }
            
            if(freqOdd[i] >= freqFirstMaxOdd){
                secondMaxOddi = firstMaxOddi;
                freqSecondMaxOdd = freqFirstMaxOdd;
                
                freqFirstMaxOdd = freqOdd[i];
                firstMaxOddi = i;
            }
            else if(freqOdd[i] > freqSecondMaxOdd && freqOdd[i] <= freqFirstMaxOdd){
                freqSecondMaxOdd = freqOdd[i];
                secondMaxOddi = i;
            }
        }
        if(firstMaxEveni != firstMaxOddi)return nums.size() - freqFirstMaxEven -freqFirstMaxOdd;
        else{
            return min(n - freqFirstMaxEven - freqSecondMaxOdd,n - freqSecondMaxEven - freqFirstMaxOdd );
        }
    }
        
};
