/*
*Evaluate the value of an arithmetic expression in Reverse Polish Notation.
*Valid operators are +, -, *, /. 
*Each operand may be an integer or another expression. For example:
21+3* => 9 {((2 + 1) * 3)      => 9}

*/


#include<iostream>
#include<stack>
using namespace std;
stack<int> stac;
int main(){
	
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i] >= '0' && s[i] <='9'){
			stac.push(s[i]-48);	
		}else{
			int temp[2]={0};
			for(int i=0;i<2;i++){
				if(!stac.empty()){
					temp[i] = stac.top();stac.pop();
				}
			}
			int result =0;
			switch(s[i]){
				case '+':
				result = temp[0] + temp[1];break;
				case '-':
				result = temp[0] - temp[1];break;
				case '*':
				result= temp[0] * temp[1];break;
				case '/':
				result = temp[0] / temp[1];break;
			}
			
		stac.push(result);	
		}
	}
	
	for(;!stac.empty();){
		cout<<stac.top()<<" ";stac.pop();
	}
	
	
}
