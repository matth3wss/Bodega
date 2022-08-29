#ifndef BODEGA_H
#define BODEGA_H

typedef struct empresa{
    char nome[40];
    char cnpj[11];
}Empresa;

typedef struct bebida{
    int id;
    char nome[40];
    int ml;
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
    int id;
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

Cliente *createCliente(int id, char *nome, char *cpf, int idade, int fiado);
Cliente *searchClienteCPF(lClientes *first, char *cpf);
Cliente *searchClienteID(lClientes *list, int id);

Bebida *createBebida(int id, char *nome, int ml, float preco, int qtEstoque, int teorAlcolico);
Bebida *searchBebida(lBebidas *first, int id);
void compraBebida(lBebidas *first, int id, int qtd);

void addCliente(lClientes *list, Cliente *new);
void addBebida(lBebidas *list, Bebida *new);

void printClientes(Cliente *first);
void printBebidas(Bebida *first);

void criaVenda(lClientes *firstC, lBebidas *firstB, char *cpf, int id);
void nf(Bebida *bebida, Cliente *cliente, int qtd);

int clearB(Bebida *first);
int clearC(Cliente *first);

int menu();

#endif