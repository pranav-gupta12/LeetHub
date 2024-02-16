class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
         if (arr.empty()) return 0; // Check if the input vector is empty
        
        sort(arr.begin(), arr.end());
        vector<int> count;
        
        for (int i = 0; i < arr.size();) {
            int temp = 1;
            while (i + 1 < arr.size() && arr[i] == arr[i + 1]) {
                temp++;
                i++;
            }
            count.push_back(temp);
            i++;
        }
        
        sort(count.begin(), count.end());
        
        int i = 0;
        while (k > 0 && i < count.size()) {
            if (count[i] <= k) {
                k -= count[i];
                count[i] = 0;
                i++;
            } else {
                break;
            }
        }
        
        int result = 0;
        for (int num : count) {
            if (num > 0) {
                result++;
            }
        }
        
        return result;
    }
};