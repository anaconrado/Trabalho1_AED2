# Trabalho1_AED2

Competição Literária

Todo ano, na escola municipal de Abadia dos Açores, ocorre uma competição

literária. Nessa, cada aluno participante deve redigir um texto sobre um de-
terminado tema. Para tornar a competição mais objetiva, os organizadores

decidiram introduzir um sistema de pontuação. Basicamente, os professores
estipulam um conjunto de palavras (que eles consideram pertinentes ao tema)
e atribuem uma pontuação a cada uma delas. Nesse sistema, a nota de um
dado aluno é calculada da seguinte maneira: somam-se os valores de todas as
palavras do texto que estão na lista dos professores e subtraem-se 10 pontos
para cada vez que uma palavra que não está na lista aparece no texto. Como
é possível fazer um programa para calcular rapidamente as notas de todos os
participantes?

Entrada: Os dados devem ser lidos diretamente da entrada padrão. A pri-
meira linha da entrada contém dois inteiros positivos: N, o número de palavras

escolhidas pelos professores, e M, o número de participantes na competição.
Em seguida, o arquivo contém N linhas, compostas por uma palavra e sua
pontuação. Nas linhas seguintes a estas são apresentados os textos produzidos
pelos alunos, sendo que, ao nal de cada texto existe uma linha com o caractere
'.' (ponto). Vale notar que cada texto pode estar em uma ou mais linhas e
todas as palavras estão em letras minúsculas, não contendo caracteres especiais
ou acentuados.

Saída: É composta de M linhas, cada uma contendo um inteiro correspon-
dente à pontuação obtida por um texto. As pontuações devem ser apresentadas

respeitando a mesma ordem em que os textos foram apresentados.
