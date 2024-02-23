class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        vector<bool> possible(n + 1, false); // Initialize possible trusts
        
        // Mark the first element of each pair as a trusted person
        for(int i = 0; i < trust.size(); i++) {
            possible[trust[i][0]] = true;
        }
        
        // Sorting the trust vector based on the second element of each pair
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        };
        sort(trust.begin(), trust.end(), cmp);
        
        // Iterate through the sorted trust vector
        for(int i = 0; i < trust.size(); i++) {
            int check = trust[i][1];
            // Check if the second element of the pair is not trusted
            if(possible[check] == false) {
                int count = 0;
                // Count how many people trust this person
                while( i < trust.size() && trust[i][1] == check )  {
                    count++;
                    if(count == n - 1) // If n - 1 people trust this person, return it
                        return check;
                    i++;
                }
            }
        }
        return -1; // Return -1 if no judge is found
    }
};