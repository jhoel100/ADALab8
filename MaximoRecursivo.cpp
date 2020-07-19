#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int filas;
int columnas;
int col_inicio=0;
int col_fin=0;
int fil_inicio=0;
int fil_fin=0;

void generar(int ** matriz,int ** acumulado){
    int sumatoria=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            sumatoria=0;
            //Halla la sumatoria local
            for(int ii=0;ii<=i;ii++){
                for(int jj=0;jj<=j;jj++){
                    sumatoria=sumatoria+matriz[ii][jj];
                }
            }
            //Coloca la Sumatoria dentro de la matriz acumulada
            acumulado[i][j]=sumatoria;
        }
    }

}

void Busqueda(int** acumulado, int x, int y,int xx,int yy,int& maximo)
{
    if (x < filas && y < columnas && xx < filas && yy < columnas)
    {
        //cout<<xx<<" "<<x<<" "<<yy<<" "<<y<<endl;
        //Realiza los calculos
        if(x<=xx &&y<=yy){
            int actual;
            actual=acumulado[xx][yy];

            if(y-1>=0){
                actual=actual-acumulado[xx][y-1];
            }
            if(x-1>=0){
                actual=actual-acumulado[x-1][yy];
            }
            if(x-1>=0 && y-1>=0){
                actual=actual+acumulado[x-1][y-1];
            }
            if(actual>maximo){
                maximo=actual;
                col_inicio=y;
                col_fin=yy;
                fil_inicio=x;
                fil_fin=xx;
            }

        }

        if (xx == (filas-1) && x == (filas-1) && yy == (columnas-1) )
        {
            y++;
						yy=y;           
						x = 0;
            xx = 0;
        }
        else{
            if (xx == (filas-1) && x == (filas-1) ){
                x = 0;
                xx = 0;
                yy++;
            }else{
                if(xx == filas-1){
                    x++;
                    xx=x;
                }else{
                    xx++;
                }

            }
        }

	      Busqueda(acumulado, x, y,xx,yy,maximo);
    }

}


void buscar_maximo2(int ** acumulado){
    int maximo=acumulado[0][0];

    Busqueda(acumulado,0,0,0,0,maximo);
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

    generar(matriz,acumulado);

    buscar_maximo2(acumulado);

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
