#include "pila_filha.h"
#include <stdio.h>
int main() {
    
    t_conjunto pilha, fila;
    t_elemento e;
    t_apontador p;
    t_no no;

    int nc, nop, i, j;
    int r_pilha, r_fila, erro_fila=0, erro_pilha=0;
    char op;

    criar_f(&fila);
    criar_p(&pilha);
    scanf("%d", &nc);
    int vet[nc];
    for (i = 0; i < nc; i++) {
        scanf("%d", &nop);
        for (j = 0; j < nop; j++) {
            scanf(" %c %d", &op, &e.chave);
            if(op=='i'){
                empilhar(&pilha, e);
                enfileirar(&fila, e);
                //break;
            }
            else if(op=='r'){
                r_pilha = desempilhar(&pilha, e);
                r_fila = desenfileirar(&fila, e);
                //break;
                /*if(r_pilha != e.chave){
                    erro_pilha = 1;
                }
                if(r_fila != e.chave){
                    erro_fila = 1;
                }*/
            }
            else{
                printf("Operador inválido. Digite i ou r.");
            }
            /*if(r_pilha = 1){
                erro_pilha++;
            }
            if(r_fila = 1){
                erro_fila++;
            }*/
            

        }
        printf("caso %d: %d\n", i, r_pilha);
        printf("caso %d: %d\n", i, r_fila);
        printf("caso %d: %d\n", i, erro_fila);
        printf("caso %d: %d\n", i, erro_pilha);
        if (r_fila == 0 && r_pilha == 0) {
            //caso impossível
            printf("impossível");
            break;
        } 
        else if (r_pilha == 0) {
            // pilha
            printf("pilha");
            break;
        }
        else if (r_fila == 0) {
            // fila
            printf("fila");
            break;
        }
        else { 
            //indefinido 
            printf("indefinido");
            break;
        }
        // liberar após cada incrementação 
        libera_f(&fila);
        libera_p(&pilha);

        //cria-se novas ED
        criar_f(&fila);
        criar_p(&pilha);
        erro_fila = 0;
        erro_pilha = 0;
  
    //retornando ao início a cada iteração do for
    }


    return 0;
}
