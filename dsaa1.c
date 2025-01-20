#include <stdio.h>
#include <stdlib.h>


void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    
    typedef struct {
        int rowindex;
        int colindex;
    } Indexes;

    
    Indexes* arr = (Indexes*)malloc(matrixSize * (*matrixColSize) * sizeof(Indexes));
    int ind = 0;

  
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                arr[ind].rowindex = i;
                arr[ind].colindex = j;
                ind++;  
            }
        }
    }

    for (int k = 0; k < ind; k++) {
        int row = arr[k].rowindex;
        int col = arr[k].colindex;

       
        for (int j = 0; j < *matrixColSize; j++) {
            matrix[row][j] = 0;
        }
       
        for (int i = 0; i < matrixSize; i++) {
            matrix[i][col] = 0;
        }
    }

    free(arr);
}

// Function to print the matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrixSize, matrixColSize;

   
    printf("Enter the number of rows: ");
    scanf("%d", &matrixSize);
    printf("Enter the number of columns: ");
    scanf("%d", &matrixColSize);

 
    int** matrix = (int**)malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; i++) {
        matrix[i] = (int*)malloc(matrixColSize * sizeof(int));
    }

  
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Original Matrix:\n");
    printMatrix(matrix, matrixSize, matrixColSize);

    setZeroes(matrix, matrixSize, &matrixColSize);

 
    printf("Modified Matrix:\n");
    printMatrix(matrix, matrixSize, matrixColSize);

   
    for (int i = 0; i < matrixSize; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
