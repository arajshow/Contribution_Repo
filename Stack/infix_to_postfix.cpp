#include<bits/stdc++.h>
#include<stack>
using namespace std;

int preced(char ch) {
   if(ch == '+' || ch == '-') {
      return 1;            
   }else if(ch == '*' || ch == '/') {
      return 2;            
   }else if(ch == '^') {
      return 3;           
   }else {
      return 0;
   }
}

string inToPost(string infix ) {
   stack<char> stk;
   stk.push('#');              
   string postfix = "";         
   string::iterator it;

   for(it = infix.begin(); it!=infix.end(); it++) {
      if(isalnum(char(*it)))
         postfix += *it;      
      else if(*it == '(')
         stk.push('(');
      else if(*it == '^')
         stk.push('^');
      else if(*it == ')') {
         while(stk.top() != '#' && stk.top() != '(') {
            postfix += stk.top(); 
            stk.pop();
         }
         stk.pop();          
      }else {
         if(preced(*it) > preced(stk.top()))
            stk.push(*it); 
         else {
            while(stk.top() != '#' && preced(*it) <= preced(stk.top())) {
               postfix += stk.top();        
               stk.pop();
            }
            stk.push(*it);
         }
      }
   }

   while(stk.top() != '#') {
      postfix += stk.top();       
      stk.pop();
   }

   return postfix;
}

int main() {
   string infix;
   cin>>infix;
   cout << "Postfix Form Is: " << inToPost(infix) << endl;
}
