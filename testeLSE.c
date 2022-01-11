#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencialEstatica.h"



struct aluno alu;

void cadastra_aluno(struct aluno* al){
    printf("\nMatricula:\t:");
    scanf("%d",&al->matricula);
    printf("\nNome:\t");
    scanf(" %[^\n]",al->nome);
 //   gets((*al).nome);
    printf("\nNota 1:\t");
    scanf("%f",&al->n1);
    printf("\nNota 2:\t");
    scanf("%f",&al->n2);
    printf("\nNota 3:\t");
    scanf("%f",&al->n3);
}

void imprime_aluno(struct aluno al){
        printf("\n\n#######################################");
        printf("\nMatricula:\t%d",al.matricula);
        printf("\nNome:\t%s",al.nome);
        printf("\nNota 1:\t%0.2f",al.n1);
        printf("\nNota 2:\t%0.2f",al.n2);
        printf("\nNota 3:\t%0.2f",al.n3);
        printf("\n#########################################\n");
}
void menu(){
    printf("\n************************************");
    printf("\n*                                  *");
    printf("\n*   1 - Cadastrar novo aluno.      *");
    printf("\n*   2 - Pesquisar por matricula.   *");
    printf("\n*   3 - Remover aluno.             *");
    printf("\n*   4 - Imprimir lista.            *");
    printf("\n*   5 - Exit.                      *");
    printf("\n*                                  *");
    printf("\n************************************\n");
}


int main(){
    
    Lista *li = cria_lista();
   
    int op = 0;

    while(op != -1){
        int mat;
        menu();
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            if(lista_cheia(li)){
                printf("\nA lista esta cheia");
                return 0;
            }
            cadastra_aluno(&alu);
            if(insere_lista_ordenada(li, alu)){
                printf("\nAluno cadastrado !");
            }else{
                printf("\nErro ao cadastrar aluno !");
            }
        break;

        case 2:
            printf("\nDigite o numero da matricula:\t");
            scanf("%d",&mat);
            if(consulta_lista_mat(li,mat,&alu)){
                imprime_aluno(alu);
            }else{
                printf("\nErro: aluno nao encontrado !");
            }
        break;

        case 3:
            printf("\nDigite o numero da matricula:\t");
            scanf("%d",&mat);
            if(remove_lista(li, mat)){
                printf("\nAluno removido !");
            }else{
                printf("\nErro na remoção !");
            }
        break;

        case 4:
            if(lista_vazia(li)){
                printf("\nA Lista esta vazia !");
            }else{
                for(int i = 0; i < tamanho_lista(li); i++){
                    consulta_lista_pos(li,i,&alu);
                    imprime_aluno(alu);
                }
            }
        break;

        case 5: 
            libera_lista(li);
            op = -1;
        break;

        default:
            printf("\nOpção invalida !!");
            break;
        }
    }
    return 0;
}