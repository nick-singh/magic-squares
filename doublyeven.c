#include <stdio.h>
#include <stdlib.h>

#define maxN 50


void doublyEven(int[][maxN+1]);
int n;

FILE *in, *out;

int main()
{
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	fscanf(in,"%d",&n);
	int magicSq[maxN+1][maxN+1];
	int i, j, count = 1;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			magicSq[i][j] = count++;			
		}		
	}
	doublyEven(magicSq);

	fclose(in);
	fclose(out);
	return 0;
}


void doublyEven(int magicSq[][maxN+1])
{
	int i, j;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i%4 ==0 || i%4 == 3){
				if(j%4 ==0 || j%4 == 3){
					magicSq[i][j] = (n * n + 1) - magicSq[i][j];
				}
			}else if(i%4 == 1 || i%4 == 2){
				if(j%4 ==1 || j%4 == 2){
					magicSq[i][j] = (n * n + 1) - magicSq[i][j];
				}
			}
			printf("%d\t", magicSq[i][j]);
		}
		printf("\n");
	}
}