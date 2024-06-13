#define pi pair<int,int>
class Solution {
public:

    bool check( int i,int j,int n,int m){
        if(i < 0 || j < 0 || i >= n || j >= m)return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(),m = image[0].size();
        queue<pi> q;if(color == image[sr][sc])return image;
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,1,-1};
        int initialColor = image[sr][sc];
        q.push({sr,sc});
        image[sr][sc] = color;
        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int currX = top.first;
            int currY = top.second;

           

                // cout << currX << " : " << currY << endl;
            for(int k = 0;k<=3;k++){
                int newX = currX + dx[k];
                int newY = currY + dy[k];
                if(check(newX,newY,n,m) && image[newX][newY] == initialColor){
                // cout << newX << " " << newY << endl;
                    q.push({newX,newY});
                    image[newX][newY] = color;
                }
            }

        }
        return image;

    }
};
