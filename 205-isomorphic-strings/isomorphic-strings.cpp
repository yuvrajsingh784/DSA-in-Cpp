class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mp1[256] = {}, mp2[256] = {};

        for (int i = 0; i < s.size(); ++i) {
            unsigned char a = s[i];
            unsigned char b = t[i];

            if (mp1[a] != mp2[b])
                return false;

            mp1[a] = i + 1;
            mp2[b] = i + 1;
        }

        return true;
    }
};
