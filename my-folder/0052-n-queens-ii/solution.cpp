class Solution {
public:
    
    int f(int col,vector<string> &a,vector<vector<string>> &ds, vector<int> &left,vector<int> &upperDiagnol,vector<int> &lowerDiagnol,int n){
        if(col == n){
            return 1;
        }
        // Iterating theough each row.
        int cnt = 0;
        for(int i =0;i<n;i++){
            // Checking Hash Table.
            if(left[i] == 0 && lowerDiagnol[i + col] == 0 && upperDiagnol[n - 1 + col - i] == 0){
                a[i][col] = 'Q';
                
                left[i] = 1;        // Checking if left side is not attacked by any other queen.
                                    // If left[i] == 0, means no queen has entered current row.
                lowerDiagnol[i + col] = 1;
                upperDiagnol[n-1 + col - i] = 1;
                
                // Call for next column recursively.
                cnt += f(col + 1,a,ds,left,upperDiagnol,lowerDiagnol,n);
                
                a[i][col] = '.';  // Back track to previous condition.
                left[i] = 0;
                lowerDiagnol[i + col] = 0;
                upperDiagnol[n-1 + col -i] = 0;
                
                
                
            }
            
        }
        return cnt;
        
        
    }
    
    int totalNQueens(int n) {
        vector<vector<string>> ds;
        vector<string> board(n);
        string s(n,'.');
        
        for(int i = 0;i<n;i++){
            board[i] = s;
        }
        
        vector<int> left(n + 1,0), upperDiagnol(2*n - 1,0),lowerDiagnol(2*n-1,0);
        
        int l = f(0,board,ds,left,upperDiagnol,lowerDiagnol,n);
        
        return l;
    }
};
