#include <iostream>
#include <stack>
using namespace std;
int main(){
	int n;
	cin>>n;
	int num[n];
	for(int i=0;i<n;++i){
		cin>>num[i];
	}
	int greater[n];
	fill_n(greater,n,-1);
	stack <int> buf;
	for(int i=0;i<2*n;++i){
		int ix=i%n;
		while(buf.empty()==false and num[buf.top()]<num[ix]){
			greater[buf.top()]=num[ix];
			buf.pop();
		}
		buf.push(ix);
	}
	for(int i=0;i<n;++i){
		cout<<greater[i]<<" ";
	}
}