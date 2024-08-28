// Exercicios Recursividade

// Ex1
// ==========================================================
#include <stdio.h>
#include <math.h>

int hip_fat(int n){
	if(n==1){
		return 1;
	}else{
		return pow(n,n)*(hip_fat(n-1));
	}	
}
int main(){
	int n;
	printf("Insira o valor de n: ");
	scanf("%d", &n);
	printf("Resultado: %d", hip_fat(n));
	return 0;	
}

// Ex2
// ==========================================================
#include <stdio.h>

int menor_elemento(int vetor[], int tamanho) {
    if (tamanho == 1)
        return vetor[0];
    
    int menor = menor_elemento(vetor, tamanho - 1);

    if (vetor[tamanho - 1] < menor)
        return vetor[tamanho - 1];
    else
        return menor;
}

int main() {
    int vetor[] = {344, -510, -23, 0, 171, 22};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    menor_elemento(vetor, tamanho);
    printf("Menor elemento do vetor: %d\n", menor_elemento(vetor, tamanho));

    return 0;
}

// Ex3
// ==========================================================
#include <stdio.h>

int padovan(int n){
    if(n<=2)
        return 1;
    else
        return (padovan(n-2)+padovan(n-3));
}

int main() {
    int num;
    printf("Digite o valor de n: ");
    scanf("%d", &num);
    printf("%d numero da sequencia: %d", num, padovan(num)); 
    return 0;
}


// Ex4
// ==========================================================
#include <stdio.h>

int pot(int k, int n){
    if(n==0){
        return 1;
    }
    else{
        if (n==1)
        {
            return k;
        }    
        return k*pot(k,n-1);
    }
}

int main() {
    int k, num;
    printf("Digite o valor de k: ");
    scanf("%d", &k);
    printf("Digite o valor de n: ");
    scanf("%d", &num);    
    printf("k^n: %d", pot(k,num)); 
    return 0;
}

// Ex5
// ==========================================================
#include <stdio.h>

int cat(int n){
    if(n==0){
        return 1;
    }
    else{ 
        return 2*((2*n)-1)*cat(n-1)/(n+1);
    }
}

int main() {
    int num;

    printf("Digite o valor de n: ");
    scanf("%d", &num);    
    printf("C(%d): %d", num, cat(num)); 
    return 0;
}


// Ex6
// ==========================================================
#include <stdio.h>
#include <math.h>

int mdc(int x, int y){
	if(y==0){
		return x;
	}else{
		return mdc(y, x%y);
	}	
}
int main(){
	int n1, n2;
	printf("Insira o valor de n1: ");
	scanf("%d", &n1);
	printf("Insira o valor de n2: ");
	scanf("%d", &n2);	
	printf("Resultado: %d", mdc(n1, n2));
	return 0;	
}

// Ex7
// ==========================================================
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordem(float *vet, int primeiro, int ultm){
    if(primeiro<ultm){
        float aux = vet[primeiro];
        vet[primeiro]=vet[ultm];
        vet[ultm]=aux;

        ordem(vet, primeiro+1, ultm-1);
    }
}
int main(){
	float vetor[100];

    srand(time(NULL));  

    for (int i = 0; i < 100; i++) {
        vetor[i] = rand() % 100; 
    }

    printf("Vetor antes de ser invertido: ");
    for (int i = 0; i < 100; i++)
    {
        printf("%.2f - ", vetor[i]);;
    }  

    ordem(&vetor[0], 0, 99);
    
    printf("\nVetor depois de ser invertido: ");
    for (int i = 0; i < 100; i++)
    {
        printf("%.2f - ", vetor[i]);;
    }
	return 0;	
}

// Ex8
// ==========================================================
#include <stdio.h>
int fat_quad(int n){
    if(n<=1){
        return 1;
    }else{
        return (2*n)*fat_quad(n-1);
    }
}
int main(){
	int num;

    printf("Digite o valor de N: ");
    scanf("%d", &num);
    printf("Fatorial quadruplo de %d: %d", num, fat_quad(num));
	return 0;	
}


// Ex9
// ==========================================================
#include <stdio.h>
#include <math.h>
int fat_exp(int n){
    if(n==1){
        return 1;
    }else{
        if (n==2)
        {
            return 2;
        }
        return pow(n, fat_exp(n-1));
    }
}
int main(){
	int num;

    printf("Digite o valor de N: ");
    scanf("%d", &num);
    printf("Fatorial quadruplo de %d: %d", num, fat_exp(num));
	return 0;	
}
