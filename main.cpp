#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);
void drawCharSquare(char **square, int n);

int main(int argc, char **argv)
{
	int n;
	if(argc!=3)
	{
		printf("Incorrect arguments number. Exiting...");
		exit(1);
	}
	n=atoi(argv[1]);
	srand(atoi(argv[2]));
	drawCharSquare(charSquare(n), n);
	return 0;
}

char **charSquare(int n)
{
	char **square;
	for(int i=0;i<n;i++) square[i]=(char*)malloc(n*(sizeof(char)));
	for(long long i=0;i<n*n;i++) square[i/n][i%n]=rand()%26+97;
	return square;
}

void drawCharSquare(char **square, int n)
{
	for(long long i=0;i<n*n;i++) if(i%n==n-1 && i<n*n-1) printf("%c\n", square[i/n][i%n]); else printf("%c ", square[i/n][i%n]);
	for(int i=0;i<n;i++) free(square[i]);
	free(square);
}
