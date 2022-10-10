#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
	long long int n;
	cin>>n;
	long long int a[n];
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	stack <long long int> hist;
	long long int area=0;
	long long int i=0;
	for(;i<n;++i){
		while(hist.empty()==false and a[hist.top()]>a[i]){
			long long int h=a[hist.top()];
			hist.pop();
			long long int at=hist.empty()?(i)*h:(i-hist.top()-1)*h;
			area=max(area,at);
		}
		hist.push(i);
	}
	while(hist.empty()==false){
			long long int h=a[hist.top()];
			hist.pop();
			long long int at=hist.empty()?(i)*h:(i-hist.top()-1)*h;
			area=max(area,at);
	}

	cout<<area;
}