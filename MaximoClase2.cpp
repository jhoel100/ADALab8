#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int filas;
int columnas;

void generar(int ** matriz,int ** acumulado,int filas,int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            acumulado[i][j]=matriz[i][j];
            if(j-1>=0){
                acumulado[i][j]=acumulado[i][j]+acumulado[i][j-1];
            }
            if(i-1>=0){
                acumulado[i][j]=acumulado[i][j]+acumulado[i-1][j];
            }
            if(i-1>=0 && j-1>=0){
                acumulado[i][j]=acumulado[i][j]-acumulado[i-1][j-1];
            }
        }
    }

}

void buscar_maximo(int ** acumulado,int filas,int columnas){
    int maximo=acumulado[0][0];
    int actual;
    int col_inicio=0;
    int col_fin=0;
    int fil_inicio=0;
    int fil_fin=0;

    //Indices iniciales y finales
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            for(int ii=i;ii<filas;ii++){
                for(int jj=j;jj<columnas;jj++){
                    actual=acumulado[ii][jj];
                    if(j-1>=0){
                        actual=actual-acumulado[ii][j-1];
                    }
                    if(i-1>=0){
                        actual=actual-acumulado[i-1][jj];
                    }
                    if(i-1>=0 && j-1>=0){
                        actual=actual+acumulado[i-1][j-1];
                    }
                    if(actual>maximo){
                        maximo=actual;
                        col_inicio=j;
                        col_fin=jj;
                        fil_inicio=i;
                        fil_fin=ii;
                    }

                }
            }


        }
    }

    cout<<maximo<<endl;

}

void imprimir(int ** matriz,int filas,int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<matriz[i][j]<<"  ";
        }
        cout<<endl;
    }
}


int main()
{
    cin>>filas;
    columnas=filas;

    //Creamos la matriz inicial
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

    //Creamos la matriz acumulada
    int** acumulado;

    acumulado = new int *[filas];

    for(int i=0;i<filas;i++){
        acumulado[i]=new int[columnas];
    }

    generar(matriz,acumulado,filas,columnas);

    buscar_maximo(acumulado,filas,columnas);

    //Eliminamos la matriz
    for(int i=0;i<filas;i++){
        delete [] matriz[i];
    }

    delete [] matriz;

    //Eliminamos la matriz
    for(int i=0;i<filas;i++){
        delete [] acumulado[i];
    }

    delete [] acumulado;


    return 0;
}
