typedef struct no bst;

bst * inicializar();
bst * inserirProduto(bst *no, char *descricao, int quantidade, int id);
bst * procurarProduto(bst *no, int id);

bst *remocaoProduto(bst *no, int id);
bst * antecessorNo(bst *no, int id);
void procurarBeco(bst *no);

void print_preordem(bst* no);
void menuPrincipal();
