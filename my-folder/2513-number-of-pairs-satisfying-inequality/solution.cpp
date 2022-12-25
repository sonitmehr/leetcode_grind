class Solution {
public:
    void update(vector<int>&fen,int i,int add){
        int N = fen.size();
        while(i <= N){
            fen[i] += add;
            i = i + (i & (-i));
        }

    }

    long long sum(vector<int>&fen,int i){
        int s = 0;
        int  N = fen.size();
        while(i > 0){
            s += fen[i];
            i = i - (i & (-i));

        }
        return s;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> fen(200005,0);
        int n = nums1.size();
        for(int i = 0;i<n;i++){
            nums1[i] -= nums2[i];
            nums1[i] += 100001;
        }
        long long ans = 0;
        for(int i = 0;i<n;i++){
            ans += sum(fen,nums1[i] + diff);
            update(fen,nums1[i],1);
        }
        return ans;
    }
};
