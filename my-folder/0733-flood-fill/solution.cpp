class Solution {
public:

    bool check(int x,int y,int n,int m){
        if( x >= n || y >= m || x < 0 || y< 0)return false;
        return true;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(),m = image[0].size();

        queue<pair<int,int>> q;
        if(color == image[sr][sc])return image;
        q.push({sr,sc});
        int initialColor = image[sr][sc];
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int currX = curr.first;
            int currY = curr.second;
            int currColor = image[currX][currY];
            image[currX][currY] = color;

            for(int k = 0;k<4;k++){
                int newX = currX + dx[k];
                int newY = currY + dy[k];
                if(check(newX,newY,n,m) && image[newX][newY] == initialColor){
                    q.push({newX,newY});
                    image[newX][newY] = color;
                }

            }   

        }
        return image;
    }
};
