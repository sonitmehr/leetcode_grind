class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        //vector<vector<int>> tasks (v.size(),vector<int>(3,0));
        for(auto &i : tasks){
            swap(i[0],i[1]);
        }
        sort(tasks.begin(),tasks.end());
        vector<bool> check(2001,false);
        for(auto &t : tasks){
            int start = t[1],end = t[0],time = t[2];
            
            for(int i = start;i<=end;i++){
                if(check[i] == true){
                    time--;
                }
            }
            for(int i = end;time > 0;i--){
                if(check[i] == true)continue;
                check[i] =true;
                time--;
            }
        }
        int ans = 0;
        for(int i = 1;i<=2000;i++){
            ans += check[i];
        }
        return ans;
    }
};
