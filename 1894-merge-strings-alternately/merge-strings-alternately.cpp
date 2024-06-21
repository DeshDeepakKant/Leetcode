class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int sl1=word1.size();
        int sl2=word2.size();
        string ans="";
        for(int i=0;i<max(sl1,sl2);i++)
        {
            if(i<sl1)
            {
                ans.push_back(word1[i]);
            }
            if(i<sl2)
            {
                ans.push_back(word2[i]);
            }
        }
        return ans;
    }
};