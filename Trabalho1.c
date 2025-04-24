/*
Programação de Baixo Nível 2025/1
Trabalho 1 - Manipulação de Imagens PPM
Autores: Gabrielle Guarani da Silva, Luiza Hackenhaar Naziazeno e Roberto Fonseca Braga
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

typedef struct
{
    int r;
    int g;
    int b;
} RGB;

FILE *fp;
char nomeImagem[100];
char nomeSaida[120];
char tipoImg[3];
int i, j, linha, coluna, val, r, g, b;
RGB matriz[700][700];

void tonsDeCinza();
void negativa();
void raioX();
void envelhecida();
void rotacionar90();
void rotacionar180();

int main()
{
    int opcao;

    printf(GREEN "Digite o nome da imagem PPM que deseja manipular (Exemplo: imagem.ppm): " RESET);
    scanf("%s", nomeImagem);

    fp = fopen(nomeImagem, "r");

    if (fp == NULL)
    {
        printf(RED "Erro ao abrir o arquivo '%s'!\n", nomeImagem);
        return 0;
    }

    fscanf(fp, "%s", tipoImg);
    printf(BLUE "Tipo de imagem: " RESET "%s\n", tipoImg);

    fscanf(fp, "%d %d", &coluna, &linha);
    printf(BLUE "Largura: " RESET "%d\n", coluna);
    printf(BLUE "Altura: " RESET "%d\n", linha);

    fscanf(fp, "%d", &val);
    printf(BLUE "Valor maximo de cor: " RESET "%d\n", val);

    printf(CYAN "\n========================================\n");
    printf(MAGENTA "    MENU DE MANIPULACAO DE IMAGEM\n");
    printf(CYAN "========================================\n");
    printf(MAGENTA "1." RESET " Gerar imagem em tons de cinza\n");
    printf(MAGENTA "2." RESET " Gerar imagem negativa\n");
    printf(MAGENTA "3." RESET " Gerar imagem raio-x\n");
    printf(MAGENTA "4." RESET " Gerar imagem envelhecida (sepia)\n");
    printf(MAGENTA "5." RESET " Rotacionar imagem 90 graus\n");
    printf(MAGENTA "6." RESET " Rotacionar imagem 180 graus\n");
    printf(MAGENTA "7." RESET " Sair\n");
    printf(CYAN "========================================\n");
    printf(GREEN "Escolha a opcao: " RESET);
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf(BLUE "Imagem com tons de cinza.\n");
        tonsDeCinza();
        break;
    case 2:
        printf(BLUE "Imagem negativa.\n");
        negativa();
        break;
    case 3:
        printf(BLUE "Imagem raio-x.\n");
        raioX();
        break;
    case 4:
        printf(BLUE "Imagem envelhecida (sepia).\n");
        envelhecida();
        break;
    case 5:
        printf(BLUE "Imagem rotacionada 90 graus.\n");
        rotacionar90();
        break;
    case 6:
        printf(BLUE "Imagem rotacionada 180 graus.\n");
        rotacionar180();
        break;
    case 7:
        printf(BLUE "Fechando o programa.\n");
        fclose(fp);
        break;
    default:
        printf(RED "Opcao invalida.\n");
    }
}

void tonsDeCinza()
{
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

    strcpy(nomeSaida, nomeImagem);
    char *ponto = strrchr(nomeSaida, '.');
    if (ponto != NULL)
        *ponto = '\0';

    strcat(nomeSaida, "_cinza.ppm");

    FILE *fp_novo = fopen(nomeSaida, "w");
    if (fp_novo == NULL)
    {
        printf(RED "Erro ao criar o novo arquivo!\n");
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
    printf(GREEN "Nova imagem salva como '%s'.\n", nomeSaida);
}

void negativa()
{
    for (j = 0; j < linha; j++)
    {
        for (i = 0; i < coluna; i++)
        {
            fscanf(fp, "%d %d %d", &r, &g, &b);
            matriz[j][i].r = 255 - r;
            matriz[j][i].g = 255 - g;
            matriz[j][i].b = 255 - b;
        }
    }

    fclose(fp);
    printf("Imagem foi gerada com sucesso.\n");

    strcpy(nomeSaida, nomeImagem);
    char *ponto = strrchr(nomeSaida, '.');
    if (ponto != NULL)
        *ponto = '\0';

    strcat(nomeSaida, "_negativa.ppm");

    FILE *fp_novo = fopen(nomeSaida, "w");
    if (fp_novo == NULL)
    {
        printf(RED "Erro ao criar o novo arquivo!\n");
        return;
    }

    fprintf(fp_novo, "P3\n");
    fprintf(fp_novo, "%d %d\n", coluna, linha);
    fprintf(fp_novo, "%d\n", val);

    for (j = 0; j < linha; j++)
    {
        for (i = 0; i < coluna; i++)
        {
            fprintf(fp_novo, "%d\n", matriz[j][i].r);
            fprintf(fp_novo, "%d\n", matriz[j][i].g);
            fprintf(fp_novo, "%d\n", matriz[j][i].b);
        }
    }

    fclose(fp_novo);
    printf(GREEN "Nova imagem salva como '%s'.\n", nomeSaida);
}

void raioX()
{
    float fator = 1.5;

    for (j = 0; j < linha; j++)
    {
        for (i = 0; i < coluna; i++)
        {
            fscanf(fp, "%d %d %d", &r, &g, &b);

            float fator = 1.2;
            int cinza = (int)(r * 0.299 + g * 0.587 + b * 0.114);

            float intensidade = powf((float)cinza, fator);
            int valorRX = (int)intensidade;

            if (valorRX > val)
                valorRX = val;
            if (valorRX < 0)
                valorRX = 0;

            matriz[j][i].r = valorRX;
            matriz[j][i].g = valorRX;
            matriz[j][i].b = valorRX;
        }
    }

    fclose(fp);
    printf("Imagem foi gerada com sucesso.\n");

    strcpy(nomeSaida, nomeImagem);
    char *ponto = strrchr(nomeSaida, '.');
    if (ponto != NULL)
        *ponto = '\0';

    strcat(nomeSaida, "_raiox.ppm");

    FILE *fp_novo = fopen(nomeSaida, "w");
    if (fp_novo == NULL)
    {
        printf(RED "Erro ao criar o novo arquivo!\n");
        return;
    }

    fprintf(fp_novo, "P3\n");
    fprintf(fp_novo, "%d %d\n", coluna, linha);
    fprintf(fp_novo, "%d\n", val);

    for (j = 0; j < linha; j++)
    {
        for (i = 0; i < coluna; i++)
        {
            fprintf(fp_novo, "%d\n", matriz[j][i].r);
            fprintf(fp_novo, "%d\n", matriz[j][i].g);
            fprintf(fp_novo, "%d\n", matriz[j][i].b);
        }
    }

    fclose(fp_novo);
    printf(GREEN "Nova imagem salva como '%s'.\n", nomeSaida);
}

void envelhecida()
{
    for (j = 0; j < linha; j++)
    {
        for (i = 0; i < coluna; i++)
        {
            fscanf(fp, "%d %d %d", &r, &g, &b);

            float fator = 0.1;
            int novaR = (r * (1 + fator));
            int novaG = (g * (1 + fator));
            int novaB = (b * (1 - fator));

            novaR = (r + 60);
            novaG = (g + 30);
            novaB = (b - 8);

            matriz[j][i].r = novaR;
            matriz[j][i].g = novaG;
            matriz[j][i].b = novaB;

            if (novaR > val)
                novaR = val;
            if (novaG > val)
                novaG = val;
            if (novaB > val)
                novaB = val;

            matriz[j][i].r = novaR;
            matriz[j][i].g = novaG;
            matriz[j][i].b = novaB;
        }
    }

    fclose(fp);
    printf("Imagem foi gerada com sucesso.\n");

    strcpy(nomeSaida, nomeImagem);
    char *ponto = strrchr(nomeSaida, '.');
    if (ponto != NULL)
        *ponto = '\0';

    strcat(nomeSaida, "_envelhecida.ppm");

    FILE *fp_novo = fopen(nomeSaida, "w");
    if (fp_novo == NULL)
    {
        printf(RED "Erro ao criar o novo arquivo!\n");
        return;
    }

    fprintf(fp_novo, "P3\n");
    fprintf(fp_novo, "%d %d\n", coluna, linha);
    fprintf(fp_novo, "%d\n", val);

    for (j = 0; j < linha; j++)
    {
        for (i = 0; i < coluna; i++)
        {
            fprintf(fp_novo, "%d\n", matriz[j][i].r);
            fprintf(fp_novo, "%d\n", matriz[j][i].g);
            fprintf(fp_novo, "%d\n", matriz[j][i].b);
        }
    }

    fclose(fp_novo);
    printf(GREEN "Nova imagem salva como '%s'.\n", nomeSaida);
}

void rotacionar90() {}

void rotacionar180() {}
