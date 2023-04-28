Projeto Bodega
==============

Pré-requisitos de instalação
----------------------------

Este projeto foi desenvolvido em linguagem C, portanto é necessário ter um compilador C instalado no sistema operacional para compilar o código fonte.

Instruções de instalação do projeto
-----------------------------------

1.  Clone o repositório do projeto em sua máquina local:

```bash
git clone https://github.com/seu-usuario/bodega.git
```

2.  Compile o código fonte usando um compilador C de sua preferência, como o GCC:

```bash
gcc -o bodega bodega.c
```

3.  Execute o arquivo executável gerado:

```bash
./bodega
```

Descrição das funcionalidades do projeto
----------------------------------------

O projeto Bodega consiste em um sistema de gestão de estoque de bebidas, onde é possível cadastrar clientes, cadastrar bebidas, comprar bebidas e consultar informações sobre o estoque e os clientes cadastrados.

As funcionalidades do projeto incluem:

*   Cadastrar um cliente: o usuário pode cadastrar um cliente informando o nome, CPF, idade, código e valor de crédito (fiado) que o cliente possui.
    
*   Cadastrar uma bebida: o usuário pode cadastrar uma bebida informando o nome, volume (em mililitros), preço, quantidade em estoque e teor alcoólico.
    
*   Comprar uma bebida: o usuário pode comprar uma bebida informando o código da bebida e a quantidade desejada. Se a compra for bem-sucedida, a quantidade em estoque da bebida será atualizada.
    
*   Consultar o estoque: o usuário pode consultar o estoque de bebidas cadastradas, visualizando o código, nome, volume, preço, quantidade em estoque e teor alcoólico de cada bebida.
    
*   Consultar clientes: o usuário pode consultar os clientes cadastrados, visualizando o código, nome, CPF, idade e valor de crédito de cada cliente.
    

Exemplos de uso do projeto
--------------------------

### Cadastrar um cliente

```c
Cliente *new = createCliente(1, "Fulano", "123.456.789-00", 30, 0);
addCliente(&clientes, new);
```

### Cadastrar uma bebida

```c
Bebida *new = createBebida(1, "Cerveja", 350, 3.5, 100, 5);
addBebida(&bebidas, new);
```

### Comprar uma bebida

```c
compraBebida(&bebidas, 1, 10);
```

### Consultar estoque

```c
printBebidas(&bebidas);
```

### Consultar clientes

```c
printClientes(&clientes);
```

Informações sobre como contribuir para o projeto
------------------------------------------------

Se você deseja contribuir com o projeto, sinta-se à vontade para fazer um fork do repositório, implementar melhorias e correções de bugs, e enviar um pull request.

Licença do projeto
------------------

Este projeto está licenciado sob a licença MIT. Consulte o arquivo [LICENSE](LICENSE) para obter mais informações.
