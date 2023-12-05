## Descrição

<p style="text-align: justify;">
O projeto consiste em um SGBD (Sistema de gerenciamento de banco de dados) simplificado, objetivando colocar em prática os conceitos aprendidos na disciplina de "Introdução às técnicas de programação".
</p>

## Requisitos

### Criar uma tabela

- [x] O usuário deve informar o nome da tabela;
- [x] Os tipos de dados para as colunas poderão ser os tipos primitivos em C ( char, int, float e double) e strings;
- [x] Os valores deverão ser armazenados em arquivo;
- [ ] A criação da tabela deverá ser solicitado um nome de coluna para ser a chave primária
- [ ] A chave primária deverá ser obrigatoriamente do tipo inteiro sem sinal

### Listar todas as tabelas

- [x] Exibir para o usuário todas as tabelas existentes

### Criar um novo registro na tabela

- [x] O usuário deve informar o nome da tabela
- [x] O sistema deve solicitar os valores de cada uma das colunas
- [x] O sistema deve solicitar uma chave primária

Para o caso da chave primária, o próprio sistema vai criar uma coluna chamada "id", e a mesma vai ser a chave primária.

### Listar todos os dados de uma tabela

- [x] O usuário deve informar de qual tabela os dados serão exibidos
- [x] Os dados deverão ser obtidos a partir do arquivo que armazena o conteúdo da tabela

### Pesquisar valor em uma tabela

- [ ] Usuário deverá informar o nome da tabela onde realizará a pesquisa
- [ ] Sistema deverá fornecer as colunas disponíveis na tabela, e o usuário deverá selecionar uma delas
- [ ] Sistema deverá solicitar o valor para pesquisar, disponibilizando algumas opções
- [ ] Valores maiores que o valor informado
- [ ] Valores maiores ou iguais que o valor informado
- [ ] Valores iguais ao valor informado
- [ ] Valores menores que o valor informado
- [ ] Valores menores ou iguais que o valor informado
- [ ] Valores próximos ao valor informado, mas isso se aplica apenas se a coluna é do tipo string

### Apagar um registro da tabela

- [ ] O usuário deve informar o nome da tabela e a chave primária da tupla a ser apagada

### Apagar uma tabela

- [ ] O usuário deverá fornecer o nome da tabela a ser apagada
