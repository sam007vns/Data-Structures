class Solution {
public:
    bool isSubsequence(string s, string t) {
        int count = 0;
        int j = 0;
        while(s[j] != '\0' && count < t.length()){
            if(s[j] == t[count]){
                j++;
                count++;
            }
            else{
                count++;
            }
        }
        if(s[j]=='\0') return true;
        return false;
    }
};

class Solution {
    int isSubSequence(string& s1, string& s2, int i, int j)
{
    if (i == 0 || j == 0) {
        return 0;
    }
    if (s1[i - 1] == s2[j - 1]) {
        return  1 + isSubSequence(s1, s2, i - 1, j - 1);
    }
    else {
        return  isSubSequence(s1, s2, i, j - 1);
    }
}
 
public:
    bool isSubsequence(string s, string t) {
         int m = s.size();
    int n = t.size();
    if (m > n) {
        return false;
    }
    if (isSubSequence(s, t, m, n) == m) {
        return true;
    }
    else {
        return false;
    }
    }
};