#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"
//#include "AVLTree.h"

//criação da estrutura da tabela hash:
Hash *cria_hash(int TABLE_SIZE){ //função de criação da tabela hash
    Hash *ha = (Hash*) malloc(sizeof(Hash)); //alocação de memória
    if(ha!=NULL){//se o ponteiro não apontar para o NULL:
        int i;
        ha->TABLE_SIZE=TABLE_SIZE; //inicializa os atributos da tabela
        ha->cis= (Elem**) malloc(TABLE_SIZE * sizeof(Elem*));//aloca memória para o ponteiro
        if(ha->cis==NULL){//caso a memória não tenha sido alocada com sucesso, libera a tabela hash
            free(ha);
            return NULL;//retorna NULL
        }
        ha->qnt=0;//inicializa o parâmetro qnt=0, como sendo a quantidade de elementos da tabela hash=0
        for(i=0;i<ha->TABLE_SIZE;i++)//percorre a tabela inicializando o ponteiro para  NULL
            ha->cis[i]=NULL;
    }
    return ha; //retorna a tabela hash criada
}
void liberaHash(Hash *ha){//função para liberar a memória alocada 
    if(ha!=NULL){//caso o ponteiro não aponte para NULL, entra no if
        for(int i=0; i<ha->TABLE_SIZE;i++){ //percorre a tabela hash
            if(ha->cis[i]!=NULL){ // se o ponteiro cis não tiver NULL
                free(ha->cis[i]); //libera os índices do ponteiro
            }
        }
        free(ha);//libera a tabela hash
        free(ha->cis);  //libera o ponteiro cis da tabela hash
    }
}
int valor(int key, int tableSize){//função que transforma uma chave em um valor, ou índice tabela. 
    return key % tableSize; //retorna o valor
}
int insereHash_EncSep(Hash *ha, ArvAVL *raiz1){ // função inserir elemento na tabela hash, usando tratamento de colisão encadeamento separado
    if(ha==NULL||ha->qnt==ha->TABLE_SIZE) //verifica se a alocação ta bela está ok ou se a tabela está cheia
        return 0; //para os dois casos retorna-se 0, pois não tem como inserir
    int pos = valor((*raiz1)->DDD,ha->TABLE_SIZE);  //usa a função valor para encontrar a posição da tebal que será endereçado o elemento
    if(ha->cis[pos]!=NULL){//Se a posicao calculada nao estiver vazia
        Elem *atual = ha->cis[pos]; //cria um ponteiro para percorrer aquela lista encadeada presente naquela posição
        while(atual->prox!=NULL){//Acho o ultimo elemento da pos que esta ocupada (podem ter acontecidos varios choques, isso formaria uma lista)
            atual=atual->prox; //percorre a lista dinâmica até o último elemento
        }
        Elem *novo=(Elem*) malloc(sizeof(Elem));//aloca memória para o novo elemento a ser inserido
        if(novo==NULL) //caso a alocação não seja bem sucedida, retorna NULL:
            return 0;
        novo->prox=NULL; //se a alocação for bem sucedida, inicializa seus paraâmetros
        novo->raiz =(*raiz1);
        atual->prox=novo; //Faco o ultimo elemento agora apontar pra raiz inserida, e a raiz sera o ultimo elemento
        ha->qnt++;//Faco o ultimo elemento agora apontar pra raiz inserida, e a raiz sera o ultimo elemento
        return 1;//tudo certo, retorna 1
    }
    else{//Se a posicao calculada estiver vazia, aloca a memória para a estrutura
        Elem *novo=(Elem*) malloc(sizeof(Elem));
        if(novo==NULL) //se a alocação não for bem sucedida, retorna 0
            return 0;
        novo->prox=NULL;//caso contrário, inicializa seus atributos
        novo->raiz =(*raiz1);
        ha->cis[pos]=novo;
        ha->qnt++; //atualiza a quantidade de elementos da tabela hash
        return 1; //tudo certo, retorna 1
    }
    
    return 0; //para qualquer outro caso, retorna 0
}
ArvAVL *buscaHash_EncSep(Hash *ha, int DDD){ //função de busca um elemento na tabela hash
    if(ha==NULL)
        return NULL; //retorna NULL em caso de problema com a tabela hash
    int pos;
    pos = valor(DDD,ha->TABLE_SIZE);
    if(ha->cis[pos]!=NULL){//Se a posicao estiver ocupada entro na busca nessa posicao
        Elem *atual = ha->cis[pos];//se a posição não tiver vazia, entra no if
        if(atual->raiz->DDD==DDD){//Achei o elemento e é o da própria posicao
                printf("raiz encontrada!!\n");
                ArvAVL *raiz = &(atual->raiz);//cria um ponteiro para o endereço do numero encontrado, chamado raiz
                return raiz; //retorna raiz
            }
        while(atual->prox!=NULL){//Procuro a raiz passada como parametro
            if(atual->raiz->DDD==DDD){//Achei o elemento
                printf("raiz encontrada!!\n");
                ArvAVL *raiz = &(atual->raiz);
                return raiz;
            }
            atual=atual->prox;//não achou o elemento, então percorre
        }
    }
    printf("raiz nao encontrada!!\n");
    return NULL;//Se passar pelos if significa que o elemento nao foi encontrado
}
int removeDoHash(Hash *ha, ArvAVL *raiz1){ //função de remoção do elemento da tabela hash
    if(ha==NULL) //se a tabela não foi alocada, retorna 0
        return 0;
    int pos;
    pos = valor((*raiz1)->DDD,ha->TABLE_SIZE);//função valor para encontrar a posição do elemento
    if(ha->cis[pos]!=NULL){//Se a posicao estiver ocupada entro na busca nessa posicao
        Elem *atual = ha->cis[pos]; //criação de um ponteiro para percorrer a tabela
        Elem *ant = NULL; //ponteiro para auxiliar a percorrer a tabela
        if(atual->raiz->DDD==(*raiz1)->DDD){//Achei a raiz
                libera_ArvAVL(&(atual->raiz));//Libero o atual
                printf("Elemento removido!!");
                ha->qnt--; //atualiza a quantidade
                return 1;//retorna 1 caso tudo dê certo até aqui
            }
        while(atual->prox!=NULL){//Procuro a raiz passada como parametro
            if(atual->raiz->DDD==(*raiz1)->DDD){//Achei a raiz
                ant->prox=atual->prox;//o anterior.rox agora vai apontar para o atual.prox, para que eu nao deixe nenhum elemento perdido
                libera_ArvAVL(&(atual->raiz));//Libero o atual
                printf("Elemento removido!!");
                ha->qnt--; //atualiza a quantidade
                return 1;//retorna 1 caso tudo dê certo até aqui
            }
        }
    }
    return 0;//Se passar pelos if significa que o elemento nao foi encontrado
}