class Solution {
public:

    static bool customComparison(vector<int> &a, vector<int> &b)
    {
        
        if (a[1] == b[1]) 
            return a[0] < b[0]; 
        return a[1] > b[1];   
    }


    int numberOfPairs(vector<vector<int>>& p) {
        
        sort(p.begin(),p.end(),customComparison);

        for(auto &i : p){
            cout << i[0] << " " << i[1] << endl;
        }
        int ans = 0;
        int n = p.size();
        for(int i= 0;i<n;i++){
            int minX = 1e9, minY = p[i][1];
            for(int j = i+1;j<n;j++){
                int x = p[j][0],y = p[j][1];
                if(x < minX && x >= p[i][0]){
                    // cout << "Ans : " << endl;
                    // cout << p[i][0] << " " << p[i][1] << endl;
                    // cout << p[j][0] << " " << p[j][1] << endl;
                    minX = x;
                    // cout << minX << endl;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
