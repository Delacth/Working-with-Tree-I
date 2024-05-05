#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sistema.h"

typedef struct no{
    char descricao[30];
    int quantidade;
    int id;
    struct no *dir, *esq;
}bst;

bst * inicializar(){
    return NULL;
}

bst *inserirProduto(bst *no, char *descricao, int quantidade, int id) {
    bst *novoProduto = (bst*)malloc(sizeof(bst));
    if (novoProduto) {
        novoProduto->quantidade = quantidade;
        strcpy(novoProduto->descricao, descricao);
        novoProduto->id = id;
        novoProduto->esq = NULL;
        novoProduto->dir = NULL;

        if (no == NULL) {
            return novoProduto;
        } else {
            bst *aux = no;
            bst *aux2 = NULL;

            if(procurarProduto(no, id) != NULL){
                printf("\nJá existe um produto com esse ID.");
                printf("\nDigite outro Id.");
                return NULL;
            }else{
                while (aux != NULL) {
                aux2 = aux;
                if (novoProduto->id > aux->id) {
                    aux = aux->dir;
                } else {
                    aux = aux->esq;
                }
            }
            

            }
             if (novoProduto->id > aux2->id) {
                aux2->dir = novoProduto;
            } else {
                aux2->esq = novoProduto;
            }

           
        }
    } else {
        printf("\n Erro de Alocação");
    }
    return no;
}

bst * procurarProduto(bst *no, int id){
     if(no == NULL){
        printf("\nÁrvore vazia!\n");
        return NULL;
    }else{
     bst * aux = no;
	 while(aux != NULL && aux->id != id){
		if(aux->id > id){
		  	aux= aux->esq;
		  }else{
			  aux = aux->dir;
		  }					 			
	 }
	 
	 if(aux->id == id){
		 return aux;
		 
	 }else{
	 	return NULL;
	 }}
}

bst * antecessorNo(bst *no, int id){
    if(no == NULL){
        printf("\nÁrvore vazia!\n");
        return NULL;
    }else{
        bst * aux = no;
        bst * aux2 = NULL;

        while (aux != NULL && aux->id != id)
        {
            if(aux->id > id){
                aux2 = aux;
                aux = aux->esq;
            }else{
                aux2 = aux;
                aux = aux->dir;           
            }
        }
        if(aux->id == id){
            return aux2;
        }else{
            return NULL;
        }
                
    }
}



bst * remocaoProduto(bst *no, int id){
    if(no == NULL){
        printf("\nÁrvore vazia!\n");
        return NULL;
    } else {
        if(no->id == id){
            //* 1º Caso: Folha
            if(no->esq == NULL && no->dir == NULL){
                free(no);
                return NULL;
            } else if(no->esq == NULL || no->dir == NULL) {
                //* 2º Caso: 1 Filho
                bst * aux = (no->esq != NULL) ? no->esq : no->dir;
                free(no);
                return aux;
            } else {
                
                //* 3º Caso: 2 Filhos
                bst * aux = no->esq;
                while(aux->dir != NULL){
                    aux = aux->dir;
                }
                no->id = aux->id;
                no->quantidade = aux->quantidade;
                strcpy(no->descricao, aux->descricao);
                aux->id = id;
                no->esq = remocaoProduto(no->esq, id);
                return no;
            }
        } else {
            if(id < no->id){
                no->esq = remocaoProduto(no->esq, id);
            } else {
                no->dir = remocaoProduto(no->dir, id);
            }
            return no;
        }
    }
}


void print_preordem(bst* no){
	if (no != NULL){
		printf("%s ", no->descricao);
		print_preordem(no->esq);
		print_preordem(no->dir);
	}
}

void menuPrincipal(){
    int loop;
    char descricao[30];
    int id, quantidade;
    int opcaoUsuario = -1;
    bst* no = inicializar();
   

    do{
        printf("\n0 - Sair do Programa\n1 - Inserir Produto\n2 - Pesquisar Produto\n3 - Remover Produto\n4 - Retornar o Antecessor\n5 - Beco sem saída");
        scanf("%d", &opcaoUsuario);
        switch (opcaoUsuario)
        {
        case 0:
            //* Sair do Programa */
            printf("\n Saindo do Programa....\n");
            break;
        case 1:   
                //* Inserir o Produto na Árvore*/  
                 id =-1, quantidade = -1;
                 strcpy(descricao, " ");
                printf("\nDigite a Descrição do Produto: ");
                scanf("%29s", descricao);
                do{
                    printf("\nDigite o ID do Produto: ");
                    scanf("%d", &id);
                }while(id<0);

                do{
                    printf("\nDigite a Quantidade do Produto: ");
                    scanf("%d", &quantidade);
                }while(quantidade < 0);
                no = inserirProduto(no,descricao,quantidade,id);
                printf("\nProduto Inserido com Sucesso.....");
                sleep(4);
            break;
        case 2:
            //* Pesquisar Produto */
            loop = 0;
            do{
                bst * aux = inicializar();
                int id;
                do{
                    printf("\n Digite o ID do Produto: ");
                    scanf("%d", &id);  
                }while(id < 0);

                aux = procurarProduto(no, id);
                if(aux != NULL){
                    int respostaUser;
	 	            printf("\nValor encontrado");
                    printf("\n Descrição:  %s",aux->descricao);
                    printf("\n ID: %d",aux->id);
                    printf("\n Quantidade: %d",aux->quantidade);

                    do{
                        printf("\nDeseja pesquisar outro Produto [1-Sim | 2-Não ]: ");
                        scanf("%d", &respostaUser);
                    }while(respostaUser != 1 || respostaUser != 2); 

                    if(respostaUser != 1){
                       loop = -1;     
                    }   

	            }else{
                    printf("\nValor não encontrado");
                }
            }while(loop == 0);    
            break;
        case 3:
            //* Remover Produto
           
            /*
            do{
                int idUser;
                do{
                    printf("Digite o ID do prduto que deseja eliminar: ");
                    scanf("%d", &idUser);
                }while(idUser<0);


                
            }while(loop == 0);
            break;
            */
            break;
        case 4:
            printf("\nDigite o ID: ");
            break;
        case 5:
            printf("Digite o ID: ");
            break;
        
        default:
            printf("\nOpcão Inválida....\n");
            break;
        }
    }while(opcaoUsuario != 0);
}