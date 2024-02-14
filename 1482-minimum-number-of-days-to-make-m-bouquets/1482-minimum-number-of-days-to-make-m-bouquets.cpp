class Solution {
    
public:
    bool IsPossible(vector<int>& arr, int m, int k, int mid)
    {
       int ans = 0;
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= mid) {
            count++;
            if (count == k) {
                ans++;
                if (ans == m) return true;
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return false;
    }
    int minDays(vector<int>& arr, int m, int k) {
         if ((long long)m * k > arr.size()) return -1;
       int low =  *min_element (arr.begin(), arr.end());
int high = *max_element (arr.begin(), arr.end());
        int ans = -1;
        while(low<=high)
        {
            int mid = (low+high)>>1;
            if(IsPossible(arr, m,k,mid)) {
                ans = mid;
                high = mid - 1;
            }
            else  low = mid+1;
        } 
        return ans;
    }
};