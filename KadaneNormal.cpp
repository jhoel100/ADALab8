#include<bits/stdc++.h>
using namespace std;

int filas;
int columnas;

int kadane(int* arreglo, int* inicio,int* fin, int n)
{
    int sum = 0, maxSum = INT_MIN, i;

    *fin = -1;

    int inicio_local = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arreglo[i];
        if (sum < 0)
        {
            sum = 0;
            inicio_local = i + 1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *inicio = inicio_local;
            *fin = i;
        }
    }

    if (*fin != -1)
        return maxSum;

    maxSum = arreglo[0];
    *inicio = *fin = 0;

    for (i = 1; i < n; i++)
    {
        if (arreglo[i] > maxSum)
        {
            maxSum = arreglo[i];
            *inicio = *fin = i;
        }
    }
    return maxSum;
}

void SumaMaxima(int ** M)
{
    int maxSum = INT_MIN, Izquierdo_final, Derecho_final,Superior_final, Inferior_final;

    int izquierdo, derecho, i;
    int auxiliar[filas], sum, inicio, fin;

    for (izquierdo = 0; izquierdo < columnas; ++izquierdo)
    {
        memset(auxiliar, 0, sizeof(auxiliar));

        for (derecho = izquierdo; derecho < columnas; ++derecho)
        {

            for (i = 0; i < filas; ++i)
                auxiliar[i] += M[i][derecho];

            sum = kadane(auxiliar, &inicio, &fin, filas);

            if (sum > maxSum)
            {
                maxSum = sum;
                Izquierdo_final = izquierdo;
                Derecho_final = derecho;
                Superior_final = inicio;
                Inferior_final = fin;
            }
        }
    }

    cout << maxSum << endl;
}

int main()
{
	cin>>filas;
	columnas=filas;

    int** matriz;

    matriz = new int *[filas];

    for(int i=0;i<filas;i++){
        matriz[i]=new int[columnas];
    }

		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				cin>>matriz[i][j];
			}
		}  

    SumaMaxima(matriz);

    //Eliminamos la matriz
    for(int i=0;i<filas;i++){
        delete [] matriz[i];
    }

    delete [] matriz;

    return 0;

}
