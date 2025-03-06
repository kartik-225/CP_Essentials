#include <bits/stdc++.h>

using namespace std;


// Generates prime numbers of a particular large range 
void segmentedSieve(vector<int> &totalPrimes , int l , int r){
    int n = sqrt(r);

    vector<bool> primes(n+1 , true);
    for(int i = 2 ; i <= n ; i++){
        if(primes[i]){
            for(int j = 2*i ; j <= n ; j += i)
                primes[j] = 0;
        }
    }

    vector<bool> primesOfRange(r-l+1 , true);
    int start;
    for(int i = 2 ; i <= n ; i++){
        if(primes[i]){
            if(l % i == 0) start = l;
            else start = l + i - (l % i);
            for(int j =  start; j <= r ; j += i){
                if(j != i)
                    primesOfRange[j-l] = 0;
            }
        }
    }

    for(int i = 0 ; i < r-l+1 ; i++)
        if(primesOfRange[i]){
            if(l+i != 1)
                totalPrimes.push_back(l+i);
        }
}

int main(){

    vector<int> ans;
    segmentedSieve(ans , 0 , 10);

    for(auto i : ans)
        cout << i << ' ';
    cout << endl;

    return 0;
}