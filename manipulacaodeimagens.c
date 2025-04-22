#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nomeImagem[100]= "C:\projects\Facul\T1C\ManipulacaoDeImagens\Imagens";
char imagem[100];


void tonsDeCinza();
void negativa();
void raioX();
void envelhecida();
void rotacionar90();
void rotacionar180();


int main()
{
    int opcao;
    
    
    do
    {
        printf("Menu Do Que Fazer Com A Imagem:\n");
        printf("1. Gerar uma imagem tons de cinza\n");
        printf("2. Gerar uma imagem negativa\n");
        printf("3. Gerar uma imagem raio-x\n");
        printf("4. Gerar uma imagem envelhecida (sepia)\n");
        printf("5. Rotacionar a imagem 90º\n");
        printf("6. Rotacionar a imagem 180º\n");
        printf("7. Exit\n");
        printf("Escolha o que deseja fazer com a imagem: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("Voce escolheu gerar uma imagem tons de cinza.\n");
            tonsDeCinza();
        }
        else if (opcao == 2)
        {
            printf("Voce escolheu gerar uma imagem negativa.\n");
            negativa();
        }
        else if (opcao == 3)
        {
            printf("Voce escolheu gerar uma imagem raio-x.\n");
        }
        else if (opcao == 4)
        {
            printf("Voce escolheu gerar uma imagem envelhecida (sépia).\n");
        }
        else if (opcao == 5)
        {
            printf("Voce escolheu rotacionar a imagem 90º.\n");
        }
        else if (opcao == 6)
        {
            printf("Voce escolheu rotacionar a imagem 180º.\n");
        }
        else if (opcao == 7)
        {
            printf("Fechando o programa.\n");
        }
        else
        {
            printf("Opção inválida.\n");
        }
    } while (opcao != 7);
}

void tonsDeCinza(){
    FILE *fp;
    fp= fopen("C:\projects\Facul\T1C\ManipulacaoDeImagens\Imagens\araravermelha.ppm","r");
   
	if(fp==NULL){
		printf("Erro ao abrir o arquivo!");
		}
  	char tipoImg[3];

  	int i, j, linha, coluna, val, r, g, b;
  	
  	fscanf(fp, "%s", tipoImg); // le o tipo de imagem P3 (color), P2 (P&B) 
  	printf("%s\n", tipoImg);
  	
  	fscanf(fp, "%d %d", &coluna, &linha); // le o tamanho da matriz  
  	printf("%d %d\n", coluna, linha);

  	int matriz[700][700];
  	
  	fscanf(fp, "%d", &val); // le o valor maximo. 
  	printf("%d\n", val);

	for(j=0; j<linha; j++)
	{
		for(i=0; i<coluna; i++)
		{  	
  			fscanf(fp, "%d %d %d", &r, &g, &b);
		  	//printf("%d %d %d\n", r, g, b);
		  	matriz[j][i] = ((r*0.30)+(g*0.59)+(b*0.11));
		  	//printf("%d\n", matriz[j][i]);
		}
	}
	printf("leu todo o arquivo e gerou vetor p&b\n");
  	fclose(fp);

	// CRIANDO A IMAGEM P&B

    FILE* fp_novo = fopen ("araravermelhaP&B.ppm", "w");
    printf("criou o arquivo\n");
    
        fprintf (fp_novo, "P2\n");
        fprintf (fp_novo, "%d %d\n", coluna, linha);
        fprintf (fp_novo, "%d\n", val);

		for(j=0; j<linha; j++)
		{
			for(i=0; i<coluna; i++)
			{  	
			  	fprintf(fp_novo, "%d\n", matriz[j][i]);
			}
		}
		fclose(fp_novo);
		printf("Fechou o novo arquivo ppm\n");
   
   return(0);
}
//metodo esta incorreto não possui leitura de arquivo
void negativa() {
    typedef struct
    {
        int r;
        int g;
        int b;
    } RGB;
    
    FILE *fp;
    char nomearquivo[100];
    char tipoImg[3];
    int i, j, linha, coluna, val, op, r, g, b;
    RGB matriz[700][700];

    for(j=0; j<linha; j++)
	{
		for(i=0; i<coluna; i++)
		{  	
            fscanf(fp, "%d %d %d", &r, &g, &b);
		  	//printf("%d %d %d\n", r, g, b);
		  	matriz[j][i].r = 255-r;
            matriz[j][i].g = 255-g;
            matriz[j][i].b = 255-b;
		  	//printf("%d\n", matriz[j][i]);
		}
	}

    printf("Leu todo o arquivo e gerou matriz com pixels negativos\n");
  	fclose(fp);

    // CRIANDO A IMAGEM NEGATIVA

    FILE* fp_novo = fopen ("araravermelhaNegativa.ppm", "w");
    printf("criou o arquivo\n");
    
    fprintf (fp_novo, "P3\n");
    fprintf (fp_novo, "%d %d\n", coluna, linha);
    fprintf (fp_novo, "%d\n", val);

	for(j=0; j<linha; j++)
	{
		for(i=0; i<coluna; i++)
		{  	
		  	fprintf(fp_novo, "%d\n", matriz[j][i].r);
            fprintf(fp_novo, "%d\n", matriz[j][i].g);
            fprintf(fp_novo, "%d\n", matriz[j][i].b);
		}
	}
	fclose(fp_novo);
	printf("Fechou o novo arquivo ppm\n");
}


// IMPLEMENTAR AS FUNÇÕES AQUI
void raioX() {}
void envelhecida() {} //Gabrielle
void rotacionar90() {} //Luiza 
void rotacionar180() {} //Luiza
