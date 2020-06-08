
#include <stdio.h>
#define D_WIDTH 8
#define AMT 2
 
int arr[D_WIDTH] = {0, 1, 0, 1, 0, 0, 1, 1}; // 32bit register

void printArr(){
	int i;
	for(i = 0; i < D_WIDTH; i++) printf("%d", arr[i]);
	printf("\n");
}

int main(void){
		
		int n, i, j, temp;
		
		printf("first: ");
		printArr();
		
		for(j = 0; j < AMT; j++){
			temp = arr[0];
			for(i = D_WIDTH - 2; i >= 0; i--){
					arr[i + 1] = arr[i];
			}	
			arr[0] = temp;
		}
		
		printf("result: ");
		printArr();
 
	return 0;
}
