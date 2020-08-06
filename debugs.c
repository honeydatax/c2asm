#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]){
	FILE *f1;
	if(argc<4)exit(0);
	f1=fopen("debug.bat","w");
	fprintf(f1,"debug.com < in.txt > OUT.S\r\necho wait is working...\r\n");
	fclose(f1);
	f1=fopen("in.txt","w");
	fprintf(f1,"n %s \r\nl 0\r\nu %s %s\r\nq\r\nq\n\r",argv[1],argv[2],argv[3]);
	fclose(f1);
	system("timeout 10s  dosbox debug.bat");
	system("mousepad OUT.S &");
	return 0;
}
