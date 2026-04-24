#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista* prox;
}Lista;
void lst_imprime(Lista* l)
{
    Lista* p;
    for(p=l;p!=NULL;p=p->prox)
    {
        printf("%d ",p->info);
    }
}
Lista* lst_insere(Lista* l, int valor)
{
    Lista* head = (Lista*) malloc(sizeof(Lista));
    head->info = valor;
    head->prox = l;
    return head;
}

int verifica(Lista* l, int valor)
{
    Lista* p;
    for(p=l;p != NULL && p->info != valor; p = p->prox);
    if(p == NULL)
    {
        return 1; //Caso não tenha mais valores repetidos ele retorna 1
    }
    else
    {
        return 0; //Caso tenha ainda valores repetidos, ele retorna 0
    }
}
Lista* lst_deleta_valores(Lista* l,int valor)
{
    Lista* atual;
    Lista* anterior;
    for(atual = l, anterior = NULL; atual != NULL && atual->info != valor;anterior = atual,atual = atual->prox);
    if(atual == NULL) 
    {
        //Tirei o printf porque é desnecessário na demonstração
    }

    if(anterior == NULL)
    {
        free(atual); //Adicionei um free para liberar essa lista "atual" - xxxxxxxx
        return l->prox; //Caso a anterior seja igual a NULL, quer dizer que o primeiro elemento da lista que foi removido, então "return l->prox"
    }
    else
    {
        anterior->prox = atual->prox;
    }
    free(atual);
    if(!verifica(l,valor))
    {
        l = lst_deleta_valores(l,valor); //Coloquei agora l recebendo essa lista para ficar mais visível - xxxxxxxx
        return l; //Adicionei um retorno aqui, na prova eu tinha me esquecido de retornar a lista nova - xxxxxxxx
    }
    else
    {
        return l; //Corrigi o nome da váriavel que estava na prova, antes estava "inicio" - xxxxxxxx
    }
}

int main()
{
    Lista* lst = NULL;

    lst = lst_insere(lst,1);
    lst = lst_insere(lst,2);
    lst = lst_insere(lst,3);
    lst = lst_insere(lst,4);
    lst = lst_insere(lst,5);

    lst = lst_deleta_valores(lst,3);
    lst_imprime(lst);

    return 0;
}

/*
    Correções nas linhas:
    50;
    60;
    61;
    65
*/