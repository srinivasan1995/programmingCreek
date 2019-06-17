/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, 
such that only one letter can be changed at a time and each intermediate word must exist in the dictionary. For example, given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
One shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", the program should return its length 5


*/

#include<iostream>
#include <unordered_set>
#include<queue>
using namespace std;
int main(){
	string start,end;
	int count =0;
	cin>> start>>end;
	unordered_set<string> dict;
	queue<string> q;

	unordered_set<string> reference;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");

	dict.insert("end");

	q.push(start);

	if(start == end ){
		cout<<"2"<<endl;
	}
	while(!q.empty()){
		string word = q.front();
		q.pop();

		if(word == end){
			break;
		}

		for(int i=0;i<word.size();i++){
			string temp = word;
			for(char a = 'a';a <='z';a++){
					temp[i] = a;
					//cout<<"generated word = "<<temp<<endl;

				if(dict.find(temp)!=dict.end() && reference.find(temp) ==  reference.end()){
					//cout<<"word added to queue = "<<temp<<endl;
					q.push(temp);
					reference.insert(temp);
					count++;
				}


			}
		}
	}

	cout<<count<<endl;



}