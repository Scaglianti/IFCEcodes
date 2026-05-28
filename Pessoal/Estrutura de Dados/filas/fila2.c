#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento
{
    char arquivo[20];
    char nome[20];
    struct elemento* prox;
}Lista;

typedef struct fila
{
    Lista* inicio;
    Lista* fim;
}Fila;

void cria(Fila* f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

int vazio(Fila* f)
{
    return (f->inicio == NULL);
}

void adicionar(Fila* f, char* n, char* a)
{
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if(novo == NULL)
    {
        exit(1);
    }

    strcpy(novo->arquivo,a);
    strcpy(novo->nome,n);
    novo->prox = NULL;
    
    if(vazio(f))
    {
        f->inicio = novo;   
        f->fim = novo;   
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void retira(Fila* f)
{
    if(vazio(f))
    {
        printf("Nada a ser retirado! Lista vazia\n");
        return;
    }
    Lista* aux = f->inicio;
    printf("----Informacoes----\nUsuario: %s\nArquivo: %s\n\n", aux->nome,aux->arquivo);
    f->inicio = aux->prox;
    if(f->inicio == NULL)
    {
        f->fim = NULL;
    }
    free(aux);
}

void imprimir(Fila* f)
{
    Lista* p = f->inicio;
    if(vazio(f))
    {
        printf("Fila vazia para impressao!\n");
    }

    while(p != NULL)
    {
        printf("----Informacoes----\nUsuario: %sArquivo: %s\n\n", p->nome,p->arquivo);
        p = p->prox;
    }
    //esvaziar(f);
}

void esvaziar(Fila* f)
{
   Lista* aux = f->inicio;

    while(f->inicio != NULL)
    {
        f->inicio = aux->prox;
        free(aux);
        aux = f->inicio;
    }
}

int main()
{
    Fila* f;
    cria(f);
    char usu[20];
    char arq[20];
    int validar = 1;
    int menu;

    while(validar)
    {
        printf("Informe o nome do usuario e o nome do arquivo: \n");
        fgets(usu,sizeof(usu),stdin);
        fgets(arq,sizeof(arq),stdin);
       

        adicionar(f,usu,arq);

        printf("Informe o que deseja fazer agora:\nAdicionar um novo nome - 1\nImprimir o primeiro da fila - 2\nImprimir todos da fila - 3\nFechar o programa - 4\n");
        scanf("%d", &menu);
        getchar();

        switch(menu)
        {
            case 1:
            continue;
            break;
            case 2:
            retira(f);
            break;
            case 3:
            imprimir(f);
            break;
            case 4:
            printf("Encerrando o sistema...");
            validar = 0;
            break;
        }
    }
}