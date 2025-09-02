class Solution {
public:

    bool checkSquare(vector<int>& A,vector<int> &B,vector<int> &C){
        // A is upper left to B
        // 4 equations of the line we get are

        // y = Ay 
        // x = Ax

        // y = By
        // x = Bx

        int Ax = A[0],Ay = A[1];
        int Bx = B[0],By = B[1];

        int Cx = C[0],Cy = C[1];

        if(Cy - Ay <= 0 && Cx - Ax >= 0 && Cy - By >= 0 && Cx - Bx <= 0)return true;

        return false;


    }

    bool leftAndAbove(vector<int>& A,vector<int> &B){
        int Ax = A[0],Ay = A[1];
        int Bx = B[0],By = B[1];

        if(Ax <= Bx && Ay >= By)return true;
        return false;
    }
    int numberOfPairs(vector<vector<int>>& p) {
        int n = p.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j <n;j++){
                if(i == j)continue;
                if(leftAndAbove(p[i],p[j])){
                    // cout << "true for indexes : " << i << " " << j << endl;
                    if(n == 2){
                        ans ++;
                        break;
                    }
                    bool flag = true;
                    for(int k = 0;k<n;k++){
                        if(k != i && k != j ){
                            if(checkSquare(p[i],p[j],p[k]) == true){
                                flag = false;
                            }

                        }
                    }
                    if(flag)ans++;
                }
            }
        }
        return ans;
    }
};
