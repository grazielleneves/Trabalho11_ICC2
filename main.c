#include<stdio.h>
#include<stdlib.h>

int somaAmgs(int *cache, int **mapa, int i, int j, int linhas, int colunas){
    if ((i < 0) || (i == linhas) || (j == colunas)) { 
        return 0;
    }
    if(cache[x][y] != -1){
        return cache[x][y] ;
    }
    // Baixo
    int baixo = somaAmgs(cache, mapa, i + 1, j, linhas, colunas);
     // Esquerda
    int esquerda = somaAmgs(cache, mapa, i, j + 1, linhas, colunas);
 
    // Return the maximum and store the value
    return cache[x][y] = mapa[x][y] + max(baixo, esquerda); 
}
int amigosMax(int **mapa, int linhas, int colunas){
    int *cache = (int *) malloc(sizeof(int) * ((linhas*colunas) + 1));
    int max_amg = 0;
    for(int i = 0; i <= linhas; i++){
        for(int j = 0; i <= colunas; j++){
            cache[i]=-1;
        }   
    }
    max_amg = somaAmgs(cache, mapa, linhas, colunas);
    free(cache);

    return max_amg;  
}
int main(){
    int linhas, colunas, count = 0, c1 = 0, c2 = 0, aux = 0, count2 = 0;
    int **mapa;
    int *amigos;
    scanf("%d %d", &linhas, &colunas);
    printf("%d %d", linhas, colunas);
    mapa = (int**)malloc(sizeof(int*)*(linhas*colunas));
    for(int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            mapa[i] = (int*)malloc(sizeof(int)*(linhas*colunas));            
        }
    }
    for(int i = 0; i < linhas; i++){//lendo esquinas
        for(int j = 0; j < colunas; j++){
            //scanf("%d", &caminho[i][j]);
            mapa[i][j]=count;//variável para auxiliar nos valores de cada esquina, ex: mapa[0][0]=0, mapa[0][1]=1 e etc
            count++;
        }
    }
    /*for(int i = 0; i < linhas; i++){//lendo esquinas
        for(int j = 0; j < colunas; j++){
            //scanf("%d", &caminho[i][j]);
            mapa[i][j]=count;//variável para auxiliar nos valores de cada esquina, ex: mapa[0][0]=0, mapa[0][1]=1 e etc
            count++;
            //condições para somar posições para a matriz de amigos
            if(mapa[i+1][j]!=0 && mapa[i][j+1]!=0){
                count2=count2+2;
            }
            else if(mapa[i+1][j]!=0 || mapa[i][j+1]!=0){
                count2++;
            }
        }
    }
    printf("%d", count2);
    amigos = (int*)malloc(count2*sizeof(int));
    for(int k = 0; k < count2; k++){
        scanf("%d %d %d", &amigos[k], &c1, &c2);
        //scanf("%d", &c1, &c2);

    }
    /*for(i = 0; i < linhas; i++){//ex: mapa[0][0] tem que ler mapa[0][1] e mapa[1][0] -> colunas e linhas adjacentes
        for(j = 0; j < colunas; j++){
            scanf("%d ", aux);
            scanf("%d %d", &c1, &c2);
            if(mapa[i][j]==c1){//posição coluna 1 igual 
                amigos[i][j]=aux;//matriz dos amigos entre os caminhos, caminhos não adjacentes receberão sempre 0
            }
            else{
                amigos[i][j]=0;
            }
            
        }
    }*/

    //imprimir matriz e vetor pra testar
    for(int i = 0; i < linhas; i++){
        printf("\n");
        for(int j = 0; j < colunas; j++){
            printf("%d ", mapa[i][j]);
        }
    }
    /*for(int k = 0; k < count2; k++){
        printf("\n%d", amigos[k]);
    }*/
    for(int i = 0;i < linhas; i++) {
        free(mapa[i]);
    }
    free(mapa);
    //free(amigos);
}
