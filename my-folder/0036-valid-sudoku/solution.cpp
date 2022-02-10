class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        
        for(int i = 0;i<9;i++){            
            for(int j = 0;j<9;j++){
                
                if(board[i][j] !='.'){
                    string hash_row = "Row: " + to_string(i) + to_string(board[i][j] - '0');
                    string hash_col = "Col: " + to_string(j) + to_string(board[i][j] - '0');
                    //Figure this last one out. Its fucking wierd.
                    string box = "Box: " + to_string(3*(i/3) + j/3) + to_string(board[i][j] - '0');
                    //Checking if they already exist. But what about the first iteration? 
                    if(seen.find(hash_row)!=seen.end() || seen.find(hash_col)!=seen.end() || seen.find(box)!= seen.end())return false;
                    seen.insert(hash_row);
                    seen.insert(hash_col);
                    seen.insert(box);
                }
                
            }
        }
        return true;
            
        
            
    }
};
