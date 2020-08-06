#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	int i=0;
	int ii=0;
	char strcopy[1024];
	char strcopy2[1024];
	char *strc;
	if(argc<2)exit(0);
	for(i=1;i<argc;i++){
		if (strstr(argv[i],"-h")){
			printf("dissembler -h\ndissembler filename.o\n");
		}else{
			printf("%s %s\n","working..\n",argv[i]);
			strcpy(strcopy,argv[i]);
			strc=strstr(strcopy,".o");
			if (strc!=NULL){
				strc[1]='T';
				strc=strcpy(strcopy2,"objdump86 ");
				strc=strcat(strcopy2," ");
				strc=strcat(strcopy2,argv[i]);
				strc=strcat(strcopy2," > ");
				strc=strcat(strcopy2,strcopy);
				strc=strcat(strcopy2," ");
				strc=strcat(strcopy2," ");
				system(strcopy2);
				strc=strcpy(strcopy2,"mousepad ");
				strc=strcat(strcopy2,strcopy);
				strc=strcat(strcopy2," &");
				system(strcopy2);
				printf("openig file %s \n ",strcopy);
				
			}else{
				printf("the file is not a .o object file");
			}
		}
	}
	
	return 0;
}
