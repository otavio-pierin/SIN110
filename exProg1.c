#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct produto
{
    char nome[50];
    float preco;
}Produto;

//função para escrever no arquivo 
void escreverArquivo(FILE *arquivo, int numProdutos, Produto *produto){
    for (int i = 0; i < numProdutos; i++)
    {
        printf("Produto %d\n", i+1);
        printf("Insira o nome do produto: ");
        fgets(produto[i].nome, sizeof(produto[i].nome), stdin);

        // Remover o caractere de nova linha ('\n') do final da string
        if (strlen(produto[i].nome) > 0 && produto[i].nome[strlen(produto[i].nome) - 1] == '\n') {
            produto[i].nome[strlen(produto[i].nome) - 1] = '\0';
        }

        printf("Insira o preco do produto: ");
        scanf("%f",&produto[i].preco);
        getchar();
    }

    for (int i = 0; i < numProdutos; i++)
    {
        fprintf(arquivo, "%s %.2f\n", produto[i].nome, produto[i].preco);
    }
    
}

void renomearArquivo(char *nomeAntigo, char *nomeNovo){
    if (rename(nomeAntigo, nomeNovo)==0)
    {
        printf("Arquivo renomeado com sucesso!");
    }else{
        printf("Erro ao renomear arquivo!");
    }
}

//lê linha por linha do arquivo
void lerArquivo(FILE *arquivo, Produto *produto, float *total){
    // Lê o arquivo linha por linha
    int cont=0;
    while (fscanf(arquivo, "%s %f", produto[cont].nome, &produto[cont].preco) != EOF) {
        *total += produto[cont].preco;
        cont++;
    }

    fclose(arquivo);
} 


int main(){
    FILE *arquivo;
    Produto *produto;
    char nome[50];
    int n;
    float total;

    //alocação dinâmica
    printf("Insira a quantidade de produtos a serem cadastrados: ");
    scanf("%d", &n);
    getchar();    
    produto = (Produto *) malloc(n*sizeof(Produto));
    if (produto == NULL)
    {
        printf("Erro! Memória insuficiente!");
        free(produto);
        exit(1);
    }

    //abrindo o arquivo
    printf("Nome do arquivo: ");
    fgets(nome, sizeof(nome), stdin);
    // Remover o caractere de nova linha ('\n') do final da string
    if (strlen(nome) > 0 && nome[strlen(nome) - 1] == '\n') {
        nome[strlen(nome) - 1] = '\0';
    }
    arquivo = fopen(nome, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }  

    escreverArquivo(arquivo, n, &produto[0]);

    fclose(arquivo);

    //ler arquivo e calcular total
    arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }     
    lerArquivo(arquivo, &produto[0], &total);

    // Exibe o total da compra
    printf("Total da compra: R$ %.2f\n", total);

    //renomear arquivo
    int renomear; 
    printf("Deseja renomear o arquivo (1 - sim  | 0 - nao): ");
    scanf("%d", &renomear);
    if (renomear == 1)
    {
        char nomeNovo[50];
        printf("Insira o novo nome para o arquivo: ");
        fgets(nomeNovo, sizeof(nomeNovo), stdin);
    // Remover o caractere de nova linha ('\n') do final da string
    if (strlen(nomeNovo) > 0 && nomeNovo[strlen(nomeNovo) - 1] == '\n') {
        nomeNovo[strlen(nomeNovo) - 1] = '\0';
    }        
        renomearArquivo(nome, nomeNovo);
    }

    free(produto);    

	return 0;	
}
