#include <stdio.h>
#include <stdlib.h>

int leftBit(int x);
void printBin(int n);

int main(int argc, char **argv) {
	if (argc<2) {
		printf("Invoke as %s <n> \n\twhere <n> is an integer\n",argv[0]);
		return 1;
	}
	int x=atoi(argv[1]);
	printf("X= "); printBin(x); printf("\n");
	printf("The leftmost bit of %d is at position %d\n",x,leftBit(x));
	return 0;
}

int leftBit(int x) {
	// Your code goes here
	int n = 0 ,w = 32 , hw;

	while (w>1) {
		/* code */
		hw = w/2;
		int mask=((1<<hw)-1)<<(n+hw);
		if ( (x & mask) != 0  ){
			n = n+hw ;
			w = hw ;
		}
		else {
			w = hw;
		}
		printf("M= "); printBin(mask); printf(" hw=%d n=%d\n",hw,n);


	}


	return n;
}

void printBin(int n) {
	int i;
	for(i=31;i>=0;i--) {
		printf("%c",(n&1<<i)?'1':'0');
		if (0==i%4) printf(" ");
	}
}
