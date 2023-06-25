#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
#include "AVLTree.h"
#include <string.h>

Lista *cria_lista(){ //função para criar a lista alocando memória 
    Lista *li = (Lista *) malloc(sizeof(Lista)); //alocação da memória
    if( li != NULL) //se a lista não apontar para NULL, faz ela apontar para NULL. Significa que ela inicia vazia
        li = NULL;
    return li;//por fim, retorna a lista 
}
void libera_lista(Lista *li){ //função para liberar a meória alocada
    if(li!=NULL){ //se a lista não estiver apontando para NULL, ou sjea, não está vazia
        ElemLista *no; //cria um ponteiro auxiliar no para auxiliar a remoção do último elemento, até o primeiro
        while ((*li)!=NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li); //após a liberação de todos os elementos da lista, libera a lista
    }
}
int tamanho_lista(Lista *li){ //função que retorna o tamanho da lista
    if(li == NULL){ //problema com a lista, retorna 0, não tem elemento. 
        return 0;
    }
    int cont = 0; //inicializa um contador
    ElemLista *no = *li; //criação de um ponteiro auxiliar para contagem dos elementos da lista
    while(no != NULL){ //enquanto houver elementos na lista, o contador é incrementado
        cont++; //atualiza o contador
        no = no->prox; //percorrendo a lista enquanto não for o último elemento.
    }
    return cont;//por fim, retorna a quantidade do contador
}
int insere_lista_inicio(Lista *li, struct telefone *al){ //função para inserir elemento no início da lista
    if(li==NULL){ //problema com a lista
        return 0;//retorna 0
    }
    ElemLista *no; //cria um nó e aloca memória para ele, que será o local do novo elemento
    no = (ElemLista*) malloc(sizeof(ElemLista));
    if(no==NULL){ //alocação deu erro, retorna 0
        return 0;
    }
    no->dados=(*al);//caso a alocação seja bem sucedida, inicializa os parâmetros da estrutura ou elemento
    no->prox = (*li); //atualiza os ponteiros
    *li = no; //atualiza os ponteiros
    int i =1; //criação de uma variável somente para retorna caso tenha sido tudo bem sucedido
    return i; //retorna 1 se foi bem sucedido
}
int insere_lista_final(Lista *li, struct telefone al){ //função de inserir um elemento no final da lista
    if(li==NULL)//problema com a lista, retorna 0
        return 0;
    ElemLista *no; //criação de um ponteiro nó e alocação de memoria para ele, que será o novo elemento
    no = (ElemLista *) malloc(sizeof(ElemLista));
    if(no==NULL)//se a alocação deu erro, retorna 0
        return 0;
    no->dados = al;//caso a alocação tenha dado certo, inicializa os parâmetros.
    no->prox = NULL; //como último elemento da lista, o ponteiro vai apontar para NULL
    if((*li)==NULL){ //se a lista está vazia, só atualiza o ponteiro da lista para apontar para o elemento novo
        *li =no;
    }else{//caso a lista não esteja vazia, é criado um ponteiro aux para percorrer a lista
        ElemLista *aux;
        aux = *li;
        while(aux->prox != NULL){//enquanto não for o ultimo elemento da lista, ele percorre atualizando para o proximo
            aux = aux->prox;
        }
        aux->prox=no; //achou o último elemento, atualiza o ponteiro dele para apontar para o novo elemento
    }
    return 1;//tudo certo, retorna 1
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
void ordernarLista(Lista *li){ //função de ordenação da lista
    if(li==NULL || *li == NULL) //se a lista não tiver sido alocada ou estiver vazia não tem o que ordenar
        return;
    ElemLista *no=*li; //criação e alocação de um nó que aponta para onde o ponteiro lista aponta
    ElemLista *atual = *li; //criação de outro ponteiro que aponta para a lista, criado para comparar as strings e ordenar
    while(atual->prox!=NULL){ //enquanto não chega no final da lista
        while(no->prox!=NULL){//enquanto não chega no fim da lista
            if(strcmp(no->dados.nome,no->prox->dados.nome)>0){ //uso da função strcmp para compara as strings
                if(no==(*li)) 
                    *li=no->prox;
                struct telefone temp = no->dados; //variável temporária para guardar a informação
                no->dados=no->prox->dados; //percorrendo a lista
                no->prox->dados=temp; //atualizando a variável temporária
            }
            no=no->prox; //atualizando o ponteiro no para percorrer a lista
        }
        no=(*li);
        atual=atual->prox; //percorrendo a lista com o atual
    }
    return;
}





