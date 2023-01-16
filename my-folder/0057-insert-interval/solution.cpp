class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int first = newInterval[0];
        int second = newInterval[1];
        vector<vector<int>> ans;
        
        for(int i= 0;i<n;i++){
            int a = intervals[i][0];
            int b = intervals[i][1];

            if(first > b)ans.push_back(intervals[i]);
            else if(second < a){
                ans.push_back(newInterval);
                newInterval = intervals[i];
            }
            else{
                newInterval[0] = min(newInterval[0],a);
                newInterval[1] = max(newInterval[1],b);
                
            }
            
        }
        ans.push_back(newInterval);
        //cout << startInd << " " << endInd << endl;
        return ans;

    }
};
