// Header Files
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <list>
#include <iterator>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <random>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <complex>
#include <math.h>
#include <cstring>
#include <chrono>
#include <string>
#include <climits>
// Header Files End
#define pb push_back
#define debug(v)          \
        cout << "V [ ";\
    for (auto &i : v)      \
        cout << i << " "; \
    cout << "] " << endl\
    

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<int> ans;
        
        int left = 0,right = m - 1,top = 0,bottom = n - 1;

        while(left <= right && top <= bottom){
            // cout << left << " " <<right << " " <<top << " " << bottom << endl; 
            for(int i = left;i<=right;i++){
                ans.pb(mat[top][i]);
            }
            // debug(ans);
            top++;
            for(int i = top;i<=bottom;i++){
                ans.pb(mat[i][right]);
            }
            // debug(ans);
            right --;
            if(top <= bottom){

                for(int i = right;i>=left;i--){
                    ans.pb(mat[bottom][i]);
                }
            }
            // debug(ans);
            bottom--;
            if(left <= right){

                for(int i = bottom;i >=top;i--){
                    ans.pb(mat[i][left]);
                }
            }
            // debug(ans);
            left ++;

        }
        return ans;
    }
};
