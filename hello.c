#include <stdio.h>


void print(c)
char *c; 
{
	#asm
		nop
		mov bx,sp
		mov ax,[bx+2]
		mov dx,ax
		mov ah,#$9
		int #$21
	#endasm

}


int main(){
	char *c="hello world \r\n$";
	print(c);
	x:
	goto x;
	return 0;
}
