# lifeSimulation

  O lifeSimulation é um simulador do *jogo da vida de Conway*. Nessa simulação, células que habitam uma grade retangular estão sujeitas a certas regras que determinam a sua sobrevivencia dependendo do número de vizinhos vivos. Uma célula que tem vizinhos demais (4 ou mais) ou de menos (nenhum ou 1) não sobrevive na próxima geração. Apenas células com 2 ou três vizinhos vivos permanecem vivas e células mortas com exatamente 3 vizinhos voltam a vida na próxima geração. Um detalhe importante é que todos os nascimentos e mortes ocorridos em uma geração acontecem ao mesmo tempo.

  Assim, o usuário fornece um arquivo contendo uma configuração inicial (formato descrito abaixo) e pode observar a evolução do sistema no console ou, se preferi,r em uma série de imagens png que podem ser transformadas em vídeo utilizando o comando (necessita de ffmpeg instalado):
  
     $ ffmpeg -framerate 24 -i generation%02d.png -c:v libx264 -r 30 -pix_fmt yuv420p  -vf "pad=ceil(iw/2)*2:ceil(ih/2)*2" glider_gun.mp4

A saída do console pode ser salva em arquivo. (Veja as opções disponíveis no menu `help`.)

O arquivo contendo a configuração inicial da simulação deve fornecer na primeira linha o número de linhas e o número de colunas da grade retangular, na segunda linha o caracter utilizado para representar as células vivas no mapeamento que segue (deve ser diferente de '.', pois é o caracter utilizado para representar células mortas). Por fim, em cada linha seguinte, deve-se apresentar a localização das células vivas (representada pelo caracter fornecido na linha dois) e das mortas (qualquer caracter diferente do escolhido para as células vivas). Não há necessidade de colocar a posição de todas as células mortas, apenas a posição correta das células vivas. Qualquer caracter que ultrapasse a grade escolhida na linha 1 será ignorado.

Exemplos de configurações inicial se encontram na pasta 'data/'.

# Limitações

As regras de sobrevivencia/nascimento são fixas.

# Execução

Para compilar usando o cmake, siga as instruções:

     $ mkdir build

     $ cd build

     $ cmake ..

     $ make

     $ ./glife <opções> <arquivo de configuração inicial>


Para ver as opções disponíveis, digite:

     $ ./glife --help

# Observações

O código utilizado para gerar as imagens em png (loadpng.cpp) foi feito por Selan R. dos Santos.


# Autores:

    Daniel do Nascimento Gomes
    Karine Piacentini Coelho da Costa






