#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "bodega.h"

int main(){

    lBebidas *bebidas=malloc(sizeof(lBebidas));
    lClientes *clientes=malloc(sizeof(lClientes));

    clientes->first=NULL; clientes->last=NULL;
    bebidas->first=NULL; bebidas->last=NULL;

    Cliente auxC;
    Bebida auxB;
    int op=0;


    while(op!=-1){
    op=menu();

        switch (op){
            case 1:
            printf("Código da bebida: "); scanf("%d", &auxB.id);
            printf("Nome da bebida: "); scanf("%s", auxB.nome);
            printf("Peso liquido em ml: "); scanf("%d", &auxB.ml);
            printf("Valor da bebida: "); scanf("%f", &auxB.preco);
            printf("Qtd Estoque: "); scanf("%d", &auxB.qtEstoque);
            printf("Teor Alcoólico: "); scanf("%d", &auxB.teorAlcolico);
            addBebida(bebidas, createBebida(auxB.id, auxB.nome, auxB.ml, auxB.preco, auxB.qtEstoque, auxB.teorAlcolico));
            continue;

            case 2:
            printBebidas (bebidas->first);
            continue;

            case 3:
                if(isEmptyBebidas(bebidas->first)){
                    printf("Nenhuma bebida cadastrada\n");
                }else{
                    printf("Código da bebida: "); scanf("%d", &auxB.id);
                    printf("Qtd comprada: "); scanf("%d", &auxB.qtEstoque);
                    compraBebida(bebidas, auxB.id, auxB.qtEstoque);
                }
                continue;
            
            case 4:
                if(isEmptyClientes(clientes->first) && isEmptyBebidas(bebidas->first)){
                    printf("Nenhuma bebida ou cliente cadastrado\n");
                    continue;
                }
                else if(isEmptyClientes(clientes->first)){
                    printf("Não há nenhuma cliente cadastrado\n");
                    continue;;
                }else if(isEmptyBebidas(bebidas->first)){
                    printf("Não há nenhuma bebida cadastrada\n");
                    continue;;
                }
                printf("CPF do cliente (sem pontuação): "); scanf("%s", auxC.cpf);
                printf("Código da bebida: "); scanf("%d", &auxB.id);
                criaVenda(clientes, bebidas, auxC.cpf, auxB.id);
            continue;

            case 5:
            printf("Código do cliente: "); scanf("%d", &auxC.id);
            printf("Nome do cliente: "); scanf("%s", auxC.nome);
            printf("CPF do cliente (sem pontuação): "); scanf("%s", auxC.cpf);
            printf("Idade: "); scanf("%d", &auxC.idade);
            printf("Posso vender fiado?\n(1)SIM\n(0)NÃO\n"); scanf("%d", &auxC.fiado);
            addCliente(clientes, createCliente(auxC.id, auxC.nome, auxC.cpf, auxC.idade, auxC.fiado));
            continue;

            case 6:
            printClientes(clientes->first);
            continue;
        default:
        printf("Valor Inválido\n");
            continue;
        }
    }
    printf("Foram liberados: %d elementos\n", (clearC(clientes->first)+clearB(bebidas->first)));
return 0;
}