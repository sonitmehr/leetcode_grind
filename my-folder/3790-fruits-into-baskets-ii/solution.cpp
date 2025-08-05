class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int cnt =0 ;
        for(int i = 0;i<n;i++){
            bool check = true;
            for(int j = 0;j < n;j++){
                if(fruits[i] <= baskets[j]){
                    baskets[j] = 0;
                    check = false;
                    break;
                }
            }
            if(check)cnt++;        
        }
    return cnt;
    }
};
