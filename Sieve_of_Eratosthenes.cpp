#include <bits/stdc++.h>

using namespace std;

// Generates prime numbers upto n
void sieveOfEratosehenes(vector<int> &ans , int n){
    vector<bool> arr(n+1 , true);
    for(int i = 2 ; i <= n ; i++){
        if(arr[i]){
            for(int j = 2*i ; j <= n ; j += i)
                arr[j] = 0;
        }
    }

    for(int i = 2 ; i <= n ; i++)
        if(arr[i])
            ans.push_back(i);
}


int main(){

    int n = 100;
    vector<int> v;
    sieveOfEratosehenes(v , n);

    for(auto i : v)
        cout << i << ' ';
    cout << '\n';

    return 0;
}