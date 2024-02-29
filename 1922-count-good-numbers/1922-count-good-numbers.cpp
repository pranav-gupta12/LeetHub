#define mod 1000000007
class Solution {
private:
     long long power(long long x, long long n) {
        if (n == 0) return 1;
        
        long long y = power(x, n / 2) % mod;
        
        if (n % 2 == 0) {
            return (y * y) % mod;
        } else {
            return (x * y * y) % mod;
        }
    }
public:
    int countGoodNumbers(long long n) {
        long long numberOfOddPlaces = n/2;
        long long numberOfEvenPlaces = n/2 + n%2;
        return (power(5, numberOfEvenPlaces) * power(4, numberOfOddPlaces))%mod;
    }
};