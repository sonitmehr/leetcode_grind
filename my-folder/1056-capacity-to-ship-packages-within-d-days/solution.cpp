class Solution {
public:
    int shipWithinDays(vector<int>& v, int days) {
        int n = v.size();
        int i = *max_element(v.begin(),v.end()),j = 1e9;
        
        while(i <= j){
            int mid = i + (j - i)/2;
        cout <<i << " " << j << " "  << mid ;
            int temp = mid;
            int d = 1;
            for(int i = 0;i<n;i++){
                if(temp >= v[i] && v[i] < mid){
                    
                    temp -= v[i];
                }
                else {
                    temp = mid - v[i];
                    d++;
                }
            }
            cout <<  " days :" << d <<endl;
            if(d <= days){
                j = mid - 1;
            }
            else i = mid +1;
        }
        return i;
    }
};
