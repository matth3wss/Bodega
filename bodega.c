#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "bodega.h"

bool isEmptyBebidas(Bebida *list){
    if(list==NULL)
        return true;
    return false;
}

bool isEmptyClientes(Cliente *list){
    if(list==NULL)
        return true;
    return false;
}

Cliente *createCliente(int cod, char *nome, char *cpf, int idade, int fiado){
    Cliente *new=malloc(sizeof(Cliente));
    new->cod=cod;
    snprintf(new->nome, sizeof(new->nome), "%s", nome);
    snprintf(new->cpf, sizeof(new->cpf), "%s", cpf);
    new->idade=idade;
    new->fiado=fiado;
    new->next=NULL;
    new->prev=NULL;
    return new;
}

Cliente *searchCliente(lClientes *list, char *cpf){
    Cliente *aux;
    for(aux=list->first; aux!=NULL; aux=aux->next){
        if(strcmp(aux->cpf,cpf)==0){
            return aux;
        }
    }
    return NULL;
}

Bebida *createBebida(int cod, char *nome, float preco, int qtEstoque, int teorAlcolico){
    Bebida *new=malloc(sizeof(Bebida));
    new->cod=cod;
    snprintf(new->nome, sizeof(new->nome), "%s", nome);
    new->preco=preco;
    new->qtEstoque=qtEstoque;
    new->teorAlcolico=teorAlcolico;
    new->next=NULL;
    new->prev=NULL;
    return new;
}

Bebida *searchBebida(lBebidas *list, int cod){
    Bebida *aux;
    if(isEmptyBebidas(list->first)){
        return NULL;
    }
    for(aux=list->first; aux!=NULL; aux=aux->next){
        if(aux->cod == cod)
            return aux;
    }
    return NULL;
}

void compraBebida(lBebidas *list, int cod, int qtd){
    Bebida *aux;
    if(searchBebida(list, cod)==NULL){
        printf("Código inexistente\n");
    }else{
        for(aux=list->first; aux->cod!=cod; aux=aux->next);
        aux->qtEstoque+=qtd;  
    }
    return;
}

// Função adiciona na lista em ordem crescente das idades dos clientes
void addCliente(lClientes *list, Cliente *new){
    Cliente *inicio=list->first, *fim=list->last, *aux;
    //Se a lista estiver vazia, "first" e "last" recebem "new"
    if(isEmptyClientes(list->first)){
        list->first=new;
        list->last=new;
        return;

    // Se "new" for menor que "first" ou igual a "first" vai adicionar no inicio
    }else if(new->idade <= inicio->idade){
        new->next=list->first;
        new->next->prev=new;
        list->first=new;
    // Se "new" for maior que "last" ou igual a "last" vai adicionar no fim
    }else if(new->idade >= fim->idade){
        list->last->next=new;
        new->prev=list->last;
        list->last=new;
    
    //Se new não comprir os requisitos anteriores a inclusão sera feita no meio da lista 
    }else{
        for(aux=list->first; aux!=NULL; aux=aux->next){
                if(new->idade==aux->idade){
                    new->prev=aux->prev;
                    aux->prev->next=new;
                    aux->prev=new;
                    new->next=aux;
                }
                if(new->idade > aux->idade && new->idade < aux->next->idade){
                    new->next=aux->next;
                    aux->next->prev=new;
                    aux->next=new;
                    aux->next->prev=aux;
                }
        }
    }
}

void addBebida(lBebidas *list, Bebida *new){

    if(isEmptyBebidas(list->first)){
        list->first=new;
        list->last=new;
    }else if(searchBebida(list, new->cod)==NULL){
        list->last->next=new;
        list->last->next->prev=list->last;
        list->last=new;
    }else{
        printf("Código já cadastrado\n");
    }
}

void printClientes(Cliente *first){
    Cliente *aux;
    if(isEmptyClientes(first)){
        printf("Lista Vazia!\n");
    }else{
        printf("|======================================================================|\n");
        printf("| Código do Cliente | Nome do Cliente | CPF do Cliente | Idade | Fiado |\n");
        printf("|======================================================================|\n");
        for(aux = first; aux!= NULL; aux=aux->next){
            printf("|%-19d|%-17s|%-16s|%-7d|%-7d|", aux->cod, aux->nome, aux->cpf, aux->idade, aux->fiado);
            printf("\n");
        }
        printf("|======================================================================|\n");
    }
}

void printBebidas(Bebida *first){
    Bebida *aux;
    if(isEmptyBebidas(first)){
        printf("Lista Vazia!\n");
        return;
    }else{
        printf("|==========================================================================|\n");
        printf("| Código da Bebida | Nome da Bebida | Preço | Qtd Estoque | Teor Alcoólico |\n");
        printf("|==========================================================================|\n");
        for(aux = first; aux!= NULL; aux=aux->next){
            printf("|%-18d|%-16s|%-7.2f|%-13d|%-16d|", aux->cod, aux->nome, aux->preco, aux->qtEstoque, aux->teorAlcolico);
            printf("\n");
        }
        printf("|==========================================================================|\n");
    }
}

void criaVenda(lClientes *clientes, lBebidas *bebidas, char *cpf, int cod){
    Bebida *aux, *auxB;
    Cliente *auxC;
    int qtd;    
    auxC=searchCliente(clientes, cpf);
    auxB=searchBebida(bebidas, cod);
    
    if(auxC==NULL){
        printf("Cliente não cadastrado\n");
        return;
    }
    else if(auxB==NULL){
        printf("Bebida não cadastrada\n");
        return;
    }
    else if(auxC->idade < 18 && auxB->teorAlcolico > 0){
        printf("Cliente menor de idade\n");
    }
    printf("Quantas bebidas deseja comprar?\n"); 
        scanf("%d", &qtd);

    for(aux=bebidas->first; aux->cod!=cod; aux=aux->next);
    if(aux->qtEstoque < qtd ){
        printf("Estoque insuficiente\n");
    }else{
        nf(aux,auxC,qtd);
        aux->qtEstoque-=qtd;
        
    }
    return;
}

void nf(Bebida *bebida, Cliente *cliente, int qtd){
    Bebida *auxB=bebida;
    Cliente *auxC=cliente;

    printf("|=========================================================|\n");
    printf("| Cliente: %-47s|\n", auxC->nome);
    printf("|=========================================================|\n");
    printf("| Código da Bebida | Nome da Bebida | Preço | Qtd | Total |\n");
    printf("|=========================================================|\n");
    printf("|%-18d|%-16s|%-7.2f|%-5d|%-7.2f|\n", auxB->cod, auxB->nome, auxB->preco, qtd, auxB->preco*qtd);
    printf("|=========================================================|\n");
    printf("\n");
}

int menu(){
    char op[10];
    int op1;
    printf("\n");
    printf("(1) Cadastrar bebida\n");
    printf("(2) Mostrar bebidas\n");
    printf("(3) Comprar bebida\n");
    printf("(4) Vender bebida\n");
    printf("(5) Cadastrar cliente\n");
    printf("(6) Mostrar clientes\n");
    printf("(-1) Sair do sistema\n");

    scanf("%s", op);
    op1=atoi(op);

    return op1;
}