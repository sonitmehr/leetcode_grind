# define ll long long
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        //sort(time.begin(),time.end());
        
        ll l = 0,r=pow(10,14);
        ll ans = r;
        
        while(l<r){
            ll count  = 0;
            ll mid = l + (r-l)/2;
            // Counting number of buses.
            for(int i = 0;i<time.size();i++){
                count+=(mid/time[i]);
            }
            if(count>=totalTrips){
                ans = min(ans,mid);
                r =mid;
            }else{
                l =mid+1;
            }
                
            
        }
        return ans;
        
    }
};
