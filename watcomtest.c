#include <stdio.h>
#include <dos.h>

extern void fills( );
#pragma aux fills=    \
    "push bp"                  \
    "mov cx,3000" \
    "mov ax,0xb800 " \
    "push ds" \
   "mov ds,ax" \
   "mov bx,0" \
   "mov al,'*'" \
    "x:"                 \
    "mov [bx],al" \
    "inc bx" \
    "inc al" \
    "dec cx"\
    "jnz x"\
    "pop ds" \
     "pop bp"            ;       
  

int main(){
	fills();
	xx:
	goto xx;
	
	return 0;
}
