CREATE DATABASE livraria;

CREATE TABLE autores (
  id int NOT NULL AUTO_INCREMENT,
  nome varchar(50) NOT NULL,
  PRIMARY KEY (id)
); 

CREATE TABLE categorias (
  id int NOT NULL AUTO_INCREMENT,
  titulo varchar(30) NOT NULL,
  PRIMARY KEY (id)
);

CREATE TABLE livros (
  id int NOT NULL AUTO_INCREMENT,
  ano int NOT NULL,
  edicao varchar(15) NOT NULL,
  editora varchar(30) NOT NULL,
  quantidade int NOT NULL,
  titulo varchar(50) NOT NULL,
  valor double NOT NULL,
  categoria_id int NOT NULL,
  PRIMARY KEY (id),
  CONSTRAINT categoria_id FOREIGN KEY (categoria_id) REFERENCES categorias (id)
); 

CREATE TABLE autores_livros (
  id int NOT NULL AUTO_INCREMENT,
  autor_id int NOT NULL,
  livro_id int NOT NULL,
  PRIMARY KEY (id),
  CONSTRAINT FK_autor_id FOREIGN KEY (autor_id) REFERENCES autores (id),
  CONSTRAINT FK_livro_id_id_autor FOREIGN KEY (livro_id) REFERENCES livros (id)
);

CREATE TABLE telefones (
  id int NOT NULL AUTO_INCREMENT,
  ddd int NOT NULL,
  telefone varchar(10) NOT NULL,
  PRIMARY KEY (id)
);

CREATE TABLE enderecos (
  id int NOT NULL AUTO_INCREMENT,
  bairro varchar(30) NOT NULL,
  cep varchar(12) NOT NULL,
  cidade varchar(30) NOT NULL,
  complemento varchar(30) NOT NULL,
  numero int NOT NULL,
  rua varchar(50) NOT NULL,
  PRIMARY KEY (id)
);

CREATE TABLE fornecedores (
  id int NOT NULL AUTO_INCREMENT,
  email varchar(50) NOT NULL,
  nome varchar(50) NOT NULL,
  telefone varchar(15) NOT NULL,
  PRIMARY KEY (id)
); 

CREATE TABLE pedidos (
  id int NOT NULL AUTO_INCREMENT,
  data_pedido datetime NOT NULL,
  data_recebido datetime NOT NULL,
  pedido varchar(50) NOT NULL,
  quantidade int NOT NULL,
  valor_total double NOT NULL,
  valor_unitario double NOT NULL,
  fornecedor_id int NOT NULL,
  livro_id int NOT NULL,
  PRIMARY KEY (id),
  CONSTRAINT FK_livro_id_pedido FOREIGN KEY (livro_id) REFERENCES livros (id),
  CONSTRAINT FK_fornecedor_id FOREIGN KEY (fornecedor_id) REFERENCES fornecedores (id)
);

CREATE TABLE funcionarios (
  id int NOT NULL AUTO_INCREMENT,
  cpf varchar(11) NOT NULL,
  email varchar(50) NOT NULL,
  nome varchar(50) NOT NULL,
  endereco_id int NOT NULL,
  telefone_id int NOT NULL,
  PRIMARY KEY (id),
  CONSTRAINT  FK_telefone_id_funcionario FOREIGN KEY (telefone_id) REFERENCES telefones (id),
  CONSTRAINT FK_endereco_id_funcionario FOREIGN KEY (endereco_id) REFERENCES enderecos (id)
);

CREATE TABLE salarios (
  id int NOT NULL AUTO_INCREMENT,
  comissao double NOT NULL,
  data datetime NOT NULL,
  descontos double NOT NULL,
  faltas int NOT NULL,
  observacoes varchar(50) NOT NULL,
  salario_base double NOT NULL,
  salario_total double NOT NULL,
  funcionario_id int NOT NULL,
  PRIMARY KEY (id),
  CONSTRAINT FK_funcionario_id_salario FOREIGN KEY (funcionario_id) REFERENCES funcionarios (id)
);

CREATE TABLE funcionarios_rh (
  id int NOT NULL AUTO_INCREMENT,
  cargo varchar(15) NOT NULL,
  comissao int NOT NULL,
  salario_base double NOT NULL,
  funcionario_id int NOT NULL,
  PRIMARY KEY (id),
 CONSTRAINT FK_funcionario_id_rh FOREIGN KEY (funcionario_id) REFERENCES funcionarios (id)
);

CREATE TABLE usuarios (
  id int NOT NULL AUTO_INCREMENT,
  permissoes varchar(5) NOT NULL,
  senha varchar(64) NOT NULL,
  usuario varchar(32) NOT NULL,
  funcionario_id int NOT NULL,
  PRIMARY KEY (id),
  CONSTRAINT FK_funcionario_id_usuarios FOREIGN KEY (funcionario_id) REFERENCES funcionarios (id)
);

CREATE TABLE perfis (
  id int NOT NULL AUTO_INCREMENT,
  desconto int NOT NULL,
  quantidade int NOT NULL,
  tipo varchar(30) NOT NULL,
  PRIMARY KEY (id)
);

CREATE TABLE clientes (
  id int NOT NULL AUTO_INCREMENT,
  cpf varchar(11) NOT NULL,
  email varchar(50) NOT NULL,
  nome varchar(50) NOT NULL,
  total_livros_comprados int NOT NULL,
  endereco_id int NOT NULL,
  perfil_id int NOT NULL,
  telefone_id int NOT NULL,
  PRIMARY KEY (id),
  CONSTRAINT FK_perfil_id FOREIGN KEY (perfil_id) REFERENCES perfis (id),
  CONSTRAINT FK_endereco_id_cliente FOREIGN KEY (endereco_id) REFERENCES enderecos (id),
  CONSTRAINT FK_telefone_id_cliente FOREIGN KEY (telefone_id) REFERENCES telefones (id)
);

CREATE TABLE forma_pagamentos (
  id int NOT NULL AUTO_INCREMENT,
  opcao varchar(15) NOT NULL,
  PRIMARY KEY (id)
); 

CREATE TABLE vendas (
  id int NOT NULL AUTO_INCREMENT,
  data datetime NOT NULL,
  nota_fiscal varchar(20) NOT NULL,
  quantidade_itens int NOT NULL,
  valor_total double NOT NULL,
  cliente_id int DEFAULT NULL,
  forma_pagamento_id int NOT NULL,
  funcionario_id int NOT NULL,
  PRIMARY KEY (id),
  CONSTRAINT FK_cliente_id FOREIGN KEY (cliente_id) REFERENCES clientes (id),
  CONSTRAINT FK_funcionario_id_venda FOREIGN KEY (funcionario_id) REFERENCES funcionarios (id),
  CONSTRAINT FK_forma_pagamento_id FOREIGN KEY (forma_pagamento_id) REFERENCES forma_pagamentos (id)
); 

CREATE TABLE venda_livros (
  id int NOT NULL AUTO_INCREMENT,
  quantidade int NOT NULL,
  valor_unitario double NOT NULL,
  livro_id int NOT NULL,
  venda_id_id int NOT NULL,
  PRIMARY KEY (id),
  CONSTRAINT FK_venda_id_venda FOREIGN KEY (venda_id_id) REFERENCES vendas (id),
  CONSTRAINT FK_livro_id_venda FOREIGN KEY (livro_id) REFERENCES livros (id)
);