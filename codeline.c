#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	int ii=0;
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
		stdouter=strstr(stndin,"DATASEG");
		if(stdouter!=NULL && ii!=0){
			ii=0;
		}
		stdouter=strstr(stndin,"DATASEG");
		if(stdouter!=NULL && ii!=0){
			ii=0;
		}
		if (stndin[0]!=0 && ii!=0){
				fprintf(stdout,"%10x %s\r\n",line,stndin);
		line=line+16;
		}

		stdouter=strstr(stndin,"TEXTSEG");
		if(stdouter!=NULL && ii==0){
				ii=1;
		}


	}
	fprintf(stdout,"; sizes : %d \r\n",line);
}
