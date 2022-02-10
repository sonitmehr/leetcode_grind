class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long mass1 = mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto i : asteroids){
            if(mass1>=i){
                mass1 += i;
                i = '*';
            }
            else{
                return false;
            }
        }return true;
    }
};
