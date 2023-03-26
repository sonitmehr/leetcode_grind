#define ll long long

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
    bool primeSubOperation(vector<int>& v) {
        SieveOfEratosthenes(1000);
        int prev = -1;
        
        for(auto &i : v){
            // int i = p.first;
            //cout << i << " ";
            if(i == 2){
                if(prev >= i)return false;
                prev = i;
                continue;
            }
            auto it = set1.lower_bound(i);
            it--;
            while(it != set1.begin() && i - *it <= prev){
                
                
                it--;
                //cout << *it << " " <<i << " ";
                 //it = set1.lower_bound(i);
                
            }
            if(i - *it > prev)i-=*it;
            //cout << endl;
            prev = i;
        }
       
        // vector<int> temp = v;
        int n = v.size();
        cout << v[0] << " ";
        for(int i = 1;i<n;i++){
            cout << v[i] << " ";
            if(v[i] <= v[i - 1]){
                cout << endl;
                return false;
            }
            
        }
        cout <<endl;
        return true;
    }
};
