#ifndef AVLTREE_H
#define AVLTREE_H
typedef struct NO *ArvAVL;
struct NO{
    int DDD;
    struct telefone *info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};
struct telefone{
    int numero;//sem DDD
    char *nome;
    char *endereco;
};
int sugerirNumeroMaior(struct NO* atual);
int sugerirNumeroMenor(struct NO* atual);
ArvAVL *cria_AVL(int DDD);
struct telefone *cria_telefone(int numero1, char *nome1, char *endereco1);
void libera_NO(struct NO* no);
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, struct telefone *valor);
int remove_ArvAVL(ArvAVL *raiz, struct telefone *valor);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);
int removeTelefoneNome(ArvAVL *raiz, char *nome1);
void ListaEmNumeroCrescente(ArvAVL *raiz);
void ListaEmOrdemAlfabetica(ArvAVL *raiz);
void buscaAproximada(ArvAVL *raiz, int numeroMenor);
int verificaNome(ArvAVL *raiz, struct telefone *valor);
int inserir_checando_nome(ArvAVL *raiz, struct telefone *valor);
struct telefone *procurar_telefone(ArvAVL *raiz, int numero);//retorna o telefone a partir e um numero e uma raiz passada como parametro, voce pode usar para achar nome e endereco da pessoa
#endif