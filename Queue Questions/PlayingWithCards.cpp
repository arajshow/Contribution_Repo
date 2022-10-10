#include<iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> prime;
bool primes[1000000];
void primesieve(){
	fill_n(primes,1000000,true);
	prime.push_back(1);
	for(long long int i=4;i<1000000;i+=2){
		primes[i]=false;
	}
	
	prime.push_back(2);
	for(long long int i=3;i<1000000;++i){
		if(primes[i]){
			prime.push_back(i);
			for(long long int j=i*i;j<1000000;j+=i){
				primes[j]=false;
			}
		}
	}
	
}




int main(){
	int n,q;
	cin>>n>>q;
	stack <int> a[q+1];
	stack <int> b[q+1];
	primesieve();
	for(int i=0;i<n;++i){
		int d;
		cin>>d;
		a[0].push(d);
	}
	for(int i=1;i<=q;++i){
		long long int pr=prime[i];
		while(a[i-1].empty()==false){
			if(a[i-1].top()%pr==0){
				b[i].push(a[i-1].top());
			}
			else{
				a[i].push(a[i-1].top());
			}
			a[i-1].pop();
		}
		
	}
	
	for(int i=1;i<q+1;++i){
		while(b[i].empty()==false){
			cout<<b[i].top()<<"\n";
			b[i].pop();
		}
	}
	while(a[q].empty()==false){
		cout<<a[q].top()<<"\n";
		a[q].pop();
	}
	return 0;
}