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
    return 0;
}
