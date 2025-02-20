UPDATE livraria.fornecedores
SET nome = 'Livros e Cia Ltda'
WHERE (id = '1');

DELETE FROM livraria.fornecedores
WHERE (id = '1');

SELECT c.titulo, COUNT(l.categoria_id)      
FROM livros l INNER JOIN
     categorias c
    ON c.id = l.categoria_id
GROUP BY c.id;

SELECT DISTINCT cidade
FROM enderecos
ORDER BY cidade;

SELECT titulo,
    edicao,
    ano
FROM livros
ORDER BY titulo;

SELECT *
FROM vendas
WHERE valor_total >= 100
ORDER BY data DESC;

SELECT nome,
    funcionarios_rh.salario_base
FROM funcionarios
    INNER JOIN funcionarios_rh ON funcionarios.id = funcionarios_rh.funcionario_id;

SELECT categorias.titulo,
    livros.titulo,
    edicao,
    ano
FROM livros
    INNER JOIN categorias ON livros.categoria_id = categorias.id
ORDER BY categorias.titulo;

SELECT count(*)
FROM livros
WHERE valor > 300;

SELECT max(valor)
FROM livros;

SELECT sum(valor_total)
FROM vendas
WHERE DATA = '2021-09-15';

SELECT sum(valor_total)
FROM vendas
WHERE `data` between '2021-09-01' AND '2021-09-17';

SELECT avg(valor_total)
FROM vendas
WHERE `data` between '2021-09-01' AND '2021-09-17';

SELECT min(valor_total)
FROM vendas
WHERE `data` between '2021-09-01' AND '2021-09-17';

SELECT max(valor_total)
FROM vendas
WHERE `data` between '2021-09-01' AND '2021-09-17';
	
SELECT titulo,
    edicao,
    ano
FROM livros
WHERE livros.categoria_id = 1;

SELECT vendas.data,
    vendas.valor_total
FROM vendas
    INNER JOIN venda_livros ON vendas.id = venda_livros.venda_id_id
ORDER BY vendas.data;

SELECT livros.ano AS Ano,
	livros.edicao AS Edição,
    livros.titulo AS Titulo,
    categorias.titulo AS Categorias
FROM livros
    INNER JOIN categorias ON livros.categoria_id = categorias.id
ORDER BY livros.ano ASC;

SELECT c.nome AS Cliente,
    f.nome AS Funcionario,
    v.data AS Data,
    v.nota_fiscal AS Nota_Fiscal,
    l.titulo as Titulo,
    vl.quantidade as Quantidade,
    vl.valor_unitario as Valor
FROM venda_livros vl
    JOIN vendas v ON vl.venda_id_id = v.id
    JOIN funcionarios f ON v.funcionario_id = f.id
    JOIN clientes c ON v.cliente_id = c.id  
    JOIN livros l on vl.livro_id = l.id;

SELECT c.nome AS Cliente,
    f.nome AS Funcionario,
    v.data AS Data,
    v.nota_fiscal AS Nota_Fiscal,
    l.titulo as Titulo,
    vl.quantidade as Quantidade,
    vl.valor_unitario as Valor
FROM venda_livros vl
    JOIN vendas v ON vl.venda_id_id = v.id
    JOIN funcionarios f ON v.funcionario_id = f.id
    JOIN clientes c ON v.cliente_id = c.id  
    JOIN livros l on vl.livro_id = l.id
WHERE v.cliente_id = 1;