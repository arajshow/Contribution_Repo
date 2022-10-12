#include <iostream>
#include <stack>
using namespace std;

class Q{
private:
	stack <int> s1;
	stack <int> s2;
public:
	Q(int n){
		for(int i=0;i<n;++i){
			while(s1.empty()==false){
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(i);
			while(s2.empty()==false){
				s1.push(s2.top());
				s2.pop();
			}
		}		
	}
	void pop(){
		s1.pop();
	}
	int front(){
		return s1.top();
	}
	bool empty(){
		return s1.empty();
	}
};
int main(){
	int n;
	cin>>n;
	Q sq(n);
	while(sq.empty()==false){
		cout<<sq.front()<<" ";
		sq.pop();
	}

}