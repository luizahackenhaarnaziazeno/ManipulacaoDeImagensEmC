#include <stdio.h>

int main()
{
    int opcao;
    /*char imageName[100];
    printf("Menu de Escolha da Imagem:\n");
    printf("Digite o nome da imagem PPM que deseja manipular (com extensão .ppm): ");
    scanf("%s", imageName);
    printf("Imagem selecionada: %s\n", imageName);*/
    do
    {
        printf("Menu Do Que Fazer Com A Imagem:\n");
        printf("1. Gerar uma imagem tons de cinza\n");
        printf("2. Gerar uma imagem negativa\n");
        printf("3. Gerar uma imagem raio-x\n");
        printf("4. Gerar uma imagem envelhecida (sépia)\n");
        printf("5. Rotacionar a imagem 90º\n");
        printf("6. Rotacionar a imagem 180º\n");
        printf("7. Exit\n");
        printf("Escolha o que deseja fazer com a imagem: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("Você escolheu gerar uma imagem tons de cinza.\n");
        }
        else if (opcao == 2)
        {
            printf("Você escolheu gerar uma imagem negativa.\n");
        }
        else if (opcao == 3)
        {
            printf("Você escolheu gerar uma imagem raio-x.\n");
        }
        else if (opcao == 4)
        {
            printf("Você escolheu gerar uma imagem envelhecida (sépia).\n");
        }
        else if (opcao == 5)
        {
            printf("Você escolheu rotacionar a imagem 90º.\n");
        }
        else if (opcao == 6)
        {
            printf("Você escolheu rotacionar a imagem 180º.\n");
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