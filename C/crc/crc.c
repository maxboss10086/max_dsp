#include<stdio.h>
unsigned int  makecrcpos(
	unsigned int 	clocks,
	unsigned int	error1,
	unsigned int	error2,
	unsigned int	endat22,
	unsigned long 	highpos,
	unsigned long	lowpos
)
{
	unsigned int 	ff[5];
	unsigned int 	code[66];
	unsigned int 	ex;
	unsigned int 	crc = 0;
	signed int 	i;
	for ( i=0; i<5; i++){
		ff[i] = 1;
	}
	if (endat22){
		code[0]	= error1;
		code[1]	= error2;
	}
	else{
		code[1]	=error1;
	}
	for ( i=2; i<34; i++){
		code[i] = (lowpos & 0x00000001) ? 1:0;
		lowpos >>= 1;
	}
	for (int i=34; i<66; i++){
		code[i] = (highpos & 0x00000001)	? 1:0;
		highpos >>= 1;
	}
	for (i=(endat22 ? 0 : 1); i<(clocks+1); i++){
		ex = ff[4] ^ code[i];
		ff[4] = ff[3];
		ff[3] = ff[2] ^ ex;
		ff[2] = ff[1];
		ff[1] = ff[0] ^ ex;
		ff[0] = ex;
	}
	for ( i=4; i>=0; i--){
		ff[i] = ff[i] ? 0 : 1;
		crc <<= 1;
		crc |= ff[i];
	}
	return crc;
}

int main(){
	unsigned int a=0;
	printf("hello word\n");
 	a =makecrcpos(25,0,1,1,0,104462);
 	printf("%d",a);
return 0;
}