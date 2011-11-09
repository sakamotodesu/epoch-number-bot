#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
	*( list + ( num / 8 ) ) |= (unsigned char)( pow2( num % 8 ) ); 
}

int main(void){

	int max = 1500000000;
	unsigned char* list = NULL;

	list = (unsigned char*)calloc(1,max/8+1);
	if( list == NULL ){
		perror("malloc fail");
		exit(1);
	}
	int i;
	for( i = 2; i < sqrt( max ); i++ ){
		if ( get_bit( list, i ) == 0 ) {
			int j;
			for( j = 2; i * j < max; j++ ){
				set_bit( list, i * j );
			}
		}
	}

	for ( i = 2; i < max ; i++ ){
		if ( get_bit( list, i ) == 0 ) {
			printf("%d\n",i);
		}
	}

	return 0;
}
