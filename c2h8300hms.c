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
			printf("c2asm -h\nc2asm filename.c\n");
		}else{
			printf("%s %s\n","working..\n",argv[i]);
			strcpy(strcopy,argv[i]);
			strc=strstr(strcopy,".c");
			if (strc!=NULL){
				strc[1]='S';
				strc=strcpy(strcopy2,"h8300-hms-gcc ");
				strc=strcat(strcopy2,"-S -o ");
				strc=strcat(strcopy2,strcopy);
				strc=strcat(strcopy2," ");
				strc=strcat(strcopy2,argv[i]);
				strc=strcat(strcopy2," ");
				strc=strcat(strcopy2," ");
				system(strcopy2);
				strc=strcpy(strcopy2,"mousepad ");
				strc=strcat(strcopy2,strcopy);
				strc=strcat(strcopy2," &");
				system(strcopy2);
				printf("openig file %s \n ",strcopy);
				
			}else{
				printf("the file is not a .c file");
			}
		}
	}
	
	return 0;
}
