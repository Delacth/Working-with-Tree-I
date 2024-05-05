#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "sistema.c"

int main()
{
     setlocale(LC_ALL, "Portuguese");
     bst* no = inicializar();
     bst * pes = inicializar();

	no = inserirProduto(no,"kiko", 10, 9);
     no = inserirProduto(no,"Henrique Mendes", 16, 2);
     no = inserirProduto(no,"Ludmar ", 50, 11);
     no = inserirProduto(no,"Margarida ", 14, 4);
     no = inserirProduto(no,"Avandia", 14, 17);
     no = inserirProduto(no,"Julia", 14, 5);
     no = inserirProduto(no,"Hirondina", 14, 1);
     no = inserirProduto(no,"José Carlos", 14, 10);
     print_preordem(no);

   // pes = procurarProduto(no, 1);
	/*if(pes != NULL){
	 	printf("Valor encontrado");
	}*/

     pes = antecessorNo(no,10);
     if(pes != NULL){
          printf("\n ID: %d", pes->id);
          printf("\n Descrição: %s", pes->descricao);
          printf("\n Quantidade: %d",pes->quantidade);
     }

    // no = remocaoProduto(no,16);
     //printf("\n");
     //print_preordem(no);
    return 0;
}
