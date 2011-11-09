#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_bit( unsigned char* list, int num );
void set_bit( unsigned char* list, int num );
int pow2(int num);

int pow2( int num ){
	int i,ans = 1;
	if ( num == 0 ){
		return ans;
	}
	for( i = 0; i < num; i++ ){
		ans *= 2;
	}
	return ans;
}

int get_bit( unsigned char* list, int num ){
	if( *( list + ( num / 8 ) ) & (unsigned char)( pow2( num % 8 ) ) ){
		return 1;
	} else {
		return 0;
	}
}

void set_bit( unsigned char* list, int num ){
	*( list + ( num / 8 ) ) ^= (unsigned char)( pow2( num % 8 ) ); 
}

int main(void){

	int max = 100;
	unsigned char* list = NULL;

	list = (unsigned char*)malloc(max/8+1);
	if( list == NULL ){
		perror("malloc fail");
		exit(1);
	}
	memset(list, 0xFF, max);
	int i;
	printf("test\n");
	set_bit(list,10);
	set_bit(list,98);
	for( i = 0; i<max; i++ ){
		printf("%dbit: %d\n",i,get_bit(list,i));
	}
	return 0;
}
