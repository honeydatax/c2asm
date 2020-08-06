#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	int line=0;
	char stndin[1024];
	while(!feof(stdin)){
		fgets(stndin,1023,stdin);
		fprintf(stdout,"%d %s",line,stndin);
		line++;
	}
}
