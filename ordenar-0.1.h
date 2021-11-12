///// acervo de ordenação

#include <iostream>
#include <cstdlib>

using namespace std;


#ifndef ESTRUTURA_DE_ORDENACAO_H_INCLUDED
#define ESTRUTURA_DE_ORDENACAO_H_INCLUDED

template<typename T> void troca(T* a, T* b)
{
    T aux = *a; *a = *b; *b = aux;
}



template<typename T> void insertion_sort(T* v, int size)
{
    for(int i = 1; i < size; i++)
    {
        int j = i;
        while(j - 1 >= 0  &&  v[j] < v[j - 1])
        {
            troca(&v[j], &v[j-1]);
            j--;
        }
    }
}

template<typename T> void binary_insertion(T* v, int size)
{
    for(int i = 1; i < size; i++)
    {
        T x = v[i];
        int inicio = 0;
        int fim = i;

        while(inicio < fim)
        {
            int p = (fim + inicio) / 2;

            if(v[p] <= x){
                inicio = p + 1;
            }else{
                fim = p;
            }
        }

        int j = i;
        while( j > fim)
        {
            troca(&v[j], &v[j - 1]);
            j--;
        }
    }
}



template<typename T> void selection_sort(T* v, int size)
{
    for(int i = 0; i < size; i++)
    {
        int min = i;

        for(int j = i; j < size; j++)
        {
            if(v[j] < v[min])
            {
                min = j;
            }
        }

        troca(&v[i], &v[min]);
    }
}



template<typename T> void bubble_sort(T* v, int size)
{
    for(int i = 1; i < size; i++)
    {
        for(int j = size - 1; j >= i; j--)
        {
            if(v[j] < v[j - 1]){
                troca(&v[j], &v[j - 1]);
            }
        }
    }
}

void shake_sort(int* v, int size)   // algo esta errado, ainda não esta funcionando
{
    int inicio = 1;
    int fim = size;
    int k;

    do{
        for(int i = fim; i >= inicio; i--)
        {
            if(v[i - 1] > v[i])
            {
                troca(&v[i - 1], &v[i]);
                k = i;
            }
        }
        inicio = k + 1;

        
        for(int i = inicio; i <= fim; i++)
        {
            if(v[i - 1] > v[i])
            {
                troca(&v[i], &v[i - 1]);
                k = i;
            }
        }
        fim = k - 1;

    } while(inicio <= fim);
}



template<typename T> void merge(T* v, int inicio, int meio, int fim)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    T* l1 = new T [n1];
    for(int i = 0; i < n1; i++) { l1[i] = v[i + inicio];}

    T* l2 = new T [n2];
    for(int i = 0; i < n2; i++) { l2[i] = v[i + meio + 1]; }


    int i = 0, j = 0, k = inicio;
    while(i < n1  &&  j < n2)
    {
        if(l1[i] < l2[j])
        {
            v[k] = l1[i];
            i++;
        }else{
            v[k] = l2[j];
            j++;
        }
        
        k++;
    }

    while(i < n1)
    {
        v[k] = l1[i];
        i++; k++;
    }

    while (j < n2)
    {
        v[k] = l2[j];
        j++; k++;
    }
}

template<typename T> void merge_sort(T* v, int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        merge_sort(v, inicio, meio);
        merge_sort(v, meio+1, fim);

        merge(v, inicio, meio, fim);
    }
}



template<typename T> int pivo(T* v, int inicio, int fim)
{
    T p = v[fim];
    int seta = inicio;

    for(int i = inicio; i < fim; i++)
    {
        if(v[i] <= p)
        {
            troca(&v[seta], &v[i]);
            seta++;
        }
    }

    troca(&v[seta], &v[fim]);

 return seta;
}

template<typename T> void quick_sort(T* v, int inicio, int fim)
{
    if(inicio < fim)
    {
        int p = pivo(v, inicio, fim);

        quick_sort(v, inicio, p-1);
        quick_sort(v, p+1, fim);
    }
}


namespace iterativo{

    void quick_sort(int* v, int inicio, int fim);
}

void iterativo::quick_sort(int* v, int inicio, int fim)
{
    int* stack = new int [fim - inicio + 1];
    int seta = inicio - 1;

    stack[++seta] = inicio;
    stack[++seta] = fim;

    while(seta >= 0)
    {
        fim = stack[seta--];
        inicio = stack[seta--];

        int p = pivo(v, inicio, fim);

        if(inicio < p-1)
        {
            stack[++seta] = inicio;
            stack[++seta] = p - 1;
        }

        if(p + 1 < fim)
        {
            stack[++seta] = p + 1;
            stack[++seta] = fim;
        }
    }
}






#endif
