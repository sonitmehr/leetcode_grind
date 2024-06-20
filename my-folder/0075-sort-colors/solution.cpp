class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();

        int one = 0,two = 0,zero= 0;

        for(int i = 0;i<n;i++){
            int val =arr[i];
            if(val == 0)zero++;
            else if(val == 1)one++;
            else if(val == 2)two++;
        }

        for(int i = 0;i<n;i++){
            if(zero > 0){
                arr[i] = 0;
                zero--;
            }
            else if(one > 0){
                arr[i] = 1;
                one--;
            }
            else if(two > 0){
                arr[i] =2;

two--;            }
        }
    }
};
