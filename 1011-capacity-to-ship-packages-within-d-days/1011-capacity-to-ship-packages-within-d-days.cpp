class Solution {
public:
    int DaysTaken(vector<int>& arr, int capacity)
    {
        int days = 1, current = capacity;
        for(int i=0;i<arr.size();i++)
        {
            if(current >= arr[i] )
            {
                current -= arr[i];
            }
            else
            {
                days++;
                current = capacity;
                 current -= arr[i];
            }
            
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = 0;
        for(auto x: weights) high+=x;
        int ans = 0;
        while(low <= high)
        {
            int mid = (low+high)>>1;
            if(DaysTaken(weights, mid)<= days) {
                ans = mid; high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
        
    }
};