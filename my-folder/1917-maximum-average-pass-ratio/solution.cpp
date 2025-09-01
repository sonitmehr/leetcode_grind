#define pii pair<double,pair<double,double>>

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int extra) {
        double ans = 0;

 
        double sum = 0;

        // priority_queue<pii, std::vector<pii>, std::greater<pii>> minHeap;
        priority_queue<pii> q;
        for(auto &i : c){
            auto curr = (double)i[0]/(double)i[1];
            auto  newCurr = ((double)i[0] + 1)/((double)i[1] + 1);

            auto diff = newCurr - curr;
            q.push({diff,{i[0],i[1]}});

        }


        while(extra > 0){
            
            auto p = q.top();

            q.pop();
            auto diff = p.first;
            auto first = p.second.first;
            auto second = p.second.second;



            auto  newCurr = ((double)first + 2)/((double)second + 2);
            auto  curr = ((double)first + 1)/((double)second + 1);
            
            q.push({newCurr- curr,{first + 1,second + 1}});


            extra--;

        }
 
 while(!q.empty()){
    auto p = q.top();
    auto first = p.second.first;
            auto second = p.second.second;
            auto curr = (double)first/(double)second;

    q.pop();
    sum += curr;
 }


return sum/=(double)c.size();
    //    return 0;
    }
};
