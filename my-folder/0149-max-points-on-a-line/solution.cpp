class Solution {
public:
    struct Node{
        float slope;
        float x1,x2,y1,y2;
    };
    struct Node *newNode(float slope,float x1,float x2,float y2,float y1){
        Node * n = new Node();
        n->slope = slope;
        n->x1 = x1;
        n->x2 = x2;
        n->y1 = y1;
        n->y2 = y2;
        return n;
    }
    int maxPoints(vector<vector<int>>& v) {
        int n = v.size();
        //map<float,int> m;
        if(n<=2)return n;
        int maxi = 2;
        for(int i = 0;i<n-1;i++){
            for(int j = i + 1;j<n;j++){
                int cnt = 2;
                for(int k = 0;k<n;k++){
                    if(k==i || k == j)continue;
                    int y2 = (int)v[i][1]; // i
                    int x2 = (int)v[i][0];

                    int y1 = (int)v[j][1]; // j
                    int x1 = (int)v[j][0];
                    
                    int x3 = (int)v[k][0]; // k
                    int y3 = (int)v[k][1];
                    //              (i - j)*(j - k)
                    int  check1 = (y2 - y1)*(x1 - x3);
                    //             (j - k)*(i - j)
                    int check2 = (y1 - y3)*(x2-x1);
                    //cout << check1 << " " << check2 << endl;
                    if(check1 == check2)cnt++;
                    
                }
                maxi = max(maxi,cnt);
                
            }
        }
        return maxi;
        
    }
};
