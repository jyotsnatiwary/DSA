#include<iostream>
using namespace std;


int main(){
	int n,i,j,k=0;
	cin>>n;
	for(i=1;i<n;i++){
		for(j=1;j<i;++j){
			cout<<j+k;
			++k;
			cout<<"\n";
		}
		
	}

}


