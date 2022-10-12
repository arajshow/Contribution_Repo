#include <iostream>
#include<vector>
#include <climits>
using namespace std;
template <typename T>
class stack{
private:
	vector <T> v;
	T currMin;
public:
	stack(){
		currMin=3456789;
	}
	void push(T data){
		if(v.empty()){
			v.push_back(data);
			currMin=data;
		}
		else if(data<currMin){
			T temp=2*data-currMin;
			v.push_back(temp);
			currMin=data;
		}
		else{
			v.push_back(data);	
		}
	}
	T top(){
		return *v.end();
	}
	void pop(){
		int n=v.size()-1;
		if(v[n]<currMin){
			currMin=2*currMin-v[n];
		}
		auto i=v.end();
		--i;
		v.erase(i);

	}
	void minE(){
		cout<<currMin<<"\n";
	}
	void print(){
		for(int i=0;i<v.size();++i){
			cout<<v[i]<<" ";
		}
		cout<<"\n";
	}

};
int main(){
	stack <int> s;
	s.push(3);
	s.push(5);
	s.push(2);
	s.push(8);
	s.push(9);
	s.push(1);
	s.print();
	s.minE();
	
	s.pop();
	s.print();
	s.minE();
	s.pop();
	s.pop();
	s.pop();
	s.print();
	s.minE();
	
	return 0;
}