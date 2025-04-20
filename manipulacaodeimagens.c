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
    
    printf("Imagens Disponiveis: arara vermelha.ppm, cat.ppm, Elephant.ppm, fish.ppm, snake.ppm,tigre branco.ppm\n");
    printf("Digite o nome da imagem PPM que deseja manipular (Exemplo: imagem.ppm): ");  
    scanf("%s",imagem);
    
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
    FILE *fp = fopen(nomeImagem,"r");
    if (fp == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo '%s'!\n", nomeImagem);
        return;
    }

    char tipoImg[3];
    int linha, coluna, val, r, g, b, i, j;

    fscanf(fp, "%s", tipoImg);
    fscanf(fp, "%d %d", &coluna, &linha);
    fscanf(fp, "%d", &val);

    int matriz[700][700];

    for (j = 0; j < linha; j++)
    {
        for (i = 0; i < coluna; i++)
        {
            fscanf(fp, "%d %d %d", &r, &g, &b);
            matriz[j][i] = (int)((r * 0.30) + (g * 0.59) + (b * 0.11));
        }
    }

    fclose(fp);
    printf("Imagem foi gerada com sucesso.\n");

    char nomeSaida[120];
    strcpy(nomeSaida, nomeImagem);
    char *ponto = strrchr(nomeSaida, '.');
    if (ponto != NULL)
        *ponto = '\0';

    strcat(nomeSaida, "_cinza.ppm");

    FILE *fp_novo = fopen(nomeSaida, "w");
    if (fp_novo == NULL)
    {
        printf("Erro ao criar o novo arquivo!\n");
        return;
    }

    fprintf(fp_novo, "P2\n");
    fprintf(fp_novo, "%d %d\n", coluna, linha);
    fprintf(fp_novo, "%d\n", val);

    for (j = 0; j < linha; j++)
    {
        for (i = 0; i < coluna; i++)
        {
            fprintf(fp_novo, "%d\n", matriz[j][i]);
        }
    }

    fclose(fp_novo);
    printf("Nova imagem salva como '%s'.\n", nomeSaida);
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

    FILE* fp_novo = fopen ("goldenNegativa.ppm", "w");
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
