class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int n = v.size();

        int i = 0,j = 0;
        int temp = k;
        int maxi = 0;
        
        while(j < n){
            if(temp < 0){
                if(v[i] == 0){
                    temp++;
                }
                i++;
            }
            
            if(v[j] == 0){
                temp--;
            }
            j++;

            if(temp >= 0){
                maxi = max(maxi,j - i);
            }
        }
        // if(temp >=0){

        //     maxi = max(maxi,j - i);
        // }
        return maxi;
    }
};
