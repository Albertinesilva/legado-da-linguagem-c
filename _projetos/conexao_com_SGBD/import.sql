INSERT INTO livraria.autores (nome) VALUES ('João'), ('Manoel Antonio'), ('Marta Maria');

UPDATE livraria.autores SET nome = 'João Santos' WHERE (id = '1');

INSERT INTO livraria.categorias (titulo) VALUES ('Tecnologia'), ('Romance'), ('Terror');

INSERT INTO livraria.livros (ano, edicao, editora, quantidade, titulo, valor, categoria_id) 
VALUES ('2015', '6', 'Abril', '36', 'Java', '365', '1'), ('2019', '8', 'Abril', '30', 'POO', '375', '1'), ('2018', '1', 'Abril', '25', 'O amor', '65', '2'), 
('2020', '1', 'Abril', '15', 'A morte', '89', '3'), ('2008', '3', 'Abril', '18', 'O espanto', '16', '3');

INSERT INTO livraria.autores_livros (autor_id, livro_id) VALUES ('1', '1'), ('2', '2'), ('3', '3'), ('1', '4'), ('2', '5');

INSERT INTO livraria.enderecos (bairro, cep, cidade, complemento, numero, rua) 
VALUES ('Centro', '40444-444', 'SAJ', 'Ap 5', '55', 'Silveira'), ('Sao Jose', '40141-000', 'Salvador', 'Ap 8', '104', 'Alencar');

INSERT INTO livraria.telefones (ddd, telefone) VALUES ('75', '3333-3333'), ('75', '3344-4433');

INSERT INTO livraria.funcionarios (cpf, email, nome, endereco_id, telefone_id) VALUES ('3232311', 'tes@', 'Jose', '1', '1'), ('10417', 'ped@', 'Pedro', '2', '2');

INSERT INTO livraria.usuarios (permissoes, senha, usuario, funcionario_id) VALUES ('ADM', 'd3d9446802a44259755d38e6d163e820', 'ADM', '1'), ('Caixa', 'd3d9446802a44259755d38e6d163e820', 'Caixa', '2');

INSERT INTO livraria.funcionarios_rh (cargo, comissao, salario_base, funcionario_id) VALUES ('Gerente', '5', '4000', '1'), ('Funcionario', '5', '2000', '2');

INSERT INTO livraria.forma_pagamentos (opcao) VALUES ('Especie'), ('Cartao'), ('Pix');

INSERT INTO livraria.perfis (desconto, quantidade, tipo) VALUES ('0', '0', 'LATAO'),('5', '10', 'BRONZE'),('10', '15', 'PRATA'),('15', '20', 'OURO');

INSERT INTO livraria.enderecos (bairro, cep, cidade, complemento, numero, rua) 
VALUES ('Santos', '17777-444', 'Feira', 'Ap 1', '15', 'Sao Jose'), ('Santos', '47777-000', 'Itabuna', 'Casa', '254', 'Sao Lucas');

INSERT INTO livraria.telefones (ddd, telefone) VALUES ('71', '2222-3333'), ('71', '1111-4433');

INSERT INTO livraria.clientes (cpf, email, nome, total_livros_comprados, endereco_id, perfil_id, telefone_id) VALUES ('12345', 'maria@', 'Maria Santos', '0', '3', '1', '3'), 
('543210', 'paula@', 'Paula Silva', '0', '4', '1', '4');

INSERT INTO livraria.vendas (data, nota_fiscal, quantidade_itens, valor_total, cliente_id, forma_pagamento_id, funcionario_id) VALUES ('2021-09-10', '10120214', '1', '365', '1', '1', '1'),
('2021-09-12', '10120215', '1', '375', '2', '1', '2'), ('2021-09-13', '10120215', '1', '65', '1', '1', '1'), ('2021-09-15', '10120216', '2', '105', '2', '1', '2');

INSERT INTO livraria.venda_livros (quantidade, valor_unitario, livro_id, venda_id_id) VALUES 
('1', '365', '1', '1'), ('1', '375', '2', '2'), ('1', '65', '3', '3'), ('1', '89', '4', '4'), ('1', '16', '5', '4');

INSERT INTO livraria.fornecedores (email, nome, telefone) VALUES ('empresa@ltda', 'Livros e Cia', '7185858585');
