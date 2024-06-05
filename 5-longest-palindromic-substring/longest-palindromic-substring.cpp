class Solution {
public:
    string longestPalindrome(string s) {
        ios::sync_with_stdio(0);

        int sz = s.size();
        pair<int, int> p = {0, 0};
        vector<vector<bool>> dp(sz, vector<bool>(sz));
        for (int i = 0; i < sz; ++i)
            for (int j = i; ~j; --j) {
                if (j >= i-1) dp[j][i] = s[i] == s[j];
                else dp[j][i] = dp[j+1][i-1] && s[i] == s[j];
                if (dp[j][i] && i-j > p.second-p.first) {
                    p.first = j;
                    p.second = i;
                } 
            }
        return s.substr(p.first, p.second-p.first+1);
    }
};