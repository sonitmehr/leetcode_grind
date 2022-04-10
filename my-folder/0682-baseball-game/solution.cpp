class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n = ops.size();
        vector<int> temp;
        for(int i = 0;i<n;i++){
            if(ops[i] == "C"){
                temp.pop_back();
            }
            else if(ops[i] == "D"){
                temp.push_back(2*temp.back());
            }else if(ops[i]== "+"){
                int n1 = temp.size();
                temp.push_back(temp[n1-1] + temp[n1-2]);
            }else temp.push_back(stoi(ops[i]));
        }
        return accumulate(temp.begin(),temp.end(),0);
    }
};//["5","2","C","D","+"]
