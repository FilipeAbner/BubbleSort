#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <time.h>

using namespace std;

#define MAX_ELEMENTOS 100 // define o max de elementos na lista/ tamanho do vetor

class Lista
{ // criaçaõ da classe lista

public:
    unsigned tamanho; // declaração de variaveis
    int inteiros[MAX_ELEMENTOS];

    Lista()
    {
        tamanho = 0; // construtor da lista
    }

    ~Lista()
    { // destrutor
    }

    void imprime()
    { // imprime os elementos da lista

        for (unsigned u = 0; u < tamanho; u++)
            cout << inteiros[u] << endl;

        cout << "\n"
             << endl;
    }

    void insere(unsigned posicao, int inteiro)
    {
        // verifica se a posicao solicitada é inválida (maior que a lista)
        if (posicao > tamanho)
        {
            cout << "posicao invalida" << endl;
            return;
        }

        // verifica se a lista está cheia
        if (MAX_ELEMENTOS == tamanho)
        {
            cout << "lista cheia" << endl;
            return;
        }

        // desloca todos os inteiros, a partir da posicao, uma posicao a diante

        for (int i = tamanho; i > posicao; i--)
        {
            inteiros[i] = inteiros[i - 1];
        }

        // inserindo novo valor
        inteiros[posicao] = inteiro;
        tamanho++;
    }

    void swap(int *passardireita, int *passaresquerda)
    {
        int temporario = *passardireita;  // inteiros[j]
        *passardireita = *passaresquerda; // inteiros[j]=inteiros[j+1]
        *passaresquerda = temporario;     // inteiros[j+1] = inteiros[j]
    }

    int bubbleSort(bool etapas)
    { // etapas= true para etapa 1 e false para etapa 2

        bool mudou = true;
        int nn = tamanho;
        int aux = tamanho - 1;
        int contadorAcessos = 0;
        //int valor[20] = {1, 12, 8, 70, 72, 5, 15, 20, 91, 14, 61,66, 41, 81, 88, 16, 21, 34, 90, 99}
        while (mudou == true)
        {
            mudou = false;

            for (int j = 0; j <= nn - 2; j++)
            {
                if (inteiros[j] > inteiros[j + 1])
                {
                    mudou = true;
                    aux = j;
                    swap(&inteiros[j], &inteiros[j + 1]);
                    contadorAcessos++; // contando numero de swaps
                }
            }
            nn = aux + 1;       
            if (etapas == true) // se o parametro for verdadeiro ira imprimir cada etapa da ordenação do bubblesort
                imprime();      // metodo imprime
        }
        return contadorAcessos * 3; // retorna o numero de acessos a memoria
    }

    void geraLista(int tam)
    { // recebe o tamanho da lista
        int numero;
        srand(time(NULL)); // define a semente como null(cada lista tera valores independentes das listas passadas)
        for (unsigned j = 0; j <= tam; j++)
        { // gera os elementos para a lista de acordo com o tamanho da lista com valores aleatorios entre 1 e 1000
            numero = rand() % 1000 + 1;
            insere(j, numero); // insere os elementos na lista
        }
    }

    void deletaLista()
    { // deleta todos os elementos da lista

        tamanho = 0;
    }
};

#endif