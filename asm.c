#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	int i=0;
	int ii=0;
	char strcopy[1024];
	char strcopy2[1024];
	char strcopy3[1024];
	char strcopy4[1024];
	char *strc;
	if(argc<2)exit(0);
	for(i=1;i<argc;i++){
		if (strstr(argv[i],"-h")){
			printf("asm -h\nasm filename.s\n");
		}else{
			printf("%s %s\n","working..\n",argv[i]);
			strcpy(strcopy,argv[i]);
			strcpy(strcopy3,argv[i]);
			strcpy(strcopy4,argv[i]);
			strc=strstr(strcopy,".s");
			if (strc!=NULL){
				strc[1]='o';
				strc=strstr(strcopy3,".s");
				strc[1]='c';
				strcat(strcopy3,"om");
				strc=strcpy(strcopy2,"as86  ");
				strc=strcat(strcopy2,argv[i]);
				strc=strcat(strcopy2," -o ");
				strc=strcat(strcopy2,strcopy);
				strc=strcat(strcopy2," -u -w -0 -n ");
				strc=strcat(strcopy2,argv[i]);
				strc=strcat(strcopy2," ");
				printf("\n%s\n",strcopy2);
				system(strcopy2);
				strc=strcpy(strcopy2,"ld86  -o ");
				strc=strcat(strcopy2,strcopy3);
				strc=strcat(strcopy2," -y -d -T100 -L/usr/lib/bcc -0 -C0  ");
				strc=strcat(strcopy2,strcopy);
				strc=strcat(strcopy2," -ldos ");
				printf("\n%s\n",strcopy2);
				system(strcopy2);

			}else{
				printf("the file is not a .s file");
			}
		}
	}
	
	return 0;
}
