/*
    Nome: Gustavo Schwanka
    GRR20193748
    Estrutura de Dados 2
    Checagem de Árvores Binárias de Busca



    Imaginando esta estrutura de árvore:
    typedef struct arvore {
        int info;
        struct arvore *esq;
        struct arvore *dir;
    } Arvore;
*/

int arv_bin_check(Arvore * a){
    // 1 é binária de busca e 0 não é.
    if(arv_bin_bus(a)){
    return 1;
    }else{
    return 0;
    }
}
boolen arv_bin_bus(Arvore * a){
    /*
    Essa função verifica se todos os nós da arvore estão em ordem, ou seja, se essa arvore é binária de busca
    */
    boolean manteve = true; // defino o valor para verificação padrão. Se alterado, ela não é binária de busca.
    if((a->esq != NULL) & (a->dir !=NULL)){ // verifico se é folha
        if(a->esq !=NULL){ // se tem filho, verifica se tem a esquerda
            if(a->esq->info < a->info){ // se tem a esq e for menor
               manteve = arv_bin_check(a->esq); // chama a mesma função para verificar esse nó filho.
            }else{ // se for maior, não é arvore binária de busca
                return false; // retorna que a arvore não é.
            }
        }if(manteve){ //se não tem filho a esq, ou ele verificou e se manteve como arvore binária de busca.
            if(a->dir !=NULL){
                if(a->dir->info >= a->info){ // verifica se o da direita é maior OU IGUAL
                    manteve = arv_bin_check(a->dir);// E chama a função recursivamente para o filho da direita
                    if(manteve){ // se ambos os filhos passaram no teste
                        return true; // retorna true;
                    }
                }else{ // se for menor, não é arvore binária de busca.
                    return false; // então retorna que a arvore não é
                }
            }
        }else{ // se, o filho da esquerda retornou false e por isso alterou a variável manteve de true ( padrão ) para false,
            return false; // então não precisa verifica, a arvore não é retorna false dizendo que não é.
        }
    }else{ // se é folha,
        return true; //então returna true.
    }
    return true; // se esquerda e não tinha elemento à direita, retorna true.
}
