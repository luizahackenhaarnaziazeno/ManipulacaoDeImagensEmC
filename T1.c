#include <stdio.h>
#include <stdlib.h>

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

//                        Preto e branco
void PB()
{
    int matriz[700][700];

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

    printf("Leu todo o arquivo e gerou matriz com pixels p&b\n");
  	fclose(fp);

    // CRIANDO A IMAGEM P&B

    FILE* fp_novo = fopen ("goldenP&B.ppm", "w");
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
}

//                        Negativo
void negativo()
{
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

int main()
{
    printf("\n-- T1 --\n");
    
    printf("Insira o nome do arquivo da imagem: \n");
    scanf("%s", nomearquivo);

    fp = fopen(nomearquivo,"r");

    if(fp==NULL)
    {
        printf("Erro ao abrir o arquivo!");
        return 0;
    }
  	
  	fscanf(fp, "%s", tipoImg); // le o tipo de imagem P3 (color), P2 (P&B) 
  	printf("%s\n", tipoImg);
  	
  	fscanf(fp, "%d %d", &coluna, &linha); // le o tamanho da matriz  
  	printf("%d %d\n", coluna, linha);
  	
  	fscanf(fp, "%d", &val); // le o valor maximo. 
  	printf("%d\n", val);

    printf("O que deseja fazer com a imagem?\n");
    printf("1 - Gerar imagem preto e branco\n");
    printf("2 - Gerar imagem filtro negativo\n");
    printf("3 - Gerar imagem raio-x\n");
    printf("4 - Gerar imagem envelhecida\n");
    printf("5 - Rotacionar a imagem 90 graus\n");
    printf("6 - Rotacionar a imagem 180 graus\n");
    scanf("%d", &op);

    switch (op)
    {
        case 1:
            PB();    
        break;
        case 2:    
            negativo();
        break;
        case 3:
        
        break;
        case 4:
        
        break;
        case 5:
        
        break;
        case 6:
        
        break;
        default:

        break;
    }

    return 0;
}