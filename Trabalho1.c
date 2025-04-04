#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nomeImagem[100];

void tonsDeCinza();
void negativa();
void raioX();
void envelhecida();
void rotacionar90();
void rotacionar180();

int main()
{
    int opcao;

    printf("Digite o nome da imagem PPM que deseja manipular (Exemplo: imagem.ppm): ");
    scanf("%s", nomeImagem);

    do
    {
        printf("\n========================================\n");
        printf("    MENU DE MANIPULACAO DE IMAGEM\n");
        printf("========================================\n");
        printf("1. Gerar imagem em tons de cinza\n");
        printf("2. Gerar imagem negativa\n");
        printf("3. Gerar imagem raio-x\n");
        printf("4. Gerar imagem envelhecida (sepia)\n");
        printf("5. Rotacionar imagem 90 graus\n");
        printf("6. Rotacionar imagem 180 graus\n");
        printf("7. Sair\n");
        printf("========================================\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Imagem com tons de cinza.\n");
            tonsDeCinza();
            break;
        case 2:
            printf("Imagem negativa.\n");
            break;
        case 3:
            printf("Imagem raio-x.\n");
            break;
        case 4:
            printf("Imagem envelhecida (sepia).\n");
            break;
        case 5:
            printf("Imagem rotacionada 90 graus.\n");
            break;
        case 6:
            printf("Imagem rotacionada 180 graus.\n");
            break;
        case 7:
            printf("Fechando o programa.\n");
            break;
        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 7);

    return 0;
}

void tonsDeCinza()
{
    FILE *fp = fopen(nomeImagem, "r");
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

// IMPLEMENTAR AS FUNÇÕES AQUI
void negativa() {}
void raioX() {}
void envelhecida() {}
void rotacionar90() {}
void rotacionar180() {}
