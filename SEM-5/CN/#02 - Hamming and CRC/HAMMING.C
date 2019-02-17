#include <stdio.h>
#include <math.h>

void main() {
	int ip[4], i, n;
	// hamming bit code
	int h[7];
	// to check hamming bit code ^ same as above
	// error bit code
	int e[3];
	// position of error bit
	int pos=0;

	clrscr();

	printf("enter the data: ");
	for(i=0; i<4; i++)
		scanf("%d", &ip[i]);
	// for(i=0; i<4; i++)
	//	printf("%d ", ip[i]);

	// creating hamming code
	h[2] = ip[0];
	h[4] = ip[1];
	h[5] = ip[2];
	h[6] = ip[3];

	h[0] = (h[2]+h[4]+h[6]) % 2;
	h[1] = (h[2]+h[5]+h[6]) % 2;
	h[3] = (h[4]+h[5]+h[6]) % 2;

	printf("\nthe hamming code is: ");
	for(i=0; i<7; i++)
		printf("%d ", h[i]);

	// checking hamming code
	printf("\nenter hamming code to check: \n");
	for(i=0; i<7; i++)
		scanf("%d", &h[i]);

	e[0] = (h[0]+h[2]+h[4]+h[6]) % 2;
	e[1] = (h[1]+h[2]+h[5]+h[6]) % 2;
	e[2] = (h[3]+h[4]+h[5]+h[6]) % 2;

	printf("\n%d %d %d\n", e[0],e[1],e[2]);

	for(i=0; i<2; i++)
		pos += e[i]*pow(2,i);
	pos -= 1;

	if(pos == -1) {
		printf("\nno error");
	} else {
		printf("\nerror at position: %d", pos);
		printf("\nthe correct hamming code is: ");
		h[pos] = (h[pos]+1)%2;
		for(i=0; i<7; i++)
			printf("%d ", h[i]);
	}

	getch();
}