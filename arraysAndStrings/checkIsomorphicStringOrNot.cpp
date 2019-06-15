/*Given two strings s and t, determine if they are isomorphic. 
*Two strings are isomorphic
*if the characters in s can be replaced to get t.
eg egg and add are isomorphic since each letter on string 1 is mapped to string 2 .
foo and bar are not isomorphic since o is mapped to a and r in string 2 .
*/

#include<iostream>
#include<map>
using namespace std;
bool isIsoMorphic(string s , string t){
	if(s.size()!=t.size()){
		return false;
	}
	map<char,char> map1;
	map<char,char> map2;
	for(int i=0;i<s.size();i++){
		/*checks whether character is already  in map1 or not if yes
		checks whether previous value for already stored element is same as that of current one ,
		if not returns false  
		*/ 
		if(map1.find(s[i])!=map1.end()){
			if(map1.find(s[i])->second!=t[i]){
				return false;
			}
		}else{
			if(map2.find(t[i])!= map2.end()){
				if(map1.find(t[i])->second!=s[i]){
				return false;
			}
				
			}else{
				map1.insert(pair<char,char>(s[i],t[i]));
				map2.insert(pair<char,char>(t[i],s[i]));
			}
		}
		
	}
	return true;
}
int main(){
	
	cout<<isIsoMorphic("foo","bar")<<endl;
	cout<<isIsoMorphic("egg","add")<<endl;
	cout<<isIsoMorphic("exam","tile")<<endl;
	cout<<isIsoMorphic("cool","help")<<endl;
	
}