//約数列挙　
#include<iostream>
#include<set>
using namespace std;
set<long long> enum_divisors(long long N){
    set<long long> res;
    for(long long i = 1; i * i <= N ; i++){
        if(N % i ==0){
            res.insert(i);
            res.insert(N / i);
        }
    }
    return res;
}
int main(void){
    long long N;
    cin >> N;
    set<long long> answer = enum_divisors(N);
   auto itr = answer.begin();
   for(auto x : answer){
         cout << x << " ";
   }
    cout << endl;
}