
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
	int mLinhas,mColunas;
	cout << "Numero de linhas: ";
	cin >> mLinhas;
	cout << "Numero de colunas: ";
	cin >> mColunas;
    /// transformar em função para retornar a matriz com posições aleatorias
    int number_MAX = mLinhas*mColunas;
    int number_MIN = 1;
    srand (time(NULL));
    int random = (rand() % number_MAX) + number_MIN;
    int aux = 0;
    int matriz[mLinhas][mColunas];
    
    int matrizAux[mLinhas][mColunas];
    for(int i = 0; i < mLinhas;++i){
        for(int j = 0; j < mColunas; ++j){
            matriz[i][j] = 0;
            matrizAux[i][j] = 0;
        }
    }
    
    for(int i = 0; i < random; ++i){
        int randomX = (rand() % mLinhas) + number_MIN;
        int randomY = (rand() % mColunas) + number_MIN;
        
        matriz[randomX][randomY] = 1;
    }
    for(int i = 0; i < mLinhas;++i){
        for(int j = 0; j < mColunas; ++j){
            if(matriz[i][j] == 1){
                aux++;
            }
        }
    }
    /// Definir para onde o aspirador vai e depois qual posição devera seguir
    int posX=0,posY=0,rounds=0;
    for(int i=0; aux > 0; i++){
    	cout << "AUX: " << aux << endl;
    	system("cls");
    	
		/*A*/
		if(posX == 0 && posY == 0){
	    	if(matriz[posX][posY] == 1){
	    		matriz[posX][posY] = 0;
	    		aux--;
			}
    		int random = rand() % 2;
	    	if(random == 0) {
	    		posY++;
	    		if(matrizAux[posX][posY] == 1){
	    			posY--;
	    			posX++;
				}else{
					matrizAux[0][0] = 1;	
				}
	    	
			}	
	    	else {
				posX++;
	    		if(matrizAux[posX][posY] == 1){
	    			posX--;
					posY++;
				}else{
					matrizAux[0][0] = 1;	
				}
				
			}
		}
		/*B*/
		else if(posX == 0 && (posY > 0 && posY < (mColunas-1))){
			if(matriz[posX][posY] == 1){
				matriz[posX][posY]=0;
				aux--;
			}
			int random = rand() % 3;
			if(random == 0){
				posY++;
				if(matrizAux[posX][posY] == 1){
	    			posY--;
	    			random = rand() % 2;
	    			if(random == 0) posY--;
	    			else posX++;
				}else{
					matrizAux[posX][posY-1] = 1;	
				}

			}
			else if(random == 1){
				posY--;
				if(matrizAux[posX][posY] == 1){
	    			posY--;
	    			random = rand() % 2;
	    			if(random == 0) posY++;
	    			else posX++;
				}else{
					matrizAux[posX][posY+1] = 1;	
				}
			}
				
			else{
				posX++;
				if(matrizAux[posX][posY] == 1){
	    			posY--;
	    			random = rand() % 2;
	    			if(random == 0) posY++;
	    			else posY--;
				}else{
					matrizAux[posX-1][posY] = 1;	
				}
			}
				
		}
		/*C*/
		else if(posX == 0 && posY == (mColunas-1)){
	    	if(matriz[posX][posY] == 1){
	    		matriz[posX][posY] = 0;
	    		aux--;
			}
			int random = rand() % 2;
	    	if(random == 0){
	    		posY--;
	    		if(matrizAux[posX][posY] == 1){
	    			posY++;
	    			posX++;
				}else{
					matrizAux[posX][posY+1] = 1;	
				}

			}
	    	else{
	    		posX++;
	    		if(matrizAux[posX][posY] == 1){
	    			posY++;
	    			posX++;
				}else{
					matrizAux[posX-1][posY] = 1;	
				}
			}	
		}
		/*D*/
		else if((posX > 0 && posX < (mLinhas-1) && posY == (mColunas-1))){
			if(matriz[posX][posY] == 1){
				matriz[posX][posY] = 0;
				aux--;
			}
			int random = rand() % 3;
			if(random == 0){
				posY--;
				if(matrizAux[posX][posY] == 1){
	    			posY++;
	    			random = rand() % 2;
	    			if(random == 0) posX--;
	    			else posX++;
				}else{
					matrizAux[posX][posY-1] = 1;	
				}

			}
			else if(random == 1){
				posX--;
				if(matrizAux[posX][posY] == 1){
	    			posX++;
	    			random = rand() % 2;
	    			if(random == 0) posY--;
	    			else posX++;
				}else{
					matrizAux[posX+1][posY] = 1;	
				}

			}
				
			else {
				posX++;
				if(matrizAux[posX][posY] == 1){
	    			posX--;
	    			random = rand() % 2;
	    			if(random == 0) posY--;
	    			else posX--;
				}else{
					matrizAux[posX-1][posY] = 1;	
				}
			}
		}
		/*E*/
		else if(posX == (mLinhas-1) && posY == (mColunas-1)){
			if(matriz[posX][posY] == 1){
	    		matriz[posX][posY] = 0;
	    		aux--;
			}
			int random = rand() % 2;
	    	if(random == 0)
	    	{
	    		posY--;
	    		if(matrizAux[posX][posY] == 1){
	    			posY++;
	    			posX--;
				}else{
					matrizAux[posX][posY+1] = 1;	
				}
			}
	    		
	    	else{
	    		posX--;
				if(matrizAux[posX][posY] == 1){
	    			posX++;
	    			posY--;
				}else{
					matrizAux[posX+1][posY] = 1;	
				}
			}
	    		
		}
		/*F*/
		else if(posX == (mLinhas-1) && (posY > 0 && posY < (mColunas-1))){
			if(matriz[posX][posY] == 1){
				matriz[posX][posY] = 0;
				aux--;
			}
			int random = rand() % 3;
			if(random == 0){
				posY++;
				if(matrizAux[posX][posY] == 1){
	    			posY--;
	    			random = rand() % 2;
	    			if(random == 0) posY--;
	    			else posX--;
				}else{
					matrizAux[posX][posY-1] = 1;	
				}

			}
			else if(random == 1){
				posY--;
				if(matrizAux[posX][posY] == 1){
	    			posY++;
	    			random = rand() % 2;
	    			if(random == 0) posY++;
	    			else posX--;
				}else{
					matrizAux[posX][posY+1] = 1;	
				}
			}
				
			else {
				posX--;
				if(matrizAux[posX][posY] == 1){
	    			posX++;
	    			random = rand() % 2;
	    			if(random == 0) posY++;
	    			else posY--;
				}else{
					matrizAux[posX+1][posY] = 1;	
				}
			}
				
		}
		/*G*/
		else if(posX == (mLinhas-1) && posY == 0){
			
			if(matriz[posX][posY] == 1){
				matriz[posX][posY] = 0;
				aux--;
			}
			int random = rand() % 2;
			if(random == 0){
				posY++;
				if(matrizAux[posX][posY] == 1){
	    			posY--;
	    			posX--;
				}else{
					matrizAux[posX][posY-1] = 1;	
				}

			}
			else{
				posX--;
				if(matrizAux[posX][posY] == 1){
	    			posX++;
	    			posY++;
				}else{
					matrizAux[posX+1][posY] = 1;	
				}
			}
				
		}
		/*H*/
		else if((posX > 0 & posX < (mLinhas-1)) && posY == 0){
			
			if(matriz[posX][posY] == 1){
				matriz[posX][posY] = 0;
				aux--;
			}
			
			int random = rand() % 3;
			if(random == 0){
				posY++;
				if(matrizAux[posX][posY] == 1){
	    			posY--;
	    			random = rand() % 2;
	    			if(random == 0) posX--;
	    			else posX++;
				}else{
					matrizAux[posX][posY-1] = 1;	
				}
			}
				
			else if(random == 1){
				posX--;
				if(matrizAux[posX][posY] == 1){
	    			posX++;
	    			random = rand() % 2;
	    			if(random == 0) posY++;
	    			else posX++;
				}else{
					matrizAux[posX+1][posY] = 1;	
				}
			}
				
			else {
				posX++;
				if(matrizAux[posX][posY] == 1){
	    			posX--;
	    			random = rand() % 2;
	    			if(random == 0) posY++;
	    			else posX--;
				}else{
					matrizAux[posX-1][posY] = 1;	
				}
			}
				
		}	
		/*I*/		
		else{
			if(matriz[posX][posY] == 1){
				matriz[posX][posY] = 0;
				aux--;
			}
			int random = rand() % 4;
			if(random == 0){
				posY++;
				if(matrizAux[posX][posY] == 1){
	    			posY--;
	    			random = rand() % 3;
	    			if(random == 0) posY--;
	    			else if(random == 1) posX--;
	    			else posX++;
				}else{
					matrizAux[posX][posY-1] = 1;	
				}
			}
				
			else if(random == 1){
				posY--;
				if(matrizAux[posX][posY] == 1){
	    			posY++;
	    			random = rand() % 3;
	    			if(random == 0) posY++;
	    			else if(random == 1) posX--;
	    			else posX++;
				}else{
					matrizAux[posX][posY+1] = 1;	
				}
			}
				
			else if(random == 2){
				posX--;
				if(matrizAux[posX][posY] == 1){
	    			posX++;
	    			random = rand() % 3;
	    			if(random == 0) posY++;
	    			else if(random == 1) posY--;
	    			else posX++;
				}else{
					matrizAux[posX+1][posY] = 1;	
				}
			}
				
			else{
				posX++;
				if(matrizAux[posX][posY] == 1){
	    			posX--;
	    			random = rand() % 3;
	    			if(random == 0) posY++;
	    			else if(random == 1) posY--;
	    			else posX--;
				}else{
					matrizAux[posX-1][posY] = 1;	
				}
			}
				
		}		
		for(int i = 0; i < mLinhas;++i){
        	for(int j = 0; j < mColunas; ++j){
            	if(i==posX && j==posY)
            		cout << "X ";
            	else 
            		cout << matriz[i][j] << " ";
			}
			cout << endl;
		}
		Sleep(100);
		if(aux == 0)
			rounds = i;
	}
	cout << "Rodadas: " << rounds;
}
