class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        vector<int> table(26);
        int count = 0;
        int j = 0;
        for (int i = 0; i < n; ++i)
        {
            while (j < n)
            {
                ++table[s[j] - 'A'];
                count = max(count, table[s[j] - 'A']);
                ++j;
                if (j - i <= count + k)
                {
                    maxLen = max(maxLen, j - i);
                }
                else
                {
                    break;
                }
            }

            --table[s[i] - 'A'];
        }

        return maxLen;
    }
};
