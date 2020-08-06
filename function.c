#include <stdio.h>
int n1=0;
int n2=0;

int addss();

int addss(){
	return n1+n2;
}

int main(){
	int n=0;
	n1=100;
	n2=100;
	n=addss();
	return 0;
}

