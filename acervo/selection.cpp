/////////////

#include <iostream>
using namespace std;


void troca(int& a, int& b)
{
    int aux = a;  a = b;  b = aux;
}

void selection_sort(int* v, int size)
{
    for(int i = 0; i <= size-1; i++)
    {
        int min = i;

        for(int j = i+1; j < size; j++)
        {
            if(v[min] > v[j]) { min = j; }
        }

        troca(v[min], v[i]);
    }
}



int main(int argc, const char* argv[])
{
    int v[] = {45, 56, 12, 43, 95, 19, 8, 67};

    selection_sort(v, 8);
    
    for(int i : v) {cout << i << "  ";} cout << endl;
}