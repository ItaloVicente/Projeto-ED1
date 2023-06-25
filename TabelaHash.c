#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"
//#include "AVLTree.h"
struct elemento
{
    ArvAVL raiz;
    struct elemento *prox;
};
typedef struct elemento Elem;
struct hash{
    int qnt, TABLE_SIZE;
    Elem **cis;
};
Hash *cria_hash(int TABLE_SIZE){
    Hash *ha = (Hash*) malloc(sizeof(Hash));
    if(ha!=NULL){
        int i;
        ha->TABLE_SIZE=TABLE_SIZE;
        ha->cis= (Elem**) malloc(TABLE_SIZE * sizeof(Elem*));
        if(ha->cis==NULL){
            free(ha);
            return NULL;
        }
        ha->qnt=0;
        for(i=0;i<ha->TABLE_SIZE;i++)
            ha->cis[i]=NULL;
    }
    return ha;
}
void liberaHash(Hash *ha){
    if(ha!=NULL){
        for(int i=0; i<ha->TABLE_SIZE;i++){
            if(ha->cis[i]!=NULL){
                free(ha->cis[i]);
            }
        }
        free(ha);
        free(ha->cis);
    }
}
int valor(int key, int tableSize){
    return key % tableSize;
}
int insereHash_EncSep(Hash *ha, ArvAVL *raiz1){
    if(ha==NULL||ha->qnt==ha->TABLE_SIZE)
        return 0;
    int pos = valor((*raiz1)->DDD,ha->TABLE_SIZE);
    if(ha->cis[pos]!=NULL){//Se a posicao calculada nao estiver vazia
        Elem *atual = ha->cis[pos];
        while(atual->prox!=NULL){//Acho o ultimo elemento da pos que esta ocupada (podem ter acontecidos varios choques, isso formaria uma lista)
            atual=atual->prox;
        }
        Elem *novo=(Elem*) malloc(sizeof(Elem));
        if(novo==NULL)
            return 0;
        novo->prox=NULL;
        novo->raiz =(*raiz1);
        atual->prox=novo;
        ha->qnt++;//Faco o ultimo elemento agora apontar pra raiz inserida, e a raiz sera o ultimo elemento
        return 1;
    }
    else{//Se a posicao calculada estiver vazia
        Elem *novo=(Elem*) malloc(sizeof(Elem));
        if(novo==NULL)
            return 0;
        novo->prox=NULL;
        novo->raiz =(*raiz1);
        ha->cis[pos]=novo;
        ha->qnt++;
        return 1;
    }
    
    return 0;
}
ArvAVL *buscaHash_EncSep(Hash *ha, int DDD){
    if(ha==NULL)
        return NULL;
    int pos;
    pos = valor(DDD,ha->TABLE_SIZE);
    if(ha->cis[pos]!=NULL){//Se a posicao estiver ocupada entro na busca nessa posicao
        Elem *atual = ha->cis[pos];
        if(atual->raiz->DDD==DDD){//Achei o elemento e é o da própria posicao
                printf("raiz encontrada!!\n");
                ArvAVL *raiz = &(atual->raiz);
                return raiz;
            }
        while(atual->prox!=NULL){//Procuro a raiz passada como parametro
            if(atual->raiz->DDD==DDD){//Achei o elemento
                printf("raiz encontrada!!\n");
                ArvAVL *raiz = &(atual->raiz);
                return raiz;
            }
            atual=atual->prox;
        }
    }
    printf("raiz nao encontrada!!\n");
    return NULL;//Se passar pelos if significa que o elemento nao foi encontrado
}
int removeDoHash(Hash *ha, ArvAVL *raiz1){
    if(ha==NULL)
        return 0;
    int pos;
    pos = valor((*raiz1)->DDD,ha->TABLE_SIZE);
    if(ha->cis[pos]!=NULL){//Se a posicao estiver ocupada entro na busca nessa posicao
        Elem *atual = ha->cis[pos];
        Elem *ant = NULL;
        while(atual->prox!=NULL){//Procuro a raiz passada como parametro
            if(atual->raiz->info->numero==(*raiz1)->info->numero){//Achei a raiz
                ant->prox=atual->prox;//o anterior.rox agora vai apontar para o atual.prox, para que eu nao deixe nenhum elemento perdido
                free(atual);//Libero o atual
                printf("Elemento removido!!");
                ha->qnt--;
                return 1;
            }
            ant=atual;//atualizo o ant para ser o antigo atual
            atual=atual->prox;//atualizo o atual para a proxima raiz
        }
    }
    return 0;//Se passar pelos if significa que o elemento nao foi encontrado
}