//Calculate a determinant of a 3x3 matrix
#include <stdio.h>

int main(){
    float a,b,c,d,e,f;
    float somaTot= 0.;
    float matriz[3][3];
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%f",&matriz[i][j]);
            // printf("%d, %d", i, j);
        }
    }
    
    a = matriz[0][0] * matriz[1][1] * matriz[2][2];
    b = matriz[0][1] * matriz[1][2] * matriz[2][0];
    c = matriz[0][2] * matriz[1][0] * matriz[2][1];
    d = matriz[2][0] * matriz[1][1] * matriz[0][2];
    e = matriz[0][0] * matriz[1][2] * matriz[2][1];
    f = matriz[0][1] * matriz[1][0] * matriz[2][2];
    somaTot = (a + b + c) - (d + e + f);
    printf("%f",somaTot);
    return 0;
}
