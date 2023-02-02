class Solution {
public:
    int dp[2002][2002];
    unordered_map<int,int> m;
    bool f(int i,int k,vector<int> &a ){
        int check = a[i] + k;
        if(i == a.size() - 1)return true;
        if(i >= a.size())return false;
        if(dp[i][k] != -1)return dp[i][k];
        int pos1 = a[i] + (k - 1);
        int pos2 = a[i] + k;
        int pos3 = a[i] + (k + 1);
        bool one = false,two = false,three = false;
        // cout << i + 1 << " " <<  k << " ";
        // cout << pos1 << " " << pos2 << " " << pos3 << endl;
        if(m[pos1] > i)one = f(m[pos1],k -1,a);
        if(m[pos2] > i)two = f(m[pos2],k,a);
        if(m[pos3] > i)three = f(m[pos3],k +1,a);

        return dp[i][k] = one | two | three;
    }

    bool canCross(vector<int>& stones) {
        unordered_map<int,int> m;
        for(int i =0;i<2002;i++){
            memset(dp[i],-1,sizeof(dp[i]));
        }
        int n = stones.size();
        if(stones[1] != 1)return false;
        for(int i = 0;i<n;i++){
            m[stones[i]] = i;
        }
        this->m=m;
        return f(1,1,stones);
    }
};
