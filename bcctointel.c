#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	int line=0;
	char stndin[1024];
	char stndin2[1024];
	char *stdouter;
	fprintf(stdout,"org 0x100\r\njmp _main\r\n",stndin);
	while(!feof(stdin)){
		fgets(stndin,1023,stdin);
		stdouter=strstr(stndin,"!");
		if (stdouter!=NULL)stdouter[0]=0;
		stdouter=strstr(stndin,";");
		if (stdouter!=NULL)stdouter[0]=0;
		stdouter=strstr(stndin,"export");
		if (stdouter!=NULL)stndin[0]=0;
		stdouter=strstr(stndin,"\n");
		if (stdouter!=NULL)stdouter[0]=0;
		stdouter=strstr(stndin,"\r");
		if (stdouter!=NULL)stdouter[0]=0;
		if (stndin[0]!=0){
			if (strstr(stndin,":")==NULL)fprintf(stdout,"        ");
			stdouter=strstr(stndin,"#.");
			if (stdouter!=NULL){
				stdouter[0]='A';
				stdouter[1]='D';
			}
			stdouter=strstr(stndin,".");
			if (stdouter!=NULL && strstr(stndin,":")!=NULL){
				stdouter[0]='D';
				strcpy(stndin2,"A");
				strcat(stndin2,stndin);
				strcpy(stndin,stndin2);
			}
			stdouter=strstr(stndin,"$");
			if (stdouter!=NULL && strstr(stndin,".byte")!=NULL){
				stdouter[0]='x';
				stdouter=stdouter-1;
				stdouter[0]='0';
			}
			stdouter=strstr(stndin,".");
			if (stdouter!=NULL && strstr(stndin,":")!=NULL){
				stdouter[0]=' ';
			}			
			stdouter=strstr(stndin,".ascii");
			if (stdouter!=NULL){
				stdouter[0]='d';
				stdouter[1]='b';
				stdouter[2]=' ';
				stdouter[3]=' ';
				stdouter[4]=' ';
				stdouter[5]=' ';
			}
			stdouter=strstr(stndin,".byte");
			if (stdouter!=NULL){
				stdouter[0]='d';
				stdouter[1]='b';
				stdouter[2]=' ';
				stdouter[3]=' ';
				stdouter[4]=' ';
			}

			fprintf(stdout,"%s\r\n",stndin);
		line++;
		}
	}
	fprintf(stdout,"; lines : %d \r\n",line);
}
