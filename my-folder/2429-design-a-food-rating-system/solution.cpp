class FoodRatings {
public:
    
    struct cmp {
        bool operator() (const pair<int,string> &a,const pair<int,string> &b) const {
            if(a.first != b.first){
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };
    map<string,set<pair<int,string>, cmp> > m1;
    map<string,string > m2;
    map<string,int> rate;
    
    
    
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        
        int n = f.size();
        
        for(int i = 0;i<n;i++){
            m1[c[i]].insert({r[i],f[i]});
            m2[f[i]] = c[i];
            rate[f[i]] = r[i];
        }
    }
    
    void changeRating(string f, int newRating) {
        int oldRate = rate[f];
        rate[f] = newRating;
        m1[m2[f]].erase({oldRate,f});
        m1[m2[f]].insert({newRating,f});
    }
    
    string highestRated(string cuisine) {
        pair<int,string> p = *(m1[cuisine].begin());
        return p.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
