#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
//#include "AVLTree.h"
#include <string.h>
Lista *cria_lista(){
    Lista *li = (Lista *) malloc(sizeof(Lista));
    if( li != NULL)
        li = NULL;
    return li;
}
void libera_lista(Lista *li){
    if(li!=NULL){
        ElemLista *no;
        while ((*li)!=NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}
int tamanho_lista(Lista *li){
    if(li == NULL){
        return 0;
    }
    int cont = 0;
    ElemLista *no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}
int insere_lista_inicio(Lista *li, struct telefone *al){
    if(li==NULL){
        return 0;
    }
    ElemLista *no;
    no = (ElemLista*) malloc(sizeof(ElemLista));
    if(no==NULL){
        return 0;
    }
    no->dados=(*al);
    no->prox = (*li);
    *li = no;
    int i =1;
    return i;
}
int insere_lista_final(Lista *li, struct telefone al){
    if(li==NULL)
        return 0;
    ElemLista *no;
    no = (ElemLista *) malloc(sizeof(ElemLista));
    if(no==NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li)==NULL){
        *li =no;
    }else{
        ElemLista *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox=no;
    }
    return 1;
}
/*
int insere_lista_ordenada(Lista *li, struct telefone *al){
    if(li==NULL){
        return 0;
    }
    Elem *no;
    no = (Elem *) malloc(sizeof(Elem));
    if(no==NULL){
        return 0;
    }
    no->dados=(*al);
    if((*li)==NULL){
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.nome < (*al).nome){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li=no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}
*/
void ordernarLista(Lista *li){
    if(li==NULL || *li == NULL)
        return;
    ElemLista *no=*li;
    ElemLista *atual = *li;
    while(atual->prox!=NULL){
        while(no->prox!=NULL){
            if(strcmp(no->dados.nome,no->prox->dados.nome)>0){
                if(no==(*li))
                    *li=no->prox;
                struct telefone temp = no->dados;
                no->dados=no->prox->dados;
                no->prox->dados=temp;
            }
            no=no->prox;
        }
        no=(*li);
        atual=atual->prox;
    }
    return;
}





