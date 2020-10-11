
#include <stdio.h>
#define D_WIDTH 32
#define AMT 10
#define RIGHT 100
#define LEFT 200
 
int arr[D_WIDTH] = {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // 32bit register

void printArr(){
	int i;
	for(i = 0; i < D_WIDTH; i++) printf("%d", arr[i]);
	printf("\n");
}

int main(void){
		
		int n, i, j, temp, flag;
		
		printf("first: ");
		printArr();
		
		flag = RIGHT;
		// flag = LEFT;
		
		if(flag == RIGHT){
			printf("shift right, amount: %d\n", AMT);
			// shift right
			for(j = 0; j < AMT; j++){
				temp = arr[0];
				for(i = D_WIDTH - 2; i >= 0; i--)
					arr[i + 1] = arr[i];
				arr[0] = temp;
			}		
		}
		else if(flag == LEFT) {
			printf("shift left, amount: %d\n", AMT);
			// shift left
			for(j = 0; j < AMT; j++){
				temp = arr[0];
				for(i = 1; i <= D_WIDTH; i++){
					if(i == D_WIDTH){
						arr[D_WIDTH - 1] = 0;
					}
					else{
						arr[i] = arr[i + 1];
					}
				}
				arr[0] = temp;
			}
		}
		
		printf("result: ");
		printArr();
 
	return 0;
}
