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
        cout << i + 1 << " "; \
    cout << "]" << endl
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const int M = 1e9 + 7;
ll maxx = LLONG_MAX;
ll minn = LLONG_MIN;
#define pii pair<int,int>
class Solution {
public:

    void topoSortHelper(int node,vector<int> &vis,vector<pii> adj[],stack<int> &st){
        vis[node] = 1;
        for(auto &adjNode : adj[node]){
            if(vis[adjNode.first] == 0){
                topoSortHelper(adjNode.first,vis,adj,st);
            }
        }
        st.push(node);
    }

    stack<int> topoSort(vector<pii> adj[],int n){
        stack<int> st;
        vector<int> vis(n,0);
        
        for(int i = 0;i<n;i++){
            if(vis[i] == 0){
                topoSortHelper(i,vis,adj,st);
            }
        }
        return st;
    }

    int networkDelayTime(vector<vector<int>>& v, int n, int k) {
        vector<pii> adj[n];

        for(auto &i : v){
            adj[i[0] - 1].pb({i[1] - 1,i[2]});
        }

       queue<int> q;
        k--;
        q.push(k);
        vector<int> dist(n,1e9);
        dist[k] = 0;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            

            for(auto &i : adj[p]){
                cout << p + 1<< " " << i.first + 1 <<endl;
                if(dist[p] + i.second < dist[i.first]){
                    cout << "ENTERED" << endl;
                    dist[i.first] = dist[p] + i.second;
                    q.push(i.first);
                }
            }
        }
        int maxi = 0;
        for(auto &i : dist){
            maxi = max(maxi,i);
        }
        return maxi == 1e9 ? - 1 : maxi;
    }
};
