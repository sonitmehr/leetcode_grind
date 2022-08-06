class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        // PnC problem. Try again. Maybe solve more math hard.
        int val = minutesToTest/minutesToDie;
        if(buckets ==1 )return 0;
        int cnt = 0;
        buckets--;
        while(buckets > 0){
            buckets = buckets/(val+1);
            cnt++;
        }
        return cnt;
        
        
    }
};
