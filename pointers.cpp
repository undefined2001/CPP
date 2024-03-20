#include<bits/stdc++.h>
using namespace std;
int main(){
	int a = 20;
	// Pointer
	int *b = &a;
	// Pointer to Pointer
	int **c = &b;
	// Pointer to Pointer of a Pointer
	int ***d = &c;
	//Dereferencing pointers and changing the value with pointer aritmatic
	***d = **c + 2;
	int *e =  b + 2;

	cout<< **c <<endl ;
	printf("%d\n", *c);
	printf("%d\n", *c+2);
	cout<< *c <<endl ;
	cout<<***d <<endl ;
	cout<<*e<<endl;
	
	
	return 0;

}
