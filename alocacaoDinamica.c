//Exercícios Alocação Dinâmica

//Ex1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct registro{
    int matricula;
    char snome[30];
    int anoNasc;
}Registro;

int main() {
    int num;
    Registro *registro1;

    printf("Informe o numero de alunos que serao armazenados: ");
    scanf("%d", &num);
    registro1 = (Registro *) malloc(num*sizeof(Registro));

    if (registro1 == NULL)
    {
        printf("Erro! Memoria insuficiente!\n");
        system("pause");
        exit(1);
    }

    for (int i = 0; i < num; i++)
    {
        printf("Digite a matricula do aluno %d: ", i+1);
        scanf("%d", &registro1[i].matricula);  
        fflush(stdin);
        printf("Digite o sobrenome do aluno %d: ", i+1);
        fgets(registro1[i].snome, 30, stdin);  
        printf("Digite o ano de nascimento do aluno %d: ", i+1);
        scanf("%d", &registro1[i].anoNasc);                            
    }

    printf("\nDADOS DOS ALUNOS: \n");
    for (int i = 0; i < num; i++)
    {
        printf("ALUNO %d \n", i+1);
        printf("Matricula do aluno: %d\n", registro1[i].matricula);
        printf("Sobrenome do aluno: %s", registro1[i].snome);
        printf("Ano de nascimento do aluno: %d\n", registro1[i].anoNasc);                          
    }

    free(registro1);
    return 0;
}

//Ex2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, tam=50;
    char **matPalv;

    matPalv = (char **) malloc(10*sizeof(char *));
    if (matPalv == NULL)
    {
        printf("Erro! Memoria insuficiente!\n");
        system("pause");
        exit(1);
    }

    for (i = 0; i < 10; i++)
    {
        matPalv[i] = (char *) malloc(tam*sizeof(char));
        if (matPalv[i] == NULL)
        {
            printf("Erro! Memoria insuficiente!\n");
            system("pause");
            exit(1);
        }
    }
    

    for (int i = 0; i < 10; i++)
    {
        printf("Digite a palavra %d: ", i+1);
        fgets(matPalv[i], 50, stdin);  ;
        fflush(stdin);                          
    }

    printf("\nDADOS DIGITADOS: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("Palavra %d \n", i+1);
        printf("%s\n", matPalv[i]);                       
    }

    for (i = 0; i < 10; i++)
    {
        free(matPalv[i]);
    }

    free(matPalv);
    
    return 0;
}

//Ex3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*sorteados anteriores, tamanho do vetor para o for, numero sorteado para ver se já foi*/
int existeNumero(int *vetor, int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == numero) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int sorts[6];
    int nums[6];
    int certos[6];
    int tCertos = 0;

    srand(time(NULL));
    for (int i = 0; i < 6; i++) {
        int aleN;
        do {
            aleN = rand() % 21;
        } while (existeNumero(sorts, i, aleN)==1);
        sorts[i] = aleN;
    }

    printf("Digite os 6 numeros:\n");
    for (int i = 0; i < 6; i++) {
        int nLot;
        do {
            printf("Numero %d: ", i + 1);
            scanf("%d", &nLot);
            if (nLot < 0 || nLot > 20 || existeNumero(nums, i, nLot)==1) {
                printf("Numero invalido.\n");
            }
        } while (nLot < 0 || nLot > 20 || existeNumero(nums, i, nLot)==1);
        nums[i] = nLot;
    }

    for (int i = 0; i < 6; i++) {
        if (existeNumero(nums, 6, sorts[i])==1) {
            certos[tCertos] = sorts[i];
            tCertos++;
        }
    }

    int *pcertos = (int *)malloc(tCertos * sizeof(int));
    for (int i = 0; i < tCertos; i++) {
        pcertos[i] = certos[i];
    }

    printf("\nNumeros sorteados: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", sorts[i]);
    }

    printf("\nNumeros corretos: ");
    for (int i = 0; i < tCertos; i++) {
        printf("%d ", pcertos[i]);
    }

    free(pcertos);

    return 0;
}

//Ex4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tiraVogais(char *str, char *str2, int num){
    int j=0;
    *str2 = (char *) malloc(num+1);
    if (str == NULL)
    {
        printf("Erro! Memoria insuficiente!\n");
        system("pause");
        exit(1);
    }
    for (int i = 0; i < num; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            str2[j] = str[i];
            j++;
        }
    }
    str2[j] = '\0';
}
int main() {
    int num;
    char *str, *str2;

    printf("Digite o tamanho da string: ");
    scanf("%d", &num);
    fflush(stdin);

    str= (char *) malloc((num+1)*sizeof(char));

    if (str == NULL)
    {
        printf("Erro! Memoria insuficiente!\n");
        system("pause");
        exit(1);
    }

    printf("Digite a string: ");
    fgets(str, num+1, stdin);
    str[strcspn(str, "\n")] = '\0';

    tiraVogais(str, str2, num);

    printf("String sem vogais: %s", str2);

    free(str);
    free(str2);
    return 0;
}


//Ex5
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *num=NULL;
    int i=0, cont=0;
    int val=1;

    while (val>=0){

        printf("Digite o valor %d do vetor: ", cont+1);
        scanf("%d", &val);     
        num= (int *) realloc(num, (cont+1)*sizeof(int));
        if (num == NULL)
        {
            printf("Erro! Memoria insuficiente!\n");
            system("pause");
            exit(1);
        }

        num[cont] = val;
        cont++;
    }

    printf("Vetor lido: ");
    for ( i = 0; i < cont-1; i++)
    {
        printf("%d ", num[i]);
    }
    

    free(num);
    return 0;
}

//Ex6
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vet;
    int i;

    vet = (int *) calloc(500, sizeof(int));
    if (vet == NULL)
    {
        printf("Erro! Memoria insuficiente!\n");
        system("pause");
        exit(1);
    }
    for ( i = 0; i < 500; i++)
    {
        if(vet[i]!=0){
        printf("Vetor no ponto %d eh diferente de zero!\n", i);
        } 
    }   
    printf("Primeiros e ultimos elementos: \n");
    for ( i = 0; i < 500; i++)
    {
        vet[i]=i;
        if(i<10 || i>=490) printf("Elemento %d: %d\n", i, vet[i]);
    }

    free(vet);
    return 0;
}