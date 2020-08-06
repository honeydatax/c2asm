#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	int ii=0;
	int line=0;
	char stndin[1024];
	char *stdouter;
	if(argc<2)exit(0);
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
		stdouter=strstr(stndin,":");
		if(stdouter!=NULL && ii!=0){
			ii=0;
		}
		stdouter=strstr(stndin,".data");
		if(stdouter!=NULL && ii!=0){
			ii=0;
		}
		stdouter=strstr(stndin,":");
		if(stdouter!=NULL && ii==0){
			stdouter=strstr(stndin,argv[1]);
			if(stdouter!=NULL){
				ii=1;
			}
		}

		if (stndin[0]!=0 && ii!=0){
				if (strstr(stndin,":")==NULL)fprintf(stdout,"        ");
				fprintf(stdout,"%s\r\n",stndin);
			
		line++;
		}
	}
	fprintf(stdout,"; lines : %d \r\n",line);
}
