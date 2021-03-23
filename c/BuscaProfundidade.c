/*
Célio Yutaka 

exemplo de entrada:
8
10
0 1
0 2
0 3
0 4
1 5
2 5
3 6
4 6
5 7
6 7
0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    struct no *proximo;
    int vertice;
}no;

no *pGrafo[20];

int visitados[20];//vetor com os vetices
int n;
void criarGrafo(); //criar matriz adj
void inserir(int,int);//inserir aresta na matriz adj
void DFS(int);//algoritmo dfs, busca em profundidade

void main()
{
    fflush(stdin);
    int i;
    int n = 0;
    criarGrafo();

    //zerar vetor dos visitados
    for(i = 0; i < n; i++)
    {
        visitados[i]=0;
    }
    printf("\nDigite o numero que deseja iniciar(Exemplo: 0): ");
    scanf(" %d",&n);
    fflush(stdin);
    printf("\nOrdem em que sera percorrido: ");
    DFS(n);
}

void DFS(int i)
{
    no *p;

    printf("\n%d",i);

    p = pGrafo[i];

    visitados[i]=1;

    while( p != NULL)//enquanto p não for null
    {

        i = p->vertice;

        if(!visitados[i])//se visitados[i] for diferente de 0
        {
            DFS(i);
        }

        p = p->proximo;//vai para a proxima aresta

    }//fim while
}

void criarGrafo()
{
    int i,verticei,verticej,num_vertices;
    printf("\nDigite o numero de vertices:");

    scanf("%d",&n);



    for(i = 0; i < n; i++)
    {
        //inicializa como null
        pGrafo[i]=NULL;

        printf("\nDigite o numero de arestas:");
           scanf("%d",&num_vertices);

           for(i=0;i<num_vertices;i++)
        {
            printf("\nDigite uma aresta(u,v):");
            scanf("%d%d",&verticei,&verticej);
            inserir(verticei,verticej);
        }
    }
}

void inserir(int verticei,int verticej)
{
    no *p,*q;

    //alocacao de memoria para um novo no
    q=(no*)malloc(sizeof(no));
    q->vertice = verticej;//recebe o vertice J
    q->proximo = NULL;//proximo é vazio

    //inserir o na lista dos vetices i
    if(pGrafo[verticei] == NULL)//se pgrafo for vazio
        pGrafo[verticei] = q;   // recebe
    else
    {
        //vai para o fim da lista
        p = pGrafo[verticei];

        while(p->proximo!=NULL)//enquanto p->proximo for diferente de NULL
        {
            p=p->proximo; //p vira o p->proximo, vai para o proximo
        }
        p->proximo = q; //p->proximo recebe o q
    }
}
