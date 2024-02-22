class Solution {
public:
    string largestOddNumber(string num) {
         int end = num.size() - 1;
        while (end >= 0 && !(num[end] & 1)) {
            end--;
        }
        return num.substr(0, end + 1);
    }
};