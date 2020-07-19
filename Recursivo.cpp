#include <stdio.h> 
#include <limits.h>
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int filas;
int columnas;

int max(int a, int b) {
  return (a > b)? a : b; 
  } 
  
int max(int a, int b, int c) { 
  return max(max(a, b), c); 
  } 
  
int SumaIntermedia(int arreglo[], int l, int m, int h) 
{ 
    int sum = 0; 
    int suma_izquierda; 
    for (int i = m; i >= l; i--) 
    { 
        sum = sum + arreglo[i];
				if(i==m){
						suma_izquierda= sum; 
				}
        if (sum > suma_izquierda) 
          suma_izquierda = sum; 
    } 
  
    sum = 0; 
    int suma_derecha; 
    for (int i = m+1; i <= h; i++) 
    { 
        sum = sum + arreglo[i]; 
				if(i==m+1){
						suma_derecha= sum; 
				}
        if (sum > suma_derecha) 
          suma_derecha = sum; 
    }
  
    return max(suma_izquierda + suma_derecha, suma_izquierda, suma_derecha); 
} 

int kadane(int arreglo[], int l, int h) 
{ 

   if (l == h) 
     return arreglo[l]; 
  
   int m = (l + h)/2; 
  
   return max(kadane(arreglo, l, m), kadane(arreglo, m+1, h),SumaIntermedia(arreglo, l, m, h)); 
} 

void findMaxSum(int ** M)
{
 
    int maxSum = INT_MIN;

    int izquierda, derecha, i;
    int auxiliar[filas], sum;

    for (izquierda = 0; izquierda < columnas; ++izquierda)
    {
        memset(auxiliar, 0, sizeof(auxiliar));

        for (derecha = izquierda; derecha < columnas; ++derecha)
        {

            for (i = 0; i < filas; ++i)
                auxiliar[i] += M[i][derecha];

            sum = kadane(auxiliar,0, filas-1);
						
            if (sum > maxSum)
            {
                maxSum = sum;
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


    findMaxSum(matriz);


    //Eliminamos la matriz
    for(int i=0;i<filas;i++){
        delete [] matriz[i];
    }

    delete [] matriz;


    return 0;

}

