#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	int line=0;
	char stndin[1024];
	char *stdouter;
	
	while(!feof(stdin)){
		fgets(stndin,1023,stdin);
		stdouter=strstr(stndin,"!");
		if (stdouter!=NULL)stdouter[0]=0;
		stdouter=strstr(stndin,";");
		if (stdouter!=NULL)stdouter[0]=0;
		stdouter=strstr(stndin,"\n");
		if (stdouter!=NULL)stdouter[0]=0;
		stdouter=strstr(stndin,"\r");
		if (stdouter!=NULL)stdouter[0]=0;
		if (stndin[0]!=0){
			if (strstr(stndin,":")==NULL)fprintf(stdout,"        ");
			fprintf(stdout,"%s\r\n",stndin);
		line++;
		}
	}
	fprintf(stdout,"; lines : %d \r\n",line);
}
