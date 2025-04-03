<div align="center">
  
# Programação de Baixo Nível - Trabalho 1
  
## Manipulação de Imagens

Integrantes: Gabrielle Guarani da Silva e Luiza Hackenhaar Naziazeno

- O programa deve atender os seguintes requisitos:
- Deverá solicitar o nome da imagem colorida (entrada via teclado com o nome *.ppm); Tamanho mínimo 400x400.
- Deverá oferecer um menu de opções:
- Colorida -> Gerar uma imagem tons de cinza;
- Colorida -> Gerar uma imagem negativa;
- Colorida -> Gerar uma imagem raio-x;
- Colorida -> Gerar uma imagem envelhecida (sépia);
- Colorida -> Rotacionar a imagem 90º;
- Colorida -> Rotacionar a imagem 180º;
- Após a escolha da opção, o programa deverá salvar a imagem conforme a escolha do item acima.

## Dicas para transformar uma imagem Colorida em Tons de cinza:
- O método mais utilizado para transformar uma imagem colorida em tons de cinza é o método de média ponderada. 
- Método de Média Ponderada:
- A fórmula mais usada para converter RGB para cinza é baseada na percepção humana das cores, onde diferentes cores contribuem de 
maneira diferente para a intensidade de cinza. A fórmula mais comum é:
-
- matriz[j][i] = (r*0.299)+(g*0.587)+(b*0.114);

## Dicas para transformar Uma imagem colorida em negativa:
- Imagem Negativa:
- Uma imagem negativa é o inverso das cores da imagem original. No espaço RGB, isso significa que cada valor de cor é subtraído de 255. Para cada pixel na imagem, o valor das cores é alterado de acordo com o equacionamento abaixo (tente outros valores – pesquise novos valores):
-
- R_novo = 255 - R_original
- G_novo = 255 - G_original
- B_novo = 255 - B_original

- Características da Imagem Negativa:
- Cores Invertidas: As cores da imagem são invertidas. Por exemplo, áreas que eram brancas se tornam pretas, áreas pretas se tornam brancas, e as cores são invertidas (azul se torna laranja, verde se torna magenta, etc.).
- Estilo: O efeito negativo é visualmente dramático e geralmente utilizado para criar contrastes fortes e efeitos artísticos.

## Dicas para transformar Uma imagem colorida em raio-x:
- Processo Geral para Simular um Efeito de Raio-X:
-  Converter para Tons de Cinza
-  Primeiro, como no exemplo anterior, você deve converter a imagem colorida para tons de cinza. Sugestão de equação ponderada (procure outros métodos, valores):
-
-  matriz[j][i] = (r*0.299)+(g*0.587)+(b*0.114);
- 
- Aplicar Transformação de Intensidade
- Depois de obter a imagem em tons de cinza, você pode aplicar uma transformação para simular a aparência de raio-X. Radiografias geralmente têm uma gama de intensidades que variam entre áreas mais escuras (ossos e estruturas densas) e áreas mais claras (tecidos moles). Você pode ajustar o contraste e a intensidade para criar esse efeito.
- Um método comum para ajustar a imagem é aplicar uma função de mapeamento ou uma curva de transferência que simula o contraste e a textura típicos das radiografias. Uma função simples para isso pode ser:
-
- Matriz_raiox[j][i] = pixel_cinza^fator
- Onde o Fator pode ser um valor entre 1 e 2 (exemplo 1.5). Valores maiores aumentarão o contraste, tornando áreas escuras mais escuras e áreas claras mais claras.

## Dicas para transformar uma imagem colorida em envelhecida:
- Ajuste das Componentes RGB
- Para adicionar um tom envelhecido, você pode ajustar as componentes RGB da seguinte forma:
-
- Reduzir o Azul: Reduzir a quantidade de azul pode dar um tom mais amarelado à imagem. Subtraia um valor pequeno da componente azul.
-
- Reduzir o Azul:
- B = B * (1 - fator), onde o fator é um valor pequeno, como 0.1.
- 
- Aumentar o Vermelho e Verde: Aumentar as componentes vermelho e verde pode ajudar a adicionar um tom amarelado. Aumente essas componentes ligeiramente.
-
- Aumentar o Vermelho e Verde:
- R = R * (1 + fator), onde o fator é um valor pequeno, como 0.1.
- G = G * (1 + fator), onde o fator é um valor pequeno, como 0.1.
-
- Aplicar uma Tintura: Se você quiser aplicar uma tintura geral, pode adicionar um valor constante às componentes vermelho e verde e diminuir a componente azul.
-
- Adicionar uma Tintura:
- R = R + 10 (ou outro valor pequeno).
- G = G + 10 (ou outro valor pequeno).
- B = B - 10 (ou outro valor pequeno).

## Dicas para rotacionar 90º uma imagem colorida:
- Usando Operações de Matriz
- Rotacionar uma imagem pode ser visualizado como uma operação de matriz em que os pixels são rearranjados. Para rotacionar 90 graus no sentido horário:
- Transpose a Matriz: Troque linhas por colunas.
- Reverse as Colunas: Inverta a ordem das colunas.
- Se a imagem original tem dimensões M×N, a imagem rotacionada terá dimensões N×M.

## ABERTURA DE ARQUIVO:
 - FILE *fp;
 - fp = fopen("koala.ppm","r");
 
## LEITURA DO FORMATO:
 - char formato[3];
 - fscanf(fp, "%s", formato);  // lê o tipo de imagem P3 (color), P2 (P&B) 
 - printf("%s\n", formato);  

## LEITURA DO TAMANHO DA IMAGEM:
 - int coluna, linha;
 - fscanf(fp, "%d %d", &coluna, &linha); // lê o tamanho da matriz  
 - printf("%d %d\n", coluna, linha);


## LEITURA DO VALOR MÁXIMO POR PIXEL:
 - int valor;
 - fscanf(fp, "%d", &valor);  // lê o valor máximo.
 - printf("%d\n", valor);

## CRIANDO UM ARQUIVO PPM:
## ABERTURA DE ARQUIVO:
 - FILE* fp_novo = fopen ("koalacopy.ppm", "w");

## ESCREVENDO O CABEÇALHO NO ARQUIVO:
 - fprintf (fp_novo, "P2\n");
 - fprintf (fp_novo, "%d %d\n", coluna, linha);
 - fprintf (fp_novo, "%d\n", valor);

## PRÓXIMO PASSO ESCREVER A MATRIZ DE PIXEL’S– PODE-SE USAR STRUCT:
## LEITURA DE TODOS OS PIXELS DA IMAGEM:
 - int i, j;
 - for(j=0; j<linha; j++)
 - {
 - for(i=0; i<coluna; i++)
 - {  
 - fscanf(fp, "%d %d %d", &r, &g, &b);
 - printf("%d %d %d\n", r, g, b);
 - }
 - }

 ## FECHAMENTO DO ARQUIVO
 - fclose(fp)

 ## COMO CRIAR UMA STRUCTDOS PIXELS:
 -  #include <stdio.h>
 -  typedef struct // Esta struct é uma estrutura composta por 3 números inteiros – neste caso R, G e B.
 - {
 - int R;
 - int G;
 - int B;
 - } RGB;

 - int main() 
 -{
 - RGB vetor[3][3]; //Aqui é feito a instanciação da  struct RGB do vetor bidimensional
 - vetor[0][0].R = 130; // A atribuição de um valor a matriz bidimensional, utiliza-se o ponto (. ) com a instância a cada elemento da struct
 - vetor[0][0].G = 150;
 - vetor[0][0].B = 120;
 -  printf("%d - %d - %d", vetor[0][0].R, vetor[0][0].G, vetor[0][0].B);
 -  return 0;
 - }