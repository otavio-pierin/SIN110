//Funções

//Ex1
#include <stdio.h>

int main(){
	float vet[10];
	int i;
	
	for(i=0; i<10; i++){
		printf("%p ", &vet[i]);	
	}

	return 0;
}

//Ex2
#include <stdio.h>

int main(){
	float real =6.65;
	int inteiro =7;
	char txt = 'a';
	
	printf("ANTES -> real: %.2f int: %d: char: %c", real, inteiro, txt);
	
	int *ptrInt = &inteiro;
	float *ptrFloat = &real;
	char *ptrChar = &txt;
	
	*ptrInt = 9;
	*ptrFloat = 7.77;
	*ptrChar = 'b';
	
	printf("\nDEPOIS -> real: %.2f int: %d: char: %c", real, inteiro, txt);
	return 0;
}

//Ex3
#include <stdio.h>

void soma3(int *n){
	int i;
	for(i=1; i<=*n;i+=3)
		printf("%d ", i);		
}

int main(){
	int num;
	printf("Digite um valor inteiro: ");
	scanf("%d", &num);
	soma3(&num);	
	return 0;
}

//Ex4
#include <stdio.h>

struct Vetor{
float x;
float y;
float z;
};


void soma(struct Vetor *v1, struct Vetor *v2, struct Vetor *res){
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
}

int main() {
    struct Vetor vetor[3];

    for (int i = 0; i < 2; i++)
    {
        printf("VETOR %d \n", i+1);
        printf("Digite um valor para x: ");
        scanf("%f", &vetor[i].x);
        printf("Digite um valor para y: ");
        scanf("%f", &vetor[i].y);
        printf("Digite um valor para z: ");
        scanf("%f", &vetor[i].z);
    }

    soma(&vetor[0],&vetor[1],&vetor[2]);
    printf("Vetor resposta - (%.2f,%.2f,%.2f)", vetor[2].x, vetor[2].y, vetor[2].z);
    return 0;
}


//Ex5
#include <stdio.h>

void preencheVetor(int *vet, int n){
    for(int i=0; i<n; i++){
        printf("Digite o valor %d do vetor: ", i+1);
        scanf("%d", &vet[i]);
    }
}
void imprimeVetor(int *vet, int n){
    for(int i=0; i<n; i++){
        printf("%d ", vet[i]);
    }
}
int retornaMaiorElemento(int *vet, int n){
    int aux = vet[0];
    for(int i=0; i<n; i++){
        if (vet[i]>aux)
        {
            aux=vet[i];
        }  
    }
    return aux;
}

int main() {
    int vet[10];

    preencheVetor(&vet[0], 10);
    imprimeVetor(&vet[0], 10);
    printf("\nMaior valor: %d", retornaMaiorElemento(&vet[0], 10));
    return 0;
}
