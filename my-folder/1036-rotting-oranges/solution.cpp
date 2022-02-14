int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
        //we will start from all the rotten oranges at the same time,
        //so we will push all of them into the queue.            
                if(grid[i][j]==2){
                    q.push({i,j});
                    
        // time taken to reach a rotten orage from a rotten orage 
        //i.e., form itself to itself is 0 .           
                    grid[i][j]=0;
                }
            }
        }
        
        // we will work on negative values on minutes to use this value as visited
		// as grid dosent contain any negative values.
        
        int minutes=-1;
        int ans=0;
        while(!q.empty()){
            int len=q.size();
            
        // end of this for loop indicated 1 minutes elapsed .        
            for(int k=0;k<len;k++){
                int ii=q.front().first;
                int jj=q.front().second;
                q.pop();
                
        // checking all the four direction from the rotten orange .         
                for(int i=0;i<4;i++){  
                int row=ii+dx[i];
                int col=jj+dy[i];
                if(row<0 or col<0 or col>m-1 or row>n-1 or grid[row][col]<=0)
                    continue;
                grid[row][col]=minutes;
                q.push({row,col});
                ans=min(ans,grid[row][col]);
            }
            }
            minutes--;
        }
        
        
        // checking if there any oranges left which is not rotten
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        return -1*ans;
    }
};
