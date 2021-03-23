/*
Célio Yutaka

Fontes:
Sequencia de Fibonacci modificada
https://en.wikipedia.org/wiki/Leonardo_number
Conceitos de binário
http://www.tutorialspoint.com/cprogramming/c_operators.htm
Slide - Habib
http://pt.slideshare.net/habib_786/smooth-sort?from_action=save
Sobre SmoothSort
http://www.cs.utexas.edu/users/EWD/transcriptions/EWD07xx/EWD796a.html

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//TAMANHO DO VETOR
#define TAMANHO 100000
//QUANTIDADE DE TESTES POR TIPO, EXEMPLO: 10 TESTES DE ORDENADO, INVERSO, ALEATORIO
#define NUMERO_DE_TESTES 10

#define MENOR(A,B) (A <= B)
//Trocar quando o numero for subir na arvore
#define SOBE(IA,IB) temp = IA; IA += IB + 1; IB = temp;
//Trocar quando o numero for subir na arvore
#define DESCE(IA,IB) temp = IB; IB = IA - IB - 1; IA = temp;

//Ponteiro de inteiro global, para criação do vetor das arvores do smooth
int** pSmooth;

int q, r, p, b, c, r1, b1, c1;

void SelectionSort(int *v, int tam);
void InsertionSort(int *v, int tam);
void MergeSort(int vet[], int esqueda, int direta);
    void merge(int vet[], int esq, int meio, int dir);
void QuickSort (int *v, int primeiro, int ultimo);
void HeapSort(int vet[], int tam);
    void CriarHeap(int vet[], int inicio, int fim);
void SmoothSort(int** vet[], int tam);
    void Trinkle();
    void SemiTrinkle();
    void Sift();


int main()
{

    int vetOrdenado[TAMANHO];
    int vetInvertido[TAMANHO];
    int vetAleatorio[TAMANHO];
    int vet[TAMANHO];
    int i, j;
    double tempoGasto;
    clock_t tempoInicial, tempoFinal;

    //CRIAR VETORES
    //ORDENADO, INVERTIDO E ALEATORIO
    for (i = 0; i < TAMANHO; i++)
    {
        vet[i] = 0;
        vetOrdenado[i] = i;
        vetInvertido[i] =  TAMANHO - i;
        vetAleatorio[i] = (rand() %  TAMANHO);
    }

/*
####################################################################################################
####################################################################################################
    SELECTION SORT
####################################################################################################
####################################################################################################
*/
    printf("\nSelectionSort\n");
    printf("\n\nORDENADO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetOrdenado[i];
        }
        tempoInicial = clock();
        SelectionSort(vet,TAMANHO);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
    printf("\n\nINVERTIDO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetInvertido[i];
        }
        tempoInicial = clock();
        SelectionSort(vet,TAMANHO);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
    printf("\n\nALEATORIO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetAleatorio[i];
        }
        tempoInicial = clock();
        SelectionSort(vet,TAMANHO);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
/*
####################################################################################################
####################################################################################################
    INSERTION SORT
####################################################################################################
####################################################################################################
*/

    printf("\n\nInsertionSort\n");
    printf("\n\nORDENADO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetOrdenado[i];
        }
        tempoInicial = clock();
        InsertionSort(vet,TAMANHO);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
    printf("\n\nINVERTIDO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetInvertido[i];
        }
        tempoInicial = clock();
        InsertionSort(vet,TAMANHO);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
    printf("\n\nALEATORIO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetAleatorio[i];
        }
        tempoInicial = clock();
        InsertionSort(vet,TAMANHO);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
/*
####################################################################################################
####################################################################################################
    MERGE SORT
####################################################################################################
####################################################################################################
*/
    printf("\n\nMergeSort\n");
    printf("\n\nORDENADO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetOrdenado[i];
        }
        tempoInicial = clock();
        MergeSort(vet,0,TAMANHO-1);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
    printf("\n\nINVERTIDO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetInvertido[i];
        }
        tempoInicial = clock();
        MergeSort(vet,0,TAMANHO-1);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
    printf("\n\nALEATORIO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetAleatorio[i];
        }
        tempoInicial = clock();
        MergeSort(vet,0,TAMANHO-1);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }

/*
####################################################################################################
####################################################################################################
    QUICK SORT
####################################################################################################
####################################################################################################
*/
    printf("\n\nQuickSort\n");
    printf("\n\nORDENADO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetOrdenado[i];
        }
        tempoInicial = clock();
        QuickSort(vet,0,TAMANHO-1);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
    printf("\n\nINVERTIDO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetInvertido[i];
        }
        tempoInicial = clock();
        QuickSort(vet,0,TAMANHO-1);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
    printf("\n\nALEATORIO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetAleatorio[i];
        }
        tempoInicial = clock();
        QuickSort(vet,0,TAMANHO-1);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }

/*
####################################################################################################
####################################################################################################
    HEAP SORT
####################################################################################################
####################################################################################################
*/
    printf("\n\nHeapSort\n");
    printf("\n\nORDENADO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetOrdenado[i];
        }
        tempoInicial = clock();
        HeapSort(vet,TAMANHO);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
    printf("\n\nINVERTIDO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetInvertido[i];
        }
        tempoInicial = clock();
        HeapSort(vet,TAMANHO);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
    printf("\n\nALEATORIO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetAleatorio[i];
        }
        tempoInicial = clock();
        HeapSort(vet,TAMANHO);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
/*
####################################################################################################
####################################################################################################
    SMOOTH SORT
####################################################################################################
####################################################################################################
*/
    printf("\n\nSmoothSort\n");
    printf("\n\nORDENADO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetOrdenado[i];
        }
        tempoInicial = clock();
        SmoothSort(vet,TAMANHO);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
    printf("\n\nINVERTIDO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetInvertido[i];
        }
        tempoInicial = clock();
        SmoothSort(vet,TAMANHO);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }
    printf("\n\nALEATORIO\n");
    for (j = 0; j < NUMERO_DE_TESTES; j++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = vetAleatorio[i];
        }
        tempoInicial = clock();
        SmoothSort(vet,TAMANHO);
        tempoFinal = clock();
        tempoGasto = (tempoFinal-tempoInicial);

        printf("\n%.2f", tempoGasto);
    }


    printf("\n");
    system("pause");

    return 0;
}

void SelectionSort(int *v, int tam)
{
    int i, j, aux, min;

    for (i = 0; i <= tam-1; i++)
    {
        min=i;
        for (j = i+1; j <= tam-1; j++)
        {
            if (v[j] < v[min])
            {
            min=j;
            }
        }
            if(i != min)
            {
                aux=v[i];
                v[i]=v[min];
                v[min]=aux;
            }
    }
}

void InsertionSort(int *v, int tam)
{
    int i, j, aux;

    for (j = 0; j <= tam-1; j++)
    {
        aux = v[j];
        i = j-1;

        while ((i >= 0) && (v[i] > aux))
        {
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = aux;
    }
}

void merge(int vet[], int esq, int meio, int dir)
{
    int i, j, k;
    int n1 = meio - esq + 1;//inicio até a metade
    int n2 =  dir - meio;//metade até o fim

    int vetEsq[n1], vetDir[n2];

    //passa valores
    for (i = 0; i < n1; i++)
    {
        vetEsq[i] = vet[esq + i];
    }
    //passa valores
    for (j = 0; j < n2; j++)
    {
        vetDir[j] = vet[meio + 1+ j];
    }

    //reset variaveis
    i = 0;
    j = 0;
    k = esq;

    //i menor que metade1 e j menor que metade 2
    while (i < n1 && j < n2)
    {
        //se vetEsquerda for menor que vetDireita
        if (vetEsq[i] <= vetDir[j])
        {
            //vet recebe vetEsquerda
            vet[k] = vetEsq[i];
            i++;
        }
        else
        {
            //se não vet recebe vetDireita
            vet[k] = vetDir[j];
            j++;
        }
        k++;
    }

    //enquanto i < metade1
    while (i < n1)
    {
        //vet recebe vetEsquerda
        vet[k] = vetEsq[i];
        i++;
        k++;
    }
    //enquanto j < metade 2
    while (j < n2)
    {
        //vetr recebe vetDireita
        vet[k] = vetDir[j];
        j++;
        k++;
    }
}

void MergeSort(int vet[], int esqueda, int direta)
{
    int meio;
    if (esqueda < direta)
    {
        meio = esqueda+(direta-esqueda)/2;

        MergeSort(vet, esqueda, meio);//começo até metade
        MergeSort(vet, meio+1, direta);//metade+1 ate o fim

        merge(vet, esqueda, meio, direta);
    }
}

void QuickSort (int *v, int primeiro, int ultimo)
{
    int i, j, m, aux;
    i = primeiro;
    j = ultimo;
    m = v[(i+j)/2];
    do
    {
        while (v[i] < m)
        {
            i++;
        }

        while (v[j] > m)
        {
            j--;
        }

        if (i<=j)
        {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            i++;
            j--;
        }
   }while (i <= j);

    if (primeiro < j)
    {
        QuickSort(v,primeiro,j);
    }

    if (ultimo > i)
    {
       QuickSort(v,i,ultimo);
    }
}

void CriarHeap(int vet[], int inicio, int fim)
{
    int aux;
    int j;

    //aux recebe pai
    aux = vet[inicio];
    j = inicio * 2 + 1;
    //Enquanto nao chegar no fim, filho menor que vetor
    while( j <= fim)
    {
        //Se nao chegou no fim,  filho menor que vetor
        if (j < fim)
        {
            //Possui 2 filhos
            if (vet[j] < vet[j + 1])
            {
                j++;
            }
        }
        //se filho é maior pai
        if (aux < vet[j])
        {
            //filho = pai
            vet[inicio] = vet[j];
            inicio = j;
            j = 2 * inicio + 1;
        }
        else
        {
            j = fim + 1;
        }
    }
    // Pai velho ocupa lugar do ultimo filho
    vet[inicio] = aux;
}

void HeapSort(int vet[],int tam)
{
    int i, aux;
    //CRIAR HEAP
    for(i = (tam - 1)/2;i >= 0; i--)
    {
        CriarHeap(vet, i, tam-1);
    }
    for (i = tam-1; i >= 1; i--)
    {
        //PEGAR O MAIOR VALOR E COLOCAR NA POSIÇÃO CORRESPONDENTE NO ARRAY
        aux = vet[0];
        vet[0] = vet[1];
        vet[i] = aux;
        //RECONSTRUIR HEAP
        CriarHeap(vet, 0, i - 1);
    }
}


void Sift()
{
	int r0, r2, temp;
	int* t;
	r0 = r1;
	t = pSmooth[r0];

	while (b1 >= 3)
	{
		r2 = r1 - b1 + c1;

		if (!MENOR(pSmooth[r1 - 1], pSmooth[r2]))
		{
			r2 = r1 - 1;
			DESCE(b1, c1);
		}

		if (MENOR(pSmooth[r2], t))
		{
			b1 = 1;
		}
		else
		{
			pSmooth[r1] = pSmooth[r2];
			r1 = r2;
			DESCE(b1, c1);
		}
	}

	if (r1 - r0)
		pSmooth[r1] = t;
}

void Trinkle()
{
	int p1, r2, r3, r0, temp;
	int* t;
	p1 = p;
	b1 = b;
	c1 = c;
	r0 = r1;
	t = pSmooth[r0];

	while (p1 > 0)
	{
		while ((p1 & 1) == 0)
		{
		    //p1 = p1 >> 1
            //0000 0100 >> 1 = 0000 0010
			p1 >>= 1;
			SOBE(b1, c1)
		}

		r3 = r1 - b1;

		if ((p1 == 1) || MENOR(pSmooth[r3], t))
		{
			p1 = 0;
		}
		else
		{
			--p1;

			if (b1 == 1)
			{
				pSmooth[r1] = pSmooth[r3];
				r1 = r3;
			}
			else
			{
				if (b1 >= 3)
				{
					r2 = r1 - b1 + c1;

					if (!MENOR(pSmooth[r1 - 1], pSmooth[r2]))
					{
						r2 = r1 - 1;
						DESCE(b1, c1);
						//p1 = p1 << 1
                        //0000 0001 << 1 = 0000 0010
						p1 <<= 1;
					}
					if (MENOR(pSmooth[r2], pSmooth[r3]))
					{
						pSmooth[r1] = pSmooth[r3]; r1 = r3;
					}
					else
					{
						pSmooth[r1] = pSmooth[r2];
						r1 = r2;
						DESCE(b1, c1);
						p1 = 0;
					}
				}
			}
		}
	}
    //se r0 - r1 for 1
	if (r0 - r1)
		pSmooth[r1] = t;

	Sift();
}

void SemiTrinkle() {
	int* T;
	r1 = r - c;

	if (!MENOR(pSmooth[r1], pSmooth[r]))
	{
		T = pSmooth[r];
		pSmooth[r] = pSmooth[r1];
		pSmooth[r1] = T;
		Trinkle();
	}
}


void SmoothSort(int** vet[], int tam) {
	int temp;
	pSmooth = vet;
	q = 1;
	r = 0;
	p = 1;
	b = 1;
	c = 1;

	while (q < tam) {
		r1 = r;
        //Outros sinais, http://www.tutorialspoint.com/cprogramming/c_operators.htm
        //Se p na base 7 for igual a 3
        //bit a bit
		if ((p & 7) == 3)
		{
			b1 = b;
			c1 = c;
			Sift();
			//Deslocar a direita
            //60 >> 2 = 15
            // 0011 1100 >> 2 = 0000 1111
			p = (p + 1) >> 2;
			SOBE(b, c);
			SOBE(b, c);
		}
		else if ((p & 3) == 1) {
			if (q + c < tam)
			{
				b1 = b;
				c1 = c;
				Sift();
			}
			else
			{
				Trinkle();
			}

			DESCE(b, c);
			//p = p << 1
            //0000 0001 << 1 = 0000 0010
			p <<= 1;

			while (b > 1)
			{
				DESCE(b, c);
				p <<= 1;
			}

			p++;
		}

		q++;
		r++;
	}

	r1 = r;
	Trinkle();

	while (q > 1)
	{
		--q;

		if (b == 1)
		{
			r--;
			p--;

			while ((p & 1) == 0)
			{
				p >>= 1;
				SOBE(b, c);
			}
		}
		else
		{
			if (b >= 3) {
				p--;
				r = r - b + c;
				if (p > 0)
					SemiTrinkle();

				DESCE(b, c);
				p = (p << 1) + 1;
				r = r + c;
				SemiTrinkle();
				DESCE(b, c);
				p = (p << 1) + 1;
			}
		}
	}
}

