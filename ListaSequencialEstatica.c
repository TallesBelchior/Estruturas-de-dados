#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencialEstatica.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL){
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int tamanho_lista(Lista* li){
    if(li ==NULL){
        return -1;
    }else{
        return li->qtd;
    }
}

//Return -1 - ERRO
//        0 - Vazia
//        1 - Cheia
int lista_cheia(Lista* li){
    if(li == NULL){
        return -1;
    }
    return (li-> qtd == MAX);//true = 1 /false = 0
}

//Retorna 1 se a lista estiver vazia
int lista_vazia(Lista* li){
    if(li == NULL){
        return -1;
    }
    return (li->qtd == 0);//1
}

//1 - Sucess
//0 - Lista cheia
//-1 - ERROR
int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL){
        return -1;
    }
    if(lista_cheia(li)){
        return 0;
    }
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL){
        return -1;
    }
    for(int i = li->qtd;i != 0;i--){
        li->dados[i+1] = li->dados[i];
    }
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL){
        return -1;
    }
    if(lista_cheia(li)){
        return 0;
    }
    int j, i = 0;
    while(i < li->qtd && li->dados[i].matricula < al.matricula){
        i++;
    }
    for(j = li->qtd; j >= i; j--){
        li->dados[j] = li->dados[j-1];
    }
    li->dados[i] = al;
    li->qtd++;
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL){
        return -1;
    }
    if(li->qtd == 0){
        return 0;
    }
    li->qtd--;
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL){
        return -1;
    }if(lista_vazia(li)){
        return 0;
    }
    for(int i = 0;i != li->qtd-1;i++){
        li->dados[i] = li->dados[i+1];
    }
    li->qtd++;
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL){
        return -1;
    }
    if(lista_cheia(li)){
        return 0;
    }
    int j, i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)
        return 0;
    for(j = i; j <= li->qtd-1; j++){
        li->dados[j] = li->dados[j+1];
    }
    li->qtd--;
    return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos < 0 || pos > li->qtd){
        return -1;
    }if(lista_vazia(li)){
        return 0;
    }
    *al = li->dados[pos];
    return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
   if(li == NULL){
        return -1;
    } 
    for(int i = 0; i != li->qtd; i++){
        if(li->dados[i].matricula == mat){
            *al = li->dados[i];
            return 1;
        }
    }
    return 0;
}


/*
int imprime_lista(Lista* li){
    if(lista_vazia(li))return 0;
    for(int i = 0; i <= li->qtd-1; i++){
        printf("\n\n#######################################");
        printf("\nMatricula:\t%d",li->dados[i].matricula);
        printf("\nNome:\t%s",li->dados[i].nome);
        printf("\nNota 1:\t%0.2f",li->dados[i].n1);
        printf("\nNota 2:\t%0.2f",li->dados[i].n2);
        printf("\nNota 3:\t%0.2f",li->dados[i].n3);
        printf("\n#########################################");
    }
    return 1;
}
*/