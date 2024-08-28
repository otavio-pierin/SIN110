//Exercícios - Matriz

// Ex1
// ==========================================================
#include <stdio.h>
int main(){
	int mat[4][4], i, j;
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("Digite o numero [%d][%d] da matriz: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	
	printf("Numeros da matriz: \n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	
	printf("\nPosição dos numeros pares da matriz: \n");	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(mat[i][j]%2==0)
				printf("%d %d\n", i, j);
		}
	}
	
	
	return 0;

}

// Ex2
// ==========================================================
#include <stdio.h>
int main(){
	int mat[5][5], i, j;
	
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			printf("Digite o numero [%d][%d] da matriz: ", i+1, j+1);
			scanf("%d", &mat[i][j]); 
		}
	}
	
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			printf("%d ", mat[i][j]);
		};
		printf("\n");
	}
	
	printf("Numeros da diagonal principal da matriz: \n");
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			if(i==j)
			printf("%d ", mat[i][j]);
		};
	}
	
	return 0;

}

// Ex3
// ==========================================================
#include <stdio.h>
int main(){
	int mat[4][4], i, j;
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("Digite o numero [%d][%d] da matriz: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	
	printf("Numeros da matriz: \n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	
	printf("\nPosicao dos numeros impares da matriz: \n");	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(mat[i][j]%2!=0)
				printf("%d %d\n", i, j);
		}
	}
	
	
	return 0;

}

// Ex4
// ==========================================================
#include <stdio.h>
int main(){
	float mat[3][3], soma=0;
	int i, j;
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("Digite o numero [%d][%d] da matriz: ", i+1, j+1);
			scanf("%f", &mat[i][j]);
			soma += mat[i][j];
		}
	}
	
	printf("Numeros da matriz: \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%.2f ", mat[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMedia do conteudo da matriz: %.2f\n", soma/9);	

	
	return 0;

}

// Ex5
// ==========================================================
#include <stdio.h>
int main(){
	int mat[3][3], min, max;
	int i, j;
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("Digite o numero [%d][%d] da matriz: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	
	min=mat[0][0];
	max=mat[0][0];
	
	printf("Numeros da matriz: \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}	

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(mat[i][j]>max) max=mat[i][j];
			if(mat[i][j]<min) min=mat[i][j];
		}
	}
	
	printf("\nMax: %d\nMin: %d", max, min);	

	
	return 0;

}

// Ex6
// ==========================================================
#include <stdio.h>
int main(){
	int mat[5][2], cont2=0, cont3=0, cont5=0;
	int i, j;
	
	for(i=0; i<5; i++){
		for(j=0; j<2; j++){
			do{
			printf("Digite o numero [%d][%d] da matriz: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
	        }while(mat[i][j]<0 || mat[i][j]>9);
	        
	        if(mat[i][j]==2){
				cont2++;	
			}else if(mat[i][j]==3){
				cont3++;
			}else if(mat[i][j]==5){
				cont5++;
			}

		}
	}
	
	printf("Numeros da matriz: \n");
	for(i=0; i<5; i++){
		for(j=0; j<2; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}	
	
	printf("\nX2: %d\nX3: %d\nX5: %d", cont2, cont3, cont5);	

	
	return 0;

}

// Ex7
// ==========================================================
#include <stdio.h>
int main(){
	int mat[2][5], i, j, qtd;
	
	for(i=0; i<2; i++){
		for(j=0; j<5; j++){
			printf("Digite o numero [%d][%d] da matriz: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	
	printf("Numeros da matriz: \n");
	for(i=0; i<2; i++){
		for(j=0; j<5; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	
	printf("\nNumeros impares da matriz:");	
	for(i=0; i<2; i++){
		for(j=0; j<5; j++){
			if(mat[i][j]%2!=0){
				printf("%d ", mat[i][j]);
				qtd++;
			}	
		}
	}
	printf("\nQuantidade de numeros impares: %d\n", qtd);
	
	return 0;
}