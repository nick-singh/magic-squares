#include <stdlib.h>
#include <stdio.h>


#define maxN 51
void odd(int[][maxN+1]);
void printSq(int [][maxN+1]);

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
			magicSq[i][j] = 0;
		}		
	}
	odd(magicSq);

	printSq(magicSq);

	fclose(in);
	fclose(out);
	return 0;
}


void odd(int magicSq[][maxN+1])
{
	int i = 0, j = n/2, 
	nsq = n*n, count = 1;

	

	while(count <= nsq)
	{	
		if(i<0 && j>n-1){
			i+=2;
			j--;
		}
		if(i<0) i = n-1;
		if(j>n-1)j = 0;
		if(magicSq[i][j] !=0){			
			i+=2;
			j--;
		}	

		magicSq[i][j] = count;		
		count++;
		i--;
		j++;
			
	}
}

void printSq(int magicSq[][maxN+1]){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d \t", magicSq[i][j]);
		}		
		printf("\n");
	}
}