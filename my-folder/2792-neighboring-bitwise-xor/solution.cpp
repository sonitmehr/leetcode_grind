class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xori = 0;
        for(auto &i : derived){
            xori ^= i;
        }

        return xori == 0;
    }
};
