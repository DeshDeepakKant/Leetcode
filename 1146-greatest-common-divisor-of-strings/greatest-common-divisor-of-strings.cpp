class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        string s = "";
        int i = 0;
        while (str1[i] == str2[i] && i < gcd(str1.length(), str2.length())) {
            s.push_back(str1[i]);
            i++;
        }
        int sl = s.size();
        if (!sl ) {
            return "";
        }
        for (int i = 0; i < str1.length(); i++) {
            if (s[i % sl] != str1[i]) {
                return "";
            }
        }
        for (int i = 0; i < str2.length(); i++) {
            if (s[i % sl] != str2[i]) {
                return "";
            }
        }
        return s;
    }
};