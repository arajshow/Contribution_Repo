#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool balance(string s){
	stack <char> para;
	for(auto c:s){
		if(c==')'){
			if(para.empty()==false and para.top()=='(')
				para.pop();
			else
				return false;
		}
		else if(c=='}'){
			if(para.empty()==false and para.top()=='{')
				para.pop();
			else
				return false;
		}
		else if(c==']'){
			if(para.empty()==false and para.top()=='[')
				para.pop();
			else
				return false;
		}
		else 
			para.push(c);
	}
	if(para.empty())
		return true;
	else 
		return false;
}

int main(){
	string str;
	getline(cin,str);
	if(balance(str))
		cout<<"Yes\n";
	else
		cout<<"No\n";
}