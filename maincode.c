//Group No. 33 - CS103 project
//Members: 
//Utkarsh Verma 2301MC32
//Karan Veer Gautam Sharma	2301MC10
//Hemanth Venkata Sai Jonnadula	2301ME20
//Lalit Thakur	2301ME27
//Masthan Vali Shaik	2301MM09
//Anshul Verma	2301MM37	
//Sushanth Yelishetty	2302MT04
//Vishnu Vardhan Ramavath	2302GT04
//Vishnu Vardhini Allam    2301AI35
//Varada Chirag Patel 2301MC38

//MATRIX: mulitplication, inverse, adjoint, print matrix, determinant

#include <stdio.h>
void matrixPrint(int* ar, int r, int c)
{
    for(int x=0; x<r; x++)
    {
        for(int y=0; y<c; y++)
        {
            printf("%d\t", *(ar+ r*x + y) );  
        }
        printf("\n");
    } 
    printf("\n");
}

void matrixInput(int* ar, int r, int c)
{
    for(int x=0; x<r; x++)
    {
        for(int y=0; y<c; y++)
        {
            printf("ar[%d][%d] = ",x,y);
            scanf("%d" ,(ar+ r*x + y));  
        }
    }
    printf("\n");
}

void matrixMulti()
{
    printf("Calculating A x B :\n");
    
    printf("Order of A (r x c): \n");
    int a,b;
  
    scanf("%d%d",&a,&b);
    int m1[a][b];
  
    printf("Enter matrix A: \n");
    matrixInput(*m1,a,b);
    
    printf("Order of B (r x c): \n");
    int c,d;
  
    scanf("%d%d",&c,&d);
    int m2[c][d];
  
    printf("Enter matrix B: \n");
    matrixInput(*m2,c,d);
    
    if(c!=d)
    {
        printf("NOT POSSIBLE\n");
        return;
    }
    
    int m3[a][d];
    
    printf("Input matrix A: \n");
    matrixPrint(*m1,a,b);
    
    printf("Input matrix B: \n");
    matrixPrint(*m2,c,d);
    
    printf("Ans = \n");
    for(int x=0; x<a; x++)
    {
        for(int y=0; y<d; y++)
        {
            m3[x][y]=0;
            for(int z=0; z<b; z++)
            {
                m3[x][y] += m1[x][z]* m2[z][y];
            }
        }
    }
    
    matrixPrint(*m3,a,d);
}

int matrixDet33()
{
    int m1[3][3]; 
    printf("Enter 3x3 matrix A: \n");
    matrixInput(*m1,3,3);

    int det = m1[0][0]*((m1[1][1]*m1[2][2]) - (m1[1][2]*m1[2][1]))
            - m1[0][1]*((m1[1][0]*m1[2][2]) - (m1[1][2]*m1[2][0]))
            + m1[1][1]*((m1[1][0]*m1[2][1]) - (m1[1][1]*m1[2][0]))
    ;

    printf("Matrix A: \n");
    matrixPrint(*m1,3,3);
    return det;
}

int matrixDet22()
{
    int m1[2][2];  
    printf("Enter 2x2 matrix A: \n");
    matrixInput(*m1,2,2);
    
    printf("Matrix A: \n");
    matrixPrint(*m1,2,2);
    return ((m1[0][0]*m1[1][1])-(m1[1][0]*m1[0][1]));
}

int main(){
  /*      :)     */
}
