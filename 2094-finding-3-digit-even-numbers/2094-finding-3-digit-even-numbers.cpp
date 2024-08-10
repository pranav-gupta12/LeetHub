class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        std::set<int> uniqueNumbers;
    int count[10] = {0};

    // Count occurrences of each digit
    for (int digit : digits) {
        count[digit]++;
    }

    // Try to form three-digit even numbers
    for (int lastDigit = 0; lastDigit < 10; lastDigit += 2) { // last digit must be even
        if (count[lastDigit] > 0) {
            count[lastDigit]--; // Use last digit
            
            for (int firstDigit = 1; firstDigit < 10; firstDigit++) { // first digit cannot be 0
                if (count[firstDigit] > 0) {
                    count[firstDigit]--; // Use first digit
                    
                    for (int secondDigit = 0; secondDigit < 10; secondDigit++) {
                        if (count[secondDigit] > 0) {
                            // Form the number and insert it into the set
                            int num = firstDigit * 100 + secondDigit * 10 + lastDigit;
                            uniqueNumbers.insert(num);
                        }
                    }
                    
                    count[firstDigit]++; // Backtrack
                }
            }

            count[lastDigit]++; // Backtrack
        }
    }

    // Convert the set to a vector
    return std::vector<int>(uniqueNumbers.begin(), uniqueNumbers.end());
    }
};