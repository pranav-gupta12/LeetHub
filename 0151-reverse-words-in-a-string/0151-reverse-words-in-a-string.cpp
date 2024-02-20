class Solution {
public:
    string reverseWords(string s) {
      string result;
    int i = 0;
    int n = s.length();

    while(i < n){
        // Skip leading spaces
        while(i < n && s[i] == ' ') i++;
        if(i >= n) break;
        int j = i + 1;
        // Find the end of the current word
        while(j < n && s[j] != ' ') j++;
        // Extract the current word and add it to the beginning of the result
        string sub = s.substr(i, j-i);
        if(result.length() == 0) result = sub;
        else result = sub + " " + result;
        // Skip trailing spaces
        while(j < n && s[j] == ' ') j++;
        i = j;
    }
    return result;}
};