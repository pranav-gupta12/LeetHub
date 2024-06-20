class Solution {
public:
       bool canWePlace(const vector<int>& arr, int dist, int balls) {
        int countBalls = 1;
        int lastPlaced = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastPlaced >= dist) {
                countBalls++;
                lastPlaced = arr[i];
            }
            if (countBalls >= balls) {
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
           sort(position.begin(), position.end());
        
        int lo = INT_MAX;
        for(int i=1;i<position.size();i++){
            lo = min(lo, position[i]- position[i-1]);
        }
        int hi = (position.back() - position[0]) / (m - 1);
        int ans = 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canWePlace(position, mid, m)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};