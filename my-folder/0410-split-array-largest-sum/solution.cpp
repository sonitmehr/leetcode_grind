class Solution {
public:
    int splitArray(vector<int>& v, int k) {
        int n = v.size();
        int sum = 0;
        for(auto &i : v)sum += i;
        int i = *max_element(v.begin(),v.end()),j = sum;

        while(i <= j){
            int mid = (i + j)/2;

            int cnt = 1,currSum = 0;
            for(int i = 0;i<n;i++){
                if(currSum + v[i] <= mid){
                    currSum +=v[i];
                }
                else{
                    currSum = v[i];
                    cnt++;
                }
            }
            cout << mid << " " << cnt << endl;

            if(cnt <= k){
                j = mid - 1;
            }
            else i = mid + 1;
        }

        return i;
    }
    
};
