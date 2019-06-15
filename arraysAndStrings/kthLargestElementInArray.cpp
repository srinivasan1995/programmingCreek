#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int k;
	cin>>k;

	sort(a,a+n);

	for(int i=n-1;i>=0;i--){
		if((k-1)==0){
			cout<<a[i]<<endl;
		}
		k--;
	}
}
