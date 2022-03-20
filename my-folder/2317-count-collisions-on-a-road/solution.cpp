class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0, x = 0, y = 0;
        for (char c : directions) {
            if (c == 'L') ans += x;
            else x = 1;
        }
        reverse(directions.begin(), directions.end());
        for (char c : directions) {
            if (c == 'R') ans += y;
            else y = 1;
        }
        return ans;
    }
};
