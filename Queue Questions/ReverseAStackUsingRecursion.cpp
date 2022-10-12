#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack <int> &stk,int data){
	if(stk.empty()){
		stk.push(data);
		return;
	}
	int s=stk.top();
	stk.pop();
	insertAtBottom(stk,data);
	stk.push(s);
	return;
}

void reverseStack(stack <int> &stk){
	if(stk.empty()){
		return;
	}
	int d=stk.top();
	stk.pop();
	reverseStack(stk);
	insertAtBottom(stk,d);
}

int main(){
	int n;
	cin>>n;
	stack <int> s;
	for(int i=0;i<n;++i){
		int d;
		cin>>d;
		s.push(d);
	}
	reverseStack(s);
	while(s.empty()==false){
		cout<<s.top()<<"\n";
		s.pop();
	}

}