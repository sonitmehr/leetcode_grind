class Solution {
public:
    vector<int> fen;
    void update(int i,int add){
        while(i <= fen.size()){
            fen[i] += add;
            i = i + (i & (-i));
        }

    }

    int sum(int i){
        int s = 0;
        while(i > 0){
            s += fen[i];
            i = i - (i & (-i));

        }
        return s;
    }
    vector<int> countSmaller(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n);
        fen.resize(20005,0);
        for(int i = 0;i<n;i++)v[i] += 10001;

        for(int i = n-1;i>=0;i--){
            ans[i] = sum(v[i] -1 );
            update(v[i],1);
        }
        
        return ans;
            
        

    }
};
