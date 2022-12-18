class Solution {
public:
    set<long long> set1;
    
    void SieveOfEratosthenes(long long n)
    {
        // Create a boolean array "prime[0..n]" and initialize
        // all entries it as true. A value in prime[i] will
        // finally be false if i is Not a prime, else true.
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));

        for (long long p = 2; p * p <= n; p++) {
            // If prime[p] is not changed, then it is a prime
            if (prime[p] == true) {
                // Update all multiples of p greater than or
                // equal to the square of it numbers which are
                // multiple of p and are less than p^2 are
                // already been marked.
                for (long long i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        // Print all prime numbers
        for (long long p = 2; p <= n; p++)
            if (prime[p])
                set1.insert(p);

        //return set;
    }
    vector<int> primeFactors(int n)
    {
        // Print the number of 2s that divide n
        vector<int> ans;
        while (n % 2 == 0)
        {
            ans.push_back(2);
            n = n/2;
        }

        // n must be odd at this point. So we can skip
        // one element (Note i = i +2)
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            // While i divides n, print i and divide n
            while (n % i == 0)
            {
                ans.push_back(i);
                n = n/i;
            }
        }

        // This condition is to handle the case when n
        // is a prime number greater than 2
        if (n > 2)
            ans.push_back(n);
        return ans;
    }
 
    int smallestValue(int n) {
        vector<int> check(100010);
        SieveOfEratosthenes(n);
        for(auto i = set1.begin();i!=set1.end();i++){
            check[*i] = *i;
        }
        //for(int i = 0;i<n;i++)cout << check[i] << endl;
        check[1] = 1;
        check[2] = 2;
        check[3] = 3;
        check[4] = 4;
        check[5] = 5;
        check[6] = 5;
        check[7] = 7;
        check[8] = 5;
        check[9] = 5;
        check[10] = 7;
        
        vector<int> prime = primeFactors(n);
        if(prime.size() == 0)return n; 
        int prod = 0;
        vector<int> change;
        while(check[prod]==0){
            prod = 0;
            for(auto i : prime){
                prod += i;
                change.push_back(prod);
                //cout << i <<  " " << prod << endl;
            }
            prime = primeFactors(prod);
        }
        
        for(auto i : change)check[i] = check[prod];
        //if(check[prod] == 0)check[prod] = prod;
        
        return check[prod];

    }
};
