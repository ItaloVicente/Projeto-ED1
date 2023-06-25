#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"
#include "AVLTree.h"
#include "ListaDinEncad.h"
int main()
{
    printf("0");
    Hash *ha= cria_hash(10);
    ArvAVL *teste = cria_AVL(85);
    int x = insereHash_EncSep(ha,teste );
    ArvAVL *teste2 = buscaHash_EncSep(ha,85);
    printf("vrua");
    char *nome1 = "Italo Vicente";
    char *endereco1="Rua 7";
    printf("1");
    struct telefone *telefone = cria_telefone(997335674,nome1,endereco1);
    printf("%s", (*telefone).nome);
    int z = insere_ArvAVL(teste,telefone);
    printf("%i",z);
    return 0;
}
