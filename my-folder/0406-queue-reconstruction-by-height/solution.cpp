class Solution {
public:
    
    void print(vector<vector<int>>& v){
        for(int i = 0;i<v.size();i++){
            cout << "[";
            for(int j = 0;j < 2;j++){
                cout << v[i][j] <<  ", ";
            }cout << "],";
        }
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& v) {
        int n = v.size();
        
        sort(v.begin(),v.end());
        vector<vector<int>> ans(n,vector<int>(2,-1));
        
        //[5,0],[7,0],[4,4],[5,2],[6,1],[7,1]
        int ptr = 0;
        for(int i = 0;i<n;i++){
            int cnt = v[i][1];
            int val = 0;
            for(int j = 0;j<n;j++){
                if(ans[j][0] == -1 && cnt == val){
                    ans[j][0] = v[i][0];
                    ans[j][1] = v[i][1];
                    break;
                }
                else if(ans[j][0]== -1 || ans[j][0] >= v[i][0])val++;
                
            }
            
           // print(v);
            //cout << "cnt  =" << cnt << " val = " <<val;
            //cout << endl;
        }
        return ans;
    }
};
