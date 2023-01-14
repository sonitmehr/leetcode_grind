class Solution {
public:
    int parent[1005];
    int R[1005]; // Rank  
    void makeSet(){
        for(int i = 1;i<=1004;i++){
            parent[i] = i;
            R[i] = 0;
        }
    }
    int findPar(int node){
        if(node == parent[node])return node; // When the parent of node is the node itself.
        return parent[node] = findPar(parent[node]); // Searches for parent in constant time.
    }
    void Union(int a,int b){
        int u = findPar(a);
        int v = findPar(b);
        
        if(u!=v){
            if(u <= v){
                parent[v] = u;
                R[u]++;
            }
            else{
                parent[u] = v;
                R[v]++;
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        makeSet();
        int n = s1.size();
        for(int i= 0;i<n;i++){
            int a = s1[i] - 'a' + 1;
            int b = s2[i] - 'a' + 1;
            //cout << a <<" " << b << endl; 
             
            Union(a,b);


        }
        string ans;
        for(int i =0;i<baseStr.size();i++){
            int a = baseStr[i] - 'a' + 1;
            int b = findPar(a);

            char c = (b - 1 + 'a');
            cout << a <<  " " << b << " " << c << endl;
            ans += c;

        }
        return ans;

    }
};
