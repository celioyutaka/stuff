/*
Sistema de Referência do Universo (SRU)
Sistema de Referência do Dispositivo (SRD)


EXEMPLO DE ENTRADA DE SRU PARA SRD
1       TIPO SRU PARA SRD
0       X MIN
10      X MAX
0       Y MIN
8       Y MAX
1280    X obj
1024    Y obj
3       p(X)
2       p(Y)
*/

/*EXEMPLO DE ENTRADA DE SRD PARA SRU
2       TIPO SRD PARA SRU
0       X MIN
10      X MAX
0       Y MIN
8       Y MAX
1280    X OBJ
1024    Y OBJ
384     p(X)
768     p(Y)
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tipoSistema = -1;
    int XuMin, XuMax;
    int YuMin, YuMax;
    int pX, pY;
    int respX, respY;
    int Xobj;
    int Yobj;

    while (tipoSistema != 0){//loop para repertir todos os tipos
        printf("###########################################\n");
        printf("#                                         #\n");
        printf("#                 INICIO                  #\n");
        printf("#                                         #\n");
        printf("#                                         #\n");
        printf("# COMPUTACAO GRAFICA                      #\n");
        printf("#                                         #\n");
        printf("# CELIO YUTAKA                            #\n");
        printf("#                                         #\n");
        printf("###########################################\n");
        printf(" Sistema de Origem:\n");
        printf(" [1] - SRU para SRD\n");
        printf(" [2] - SRD para SRU\n");
        printf(" [0] - Sair\n");
        scanf("%d",&tipoSistema);
        fflush(stdin);
        if (tipoSistema != 0){//cancelar loop para repertir todos os tipos
            printf("Digite o Xu(min):\n");
            scanf("%d",&XuMin);
            fflush(stdin);
            printf("Digite o Xu(max):\n");
            scanf("%d",&XuMax);
            fflush(stdin);
            printf("Digite o Yu(min):\n");
            scanf("%d",&YuMin);
            fflush(stdin);
            printf("Digite o Yu(max):\n");
            scanf("%d",&YuMax);
            fflush(stdin);
            printf("\n");
            printf("Digite o X do objeto:\n");
            scanf("%d",&Xobj);
            fflush(stdin);
            printf("Digite o Y do objeto:\n");
            scanf("%d",&Yobj);
            fflush(stdin);
            pX = 1;
            pY = 1;
            while (pX > 0 && pY > 0){//finaliza os P caso seja menor que 0
                printf("Digite os valores de P(x,y), para finalizar defina X = 0 e Y = 0:\n");
                printf("Coordenada no P(X):\n");
                scanf("%d",&pX);
                fflush(stdin);
                printf("Coordenada no P(Y):\n");
                scanf("%d",&pY);
                fflush(stdin);
                if (pX > 0 && pY > 0){
                    if (tipoSistema == 1){//SRU PARA SRD
                        respX = sruToSrdX(XuMin, XuMax, Xobj, pX);
                        respY = sruToSrdY(YuMin, YuMax, Yobj, pY);
                        printf("Valores de P(%d,%d): (%d,%d)\n\n\n",pX,pY,respX,respY);
                    }
                    else if (tipoSistema == 2){//SRD PARA SRU
                        respX = srdToSruX(XuMin, XuMax, Xobj, pX);
                        respY = srdToSruY(YuMin, YuMax, Yobj, pY);
                        printf("Valores de P(%d,%d): (%d,%d)\n\n\n",pX,pY,respX,respY);
                    }
                }

            }
        }

        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
    }


    return 0;
}

int sruToSrdX(int XuMin, int XuMax, int Xobj, int pX){
    return  (pX * Xobj) / (XuMax-XuMin);
}

int sruToSrdY(int YuMin, int YuMax, int Yobj, int pY){
    return  (pY*(-Yobj/(YuMax-YuMin)))+Yobj;
}


int srdToSruX(int XuMin, int XuMax, int Xobj, int pX){
    float pXF = pX;
    float XobjF = Xobj;
    float tempX = pXF/XobjF;

    return (tempX*(XuMax-XuMin));

}

int srdToSruY(int YuMin, int YuMax, int Yobj, int pY){
    return ((pY-Yobj)*(YuMax-YuMin))/(0-Yobj);
}
