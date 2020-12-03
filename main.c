#include <stdio.h>
#include <stdlib.h>
#define row 100
#define col 100

void matrixOut(int R, int C, int mat[row][col]);

void matrixIn(int R, int C, int mat[row][col]);

void matrixAdd(int R, int C, int mat[row][col], int mat1[row][col], int mat2[row][col]);

void matrixSub(int R, int C, int mat[row][col], int mat1[row][col], int mat2[row][col]);

void matrixMulti(int R, int R1, int C1, int mat[row][col], int mat1[row][col], int mat2[row][col]);

void matrixTrs(int R, int C, int mat[row][col]);

int matrixDet(int O, int mat[row][col]);

void matrixAdj(int O, int mat[row][col], int mat1[row][col]);

void matrixInv(int O, int mat[row][col], float mat1[row][col]);

void matrixScl(int R, int C, int mat[row][col], int mat1[row][col], int S);

int main(void)
{
    int choice, R, C, R1, C1, O, S, mat[row][col], mat1[row][col], mat2[row][col];
    float mat3[row][col];

    printf("1.For addition.\n2.For subtraction.\n3.For multiplication.\n4.To perform a transpose.\n5.To calculate the determinant of a matrix.\n6.calculate the adjoint of a matrix\n7.calculate the inverse of a matrix\n8.To scale the matrix by a constant N\nChoose an arithmetic matrix operator: ");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
        printf("Enter the number of rows and columns of the matrices you would like to add\n");
        scanf("%d %d", &R,&C);

        printf("Enter the elements of your first %dX%d matrix:\n", R,C);

        matrixIn(R,C,mat);

        printf("The elements of your first matrix are:\n");

        matrixOut(R,C,mat);

        printf("Enter the elements of your second %dX%d matrix:\n", R,C);

        matrixIn(R,C,mat1);

        printf("The elements of your second matrix are:\n");

        matrixOut(R,C,mat1);

        printf("The sum of both matrices is:\n");

        matrixAdd(R,C,mat,mat1,mat2);

        matrixOut(R,C,mat2);

        break;
    case 2:
        printf("Enter the number of rows and columns of the matrices you would like to subtract\n");
        scanf("%d %d", &R,&C);

        printf("Enter the elements of your first %dX%d matrix:\n", R,C);

        matrixIn(R,C,mat);

        printf("The elements of your first matrix are:\n");

        matrixOut(R,C,mat);

        printf("Enter the elements of your second %dX%d matrix:\n", R,C);

        matrixIn(R,C,mat1);

        printf("The elements of your second matrix are:\n");

        matrixOut(R,C,mat1);

        printf("The subtraction of both matrices is:\n");

        matrixSub(R,C,mat,mat1,mat2);

        matrixOut(R,C,mat2);

        break;
    case 3:
        printf("Enter the number of rows and columns of the first matrix you would like to multiply:\n");
        scanf("%d %d", &R,&C);

        printf("Enter the number of rows and columns of the second matrix you would like to multiply:\n");
        scanf("%d %d", &R1,&C1);

        if(C!=R1){
            printf("The matrices can't be multiplied");
            exit(0);
        }

        printf("Enter the elements of your first %dX%d matrix:\n", R,C);

        matrixIn(R,C,mat);

        printf("The elements of your first matrix are:\n");

        matrixOut(R,C,mat);

        printf("Enter the elements of your second %dX%d matrix:\n", R1,C1);

        matrixIn(R1,C1,mat1);

        printf("The elements of your first matrix are:\n");

        matrixOut(R1,C1,mat1);

        printf("The product of the matrices is:\n");

        matrixMulti(R,R1,C1,mat,mat1,mat2);

        matrixOut(R,C,mat2);

        break;
    case 4:
        printf("Enter the rows and columns of your matrix:\n");
        scanf("%d %d", &R, &C);

        printf("Enter the elements of your %dX%d matrix:\n", R,C);

        matrixIn(R,C,mat);

        printf("Your matrix is:\n");

        matrixOut(R,C,mat);

        printf("The transpose of your %dX%d matrix is:\n", R,C);

        matrixTrs(R,C,mat);
        break;

    case 5:
        printf("Enter the order of your matrix 2X2 or 3X3:\n");
        scanf("%d", &O);

        if(!(O==2||O==3)){
            printf("Please choose order 3X3 or 2X2");
            exit(0);
        }

        printf("Enter the element of your %dX%d matrix:\n", O,O);

        matrixIn(O,O,mat);

        printf("your matrix is:\n");

        matrixOut(O,O,mat);

        printf("The determinant of your matrix is %d", matrixDet(O,mat));

        break;

    case 6:
        printf("Enter the order of your matrix 2X2 or 3X3:\n");
        scanf("%d", &O);

        if(!(O==2||O==3)){
            printf("Please choose order 3X3 or 2X2");
            exit(0);
        }

        printf("Enter the elements of your %dX%d matrix:\n", O,O);

        matrixIn(O,O,mat);

        printf("Your matrix is:\n");

        matrixOut(O,O,mat);

        printf("the adjoint of your %dX%d matrix is:\n", O,O);

        matrixAdj(O,mat,mat1);

        matrixOut(O,O,mat1);

        break;

    case 7:
        printf("Enter the order of your matrix 2X2 or 3X3:\n");
        scanf("%d", &O);

        if(!(O==2||O==3)){
            printf("Please choose order 3X3 or 2X2");
            exit(0);
        }

        printf("Enter the elements of your %dX%d matrix:\n", O,O);

        matrixIn(O,O,mat);

        printf("Your matrix is:\n");

        matrixOut(O,O,mat);

        printf("The inverse of matrix %dX%d is:\n", O,O);

        matrixInv(O,mat,mat3);

        for(int i=0; i<O; i++){
            printf("[\t");
            for(int j=0; j<O; j++){
                printf("%.2f\t", mat3[i][j]);
            }
            printf("]\n");
        }
        break;
    case 8:
        printf("Enter the rows and columns of your matrix:\n");
        scanf("%d %d", &R, &C);

        printf("Enter the scale: ");
        scanf("%d", &S);

        printf("Enter the elements of your %dX%d matrix:\n", R,C);

        matrixIn(R,C,mat);

        printf("your %dX%d matrix is:\n", R,C);

        matrixOut(R,C,mat);

        printf("Your %dX%d matrix scaled by %d is:\n", R,C,S);

        matrixScl(R,C,mat,mat1,S);

        matrixOut(R,C,mat1);
    }

    return 0;
}

void matrixIn(int R, int C, int mat[row][col])
{
    int i, j;

    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}
void matrixOut(int R, int C, int mat[row][col])
{
    int i, j;

    for(i=0; i<R; i++){
            printf("[\t");
        for(j=0; j<C; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("]\n");
    }
}
void matrixAdd(int R, int C, int mat[row][col], int mat1[row][col], int mat2[row][col])
{
    int i, j;

    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            mat2[i][j]=mat[i][j]+mat1[i][j];
        }
    }
}
void matrixSub(int R, int C, int mat[row][col], int mat1[row][col], int mat2[row][col])
{
    int i, j;

    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            mat2[i][j]=mat[i][j]-mat1[i][j];
        }
    }
}
void matrixMulti(int R, int R1, int C1, int mat[row][col], int mat1[row][col], int mat2[row][col])
{
    int i, j, k;
    int sum=0;

        for(i=0;i<R;i++){
            for(j=0;j<C1;j++){
                for(k=0; k<R1; k++){
                    sum+=mat[i][k]*mat1[k][j];
                }
                mat2[i][j]=sum;
                sum=0;
            }
        }
}
void matrixTrs(int R, int C, int mat[row][col])
{
    int i, j;

    for(j=0; j<C; j++){
            printf("[\t");
        for(i=0; i<R; i++){
        printf("%d\t", mat[i][j]);
        }
        printf("]\n");
    }

}
int matrixDet(int O, int mat[row][col])
{
    int det=0;

    if(O==2){
        det= mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }
    else{
        det= mat[0][0] *((mat[1][1]*mat[2][2]) - (mat[2][1]*mat[1][2])) - mat[0][1] * (mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2]) + mat[0][2] * (mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1]);
    }
    return det;
}
void matrixAdj(int O, int mat[row][col], int mat1[row][col])
{
    if(O==2)
    {
        mat1[0][0]=mat[1][1];
        mat1[1][1]=mat[0][0];
        mat1[0][1]=-mat[0][1];
        mat1[1][0]=-mat[1][0];
    }
    else
    {
        mat1[0][0]=(mat[1][1]*mat[2][2]-mat[2][1]*mat[1][2]);
        mat1[1][0]=(mat[1][2]*mat[2][0]-mat[1][0]*mat[2][2]);
        mat1[2][0]=(mat[1][0]*mat[2][1]-mat[2][0]*mat[1][1]);

        mat1[0][1]=(mat[0][2]*mat[2][1]-mat[0][1]*mat[2][2]);
        mat1[1][1]=(mat[0][0]*mat[2][2]-mat[0][2]*mat[2][0]);
        mat1[2][1]=(mat[0][1]*mat[2][0]-mat[0][0]*mat[2][1]);

        mat1[0][2]=(mat[0][1]*mat[1][2]-mat[0][2]*mat[1][1]);
        mat1[1][2]=(mat[0][2]*mat[1][0]-mat[0][0]*mat[1][2]);
        mat1[2][2]=(mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0]);
    }

}
void matrixInv(int O, int mat[row][col], float mat1[row][col])
{
    int matFun[row][col];
    int det=0, i, j;

    det=matrixDet(O,mat);

    matrixAdj(O,mat,matFun);

    for(i=0; i<O; i++){
        for(j=0; j<O; j++){
            mat1[i][j]=(1/(float)det)*(float)matFun[i][j];
        }
    }

}
void matrixScl(int R, int C, int mat[row][col], int mat1[row][col], int S)
{
    int i, j;

    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            mat1[i][j]=S*mat[i][j];
        }
    }
}

