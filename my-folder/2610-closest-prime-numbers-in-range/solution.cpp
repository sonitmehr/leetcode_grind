# define ll long long
class Solution {
public:
    
    set<ll> set1;
    void SieveOfEratosthenes(ll n)
    {
        // Create a boolean array "prime[0..n]" and initialize
        // all entries it as true. A value in prime[i] will
        // finally be false if i is Not a prime, else true.
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));

        for (ll p = 2; p * p <= n; p++) {
            // If prime[p] is not changed, then it is a prime
            if (prime[p] == true) {
                // Update all multiples of p greater than or
                // equal to the square of it numbers which are
                // multiple of p and are less than p^2 are
                // already been marked.
                for (ll i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        // Print all prime numbers
        for (ll p = 2; p <= n; p++)
            if (prime[p])
                set1.insert(p);

        //return set;
    }
    vector<int> closestPrimes(int left, int right) {
        SieveOfEratosthenes(2*right);
        auto it = set1.lower_bound(left);
        int l = *it;
        it++;
        int r = *it;
        if(!(l >= left && l <=right && r >= left &&r <= right))return {-1,-1};
        int finalL = l,finalR = r;
        int mini = r - l;
        while(r <= right){
            if((r-l) < mini){
                finalL = l;
                finalR = r;
                mini = r - l;
            }
            if(r-l == 1 || r-l == 2)return {l,r};
            l = r;
            it++;
            r = *it;
           //cout << l << " " << r << endl;
        }
        //cout << l << " " << r << endl;
        return {finalL,finalR};
        
    }
};/*
10
19
4
6
19
31
*/
