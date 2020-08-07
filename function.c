#include <stdio.h>
//int n1=0;
//int n2=0;



long addss(n1,n2)
	long n1,n2;
{
	return n1+n2;
}

int main(){
	long l;
	long l2;
	l=100000;
	l2=200000;
	l=addss(l,l2);
	printf("%lu\n",l);
	return 0;
}

