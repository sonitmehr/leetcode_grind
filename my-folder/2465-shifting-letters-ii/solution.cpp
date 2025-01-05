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
using namespace std;
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define ll long long
#define m(x, y) map<x, y>
#define um(x, y) unordered_map<x, y>
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define nline cout << endl;
#define yyes cout << "YES"
#define nno cout << "NO"
#define debug(v)          \
    cout << "V [ ";       \
    for (auto i : v)      \
        cout << i << " "; \
    cout << "]" << endl
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const int M = 1e9 + 7;
ll maxx = LLONG_MAX;
ll minn = LLONG_MIN;
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();
        int m = s.size();
        cout << n << endl;
        vector<int> pre(m + 1,0);
        for(int i = 0;i<n;i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2];
            if(dir){
                pre[start] += 1;
                pre[end + 1] += -1;
            }
            else{
                pre[start] += -1;
                pre[end + 1] += 1;
            }
        }
        for(int i = 0;i<m;i++){
            pre[i + 1] += pre[i];
        }
        // debug(pre);/
        for(int i = 0;i<m;i++){
            if(pre[i] > 0){
                pre[i] = pre[i] % 26;
                if(s[i] + pre[i] > 'z'){
                    pre[i] -= 'z' - s[i] + 1;    
                    s[i] = 'a';
                    
                }
                    s[i] += pre[i];
            }
            else{
                pre[i] = -pre[i];
                                pre[i] = pre[i] % 26;

                if(s[i] - pre[i] < 'a'){
                    pre[i] -= s[i] - 'a' +1;
                    s[i] = 'z';
                }
                s[i] -= pre[i];
            }
        }
            // cout << s << endl;
        return s;

    }
};
