#ifndef BODEGA_H
#define BODEGA_H

typedef struct empresa{
    char nome[40];
    char cnpj[14];
}Empresa;

typedef struct bebida{
    int cod;
    char nome[40];
    float preco;
    int qtEstoque;
    int teorAlcolico;
    struct bebida *next;
    struct bebida *prev;
} Bebida;

typedef struct lBeb{
    Bebida *first;
    Bebida *last;
}lBebidas;

typedef struct cliente{
    int cod;
    char nome[40+1];
    char cpf[14+1];
    int idade;
    int fiado;
    struct cliente *next;
    struct cliente *prev;
}Cliente;

typedef struct lCli{
    Cliente *first;
    Cliente *last;
}lClientes;

typedef struct vendas{
    Cliente cliente;
    Bebida bebida;
}Vendas;

bool isEmptyBebidas(Bebida *list);
bool isEmptyClientes(Cliente *list);

Cliente *createCliente(int cod, char *nome, char *cpf, int idade, int fiado);
Cliente *searchCliente(lClientes *first, char *cpf);


Bebida *createBebida(int cod, char *nome, float preco, int qtEstoque, int teorAlcolico);
Bebida *searchBebida(lBebidas *first, int cod);
void compraBebida(lBebidas *first, int cod, int qtd);

void addCliente(lClientes *list, Cliente *new);
void addBebida(lBebidas *list, Bebida *new);

void printClientes(Cliente *first);
// void reversePrintClientes(Cliente *last);

void printBebidas(Bebida *first);
// void reversePrintBebidas(Bebida *last);

void criaVenda(lClientes *firstC, lBebidas *firstB, char *cpf, int cod);

void printVenda(Vendas *first);

int menu();

#endif
