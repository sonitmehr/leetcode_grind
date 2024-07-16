class Solution {
public:

    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,-1,1};
    
    bool check(int i,int j,int n,int m){
        if(i < 0 || j < 0 || i >= n || j >= m)return false;
        return true;
    }

    bool solve(int i,int j,int k,vector<vector<char>>& mat,string word){
        int n = mat.size();
        int m = mat[0].size();
        if(k == word.size()){
            return true;
        }

        for(int ii = 0;ii<=3;ii++){
            int x = i + dx[ii];           
            int y = j + dy[ii];           
            
            if(check(x,y,n,m) && mat[x][y] == word[k]){
                char t = mat[x][y];
                // cout << t << endl;
                mat[x][y] = '*';
                if(solve(x,y,k +1,mat,word)==true)return true;
                mat[x][y] = t;
            }
        }
        return false;

    }

    bool exist(vector<vector<char>>& mat, string word) {
            int n = mat.size();
            int m = mat[0].size();
            bool ans = false;
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(mat[i][j] == word[0]){
                        char t = mat[i][j];
                        mat[i][j] = '*';
                        // cout <<i << " " << j <<endl;
                        ans |= solve(i,j,1,mat,word);
                        mat[i][j] = t;
                    }
                }
            }
            return ans;
    }
};
