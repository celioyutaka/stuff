/*
Célio Yutaka
*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
int mochila(int pesoMaximo, int peso[], int valor[], int n);//retorna o valor maximo que pode ser colocado na mochila

void main()
{
    system("mode con:cols=200 lines=50");
    //exemplo do word
    int valor[] = {10, 15, 20};
    int peso[] = {1, 2, 3};
    int  pesoMaximo = 3;

    /*
    exemplo
    int valor[] = {3, 4, 5, 6};
    int peso[] = {2,3,4,5};
    int  pesoMaximo = 5;
    */


    int n = sizeof(valor)/sizeof(int);
    printf("\nValor = %d", mochila(pesoMaximo, peso, valor, n));
    system("pause");


}

int mochila(int pesoMaximo, int peso[], int valor[], int n)
{

    int i, j;
    //criar matriz[qtd de obj + 1][peso maximo + 1]
    int K[n+1][pesoMaximo+1];

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= pesoMaximo; j++)
        {
            if (i==0 || j==0)//zera linha e coluna 0
            {
                printf("i = %d, j = %d; 0\n", i, j);
                K[i][j] = 0;
            }
            else if (peso[i-1] <= j)
            {
                printf("i = %d; j = %d; peso[i-1] %d <= %d j ENTAO valor[i-1] + K[i-1][j-peso[i-1]]: %d + %d > %d K[i-1][j]", i,j,peso[i-1],j,valor[i-1], K[i-1][j-peso[i-1]],K[i-1][j]);

                if (valor[i-1] + K[i-1][j-peso[i-1]] > K[i-1][j])
                {
                    K[i][j] = valor[i-1] + K[i-1][j-peso[i-1]];
                     printf("  Valor[i-1]+K[i-1][j-peso[i-1]  K[i][j] = %d\n",K[i][j]);

                }
                else
                {
                    K[i][j] = K[i-1][j];
                    printf("    COPIA O DE CIMA  K[i][j] = %d\n",K[i][j]);
                }


            }
            else
            {
                printf("i = %d, j = %d; K[i][j] COPIA O DE CIMA K[i-1][j] = %d\n", i, j, K[i-1][j]);
                K[i][j] = K[i-1][j];
            }


            //printf("%d",K[i][j]);
        }
        //printf("\n");

    }

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= pesoMaximo; j++)
        {
            printf("%3d ", K[i][j]);
            if (K[i][j] == NULL && K[i][j] != 0)
            {
                printf("%3c ",'X');
            }
        }
        printf("\n");
    }
    return K[n][pesoMaximo];
}
