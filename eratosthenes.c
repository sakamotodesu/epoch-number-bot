#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_bit( char* list, int num );
void set_bit( char* list, int num );

// todo: macro
int get_bit( char* list, int num ){
	if( *( list + ( num / 8 ) ) & (char)( num % 8 + 1 ) ){
		return 1;
	} else {
		return 0;
	}
}

void set_bit( char* list, int num ){
	*( list + ( num / 8 ) ) ^= (char)( num % 8 + 1 ); 
}

int main(void){

	int max = 100;
	char* list = NULL;

	list = (char*)malloc(max/8+1);
	if( list == NULL ){
		perror("malloc fail");
		exit(1);
	}
	memset(list, 0xF, max);
	int i;
	printf("test\n");
	set_bit(list,10);
	for( i = 0; i<max; i++ ){
		printf("%dbit: %d\n",i,get_bit(list,i));
	}
	return 0;
}
