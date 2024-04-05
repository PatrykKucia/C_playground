#include <stdio.h>
#include <stdbool.h>
#define ROWS 2
#define COLS 2

struct MatrixValueInfo {
    int row;
    int col;
    int value;
};

struct MinResult{
    int row;
    int col;
    int value;
};

struct MaxResult {
    int row;
    int col;
    int value;
};

void Balance(struct MinResult minRes, struct MaxResult maxRes) {
    if (minRes.row == maxRes.row && minRes.col == maxRes.col && minRes.value == maxRes.value) {
        printf("Saddle point!\n");
    } else {
        printf("NO Saddle point.\n");
    }
}

struct MinResult findLowest(struct MatrixValueInfo *Values, int size)
{
    int tempdecision;
    struct MinResult result;
    printf("Searching for Lowest value in chosen group\n");
    result.value = Values[0].value;
    result.row = Values[0].row;
    result.col = Values[0].col;

    for(int z=1; z<size; z++)
    {
       if(Values[z].value< result.value)
       {
            result.value = Values[z].value;
            result.row = Values[z].row;
            result.col  = Values[z].col;
       }
       else if(Values[z].value == result.value)
       {
            printf("overvrite (%d row:%d col:%d) with new min value (row:%d col:%d)?\n",result.value, result.row+1, result.col+1,Values[z].row+1,Values[z].col+1);
            printf("1->Yes\n2->No\n");
            scanf("\n%d",&tempdecision);
            if(tempdecision==1){
            result.value = Values[z].value;
            result.row = Values[z].row;
            result.col  = Values[z].col;
                printf("overvrited, new value:%d, row:%d col:%d\n",Values[z].value,Values[z].row+1,Values[z].col+1);
            }
            else{
                printf("no overwriting curent value:value:%d, row:%d col:%d\n",result.value,result.row+1,result.col+1);
            }
       }
    }
    printf("Lowest Value:\n");
    printf("Column %d, Row %d, min %d\n", result.col+1 ,result.row+1, result.value);
    return result;
}

struct MaxResult findMax(struct MatrixValueInfo *Values,int size)
{
    int tempdecision;
    struct MaxResult result;
    printf("Searching for Max value in chosen group\n");
    result.value = Values[0].value;
    result.row = Values[0].row;
    result.col = Values[0].col;

    for(int z=1; z<size; z++)
    {
       if(Values[z].value > result.value)
       {
       result.value = Values[z].value;
       result.row = Values[z].row;
       result.col  = Values[z].col;
       }
    else if(Values[z].value == result.value)
    {
        printf("overvrite (%d row:%d col:%d) with new max value (row:%d col:%d)?\n",result.value, result.row+1, result.col+1,Values[z].row+1,Values[z].col+1);
        printf("1->Yes\n2->No\n");
        scanf("\n%d",&tempdecision);
        if(tempdecision==1){
            result.value = Values[z].value;
            result.row = Values[z].row;
            result.col  = Values[z].col;
                printf("overvrited, new value:%d, row:%d col:%d\n",Values[z].value,Values[z].row+1,Values[z].col+1);
            }
            else{
                printf("no overwriting curent value:value:%d, row:%d col:%d\n",result.value,result.row+1,result.col+1);
            }
    }
    }
    printf("Max Value:\n");
    printf("Column %d, Row %d, min %d\n", result.col+1 ,result.row+1, result.value);
    return result;
}

//searching for maximum value of every matrix column
void findMaxColValue(int matrix[ROWS][COLS], struct MatrixValueInfo *maxValues) {                                                                   //DO WERYFIKACJI
int tempdecision;
    for (int j = 0; j < COLS; j++) {
        int maxValue = matrix[0][j];//matrix in c 1[]->rows 2[]->cols
        maxValues[j].row = 0;
        maxValues[j].col = j;
        maxValues[j].value = maxValue;

        for (int i = 1; i < ROWS; i++) {
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
                maxValues[j].row = i;
                maxValues[j].col = j;
                maxValues[j].value = maxValue;
                
            }
            else if (matrix[i][j] == maxValue){
                printf("overvrite (%d row:%d col:%d) with new max value (row:%d col:%d)?\n",maxValue,maxValues[j].row+1,maxValues[j].col+1,j+1,i+1);
                printf("1->Yes\n2->No\n");
                scanf("\n%d",&tempdecision);
                if(tempdecision==1){
                    maxValue = matrix[i][j];
                    maxValues[j].row = i;
                    maxValues[j].col = j;
                    maxValues[j].value = maxValue;
                    printf("overvrited, new value:%d, row:%d col:%d\n",maxValue,maxValues[j].row+1,maxValues[j].col+1);
                }
                else{
                    printf("no overwriting curent value:value:%d, row:%d col:%d\n",maxValue,maxValues[j].row+1,maxValues[j].col+1);
                }

            }
        }
    }
}

void findMinColValue(int matrix[ROWS][COLS], struct MatrixValueInfo *minValues) {
    int tempdecision;
    for (int j = 0; j < COLS; j++) {
        int minValue = matrix[0][j];//matrix in c 1[]->rows 2[]->cols
        minValues[j].row = 0;
        minValues[j].col = j;
        minValues[j].value = minValue;

        for (int i = 1; i < ROWS; i++) {
            if (matrix[i][j] < minValue) {
                minValue = matrix[i][j];
                minValues[j].row = i;
                minValues[j].col = j;
                minValues[j].value = minValue;
                
            }
        else if (matrix[i][j] == minValue){
                printf("overvrite (%d row:%d col:%d) with new min value (row:%d col:%d)?\n",minValue,minValues[j].row+1,minValues[j].col+1,j+1,i+1);
                printf("1->Yes\n2->No\n");
                scanf("\n%d",&tempdecision);
                if(tempdecision==1){
                    minValue = matrix[i][j];
                    minValues[j].row = i;
                    minValues[j].col = j;
                    minValues[j].value = minValue;
                    printf("overvrited, new value:%d, row:%d col:%d\n",minValue,minValues[j].row+1,minValues[j].col+1);
                }
                else{
                    printf("no overwriting curent value:value:%d, row:%d col:%d\n",minValue,minValues[j].row+1,minValues[j].col+1);
                }

            }
        }
    }
}

void findMaxRowValue(int matrix[ROWS][COLS], struct MatrixValueInfo *maxValuesRows) {
    int tempdecision;
    for (int j = 0; j < ROWS; j++) {
        int maxValue = matrix[j][0];
        maxValuesRows[j].row = j;
        maxValuesRows[j].col = 0;
        maxValuesRows[j].value = maxValue;

        for (int i = 1; i < COLS; i++) {
            int temp = matrix[j][i];
            if (matrix[j][i] > maxValue) {
                maxValue = matrix[j][i];
                maxValuesRows[j].row = j;
                maxValuesRows[j].col = i;
                maxValuesRows[j].value = maxValue;
            }
            else if (temp == maxValue){
                printf("overvrite (%d row:%d col:%d) with new max value (row:%d col:%d)?\n",maxValue,maxValuesRows[j].row+1,maxValuesRows[j].col+1,j+1,i+1);
                printf("1->Yes\n2->No\n");
                scanf("\n%d",&tempdecision);
                if(tempdecision==1){
                    maxValue = matrix[j][i];
                    maxValuesRows[j].row = j;
                    maxValuesRows[j].col = i;
                    maxValuesRows[j].value = maxValue;
                    printf("overvrited, new value:%d, row:%d col:%d\n",maxValue,maxValuesRows[j].row+1,maxValuesRows[j].col+1);
                }
                else{
                    printf("no overwriting curent value:value:%d, row:%d col:%d\n",maxValue,maxValuesRows[j].row+1,maxValuesRows[j].col+1);
                }

            }
        }
    }
}

void findMinRowValue(int matrix[ROWS][COLS], struct MatrixValueInfo *minValues) {           
int tempdecision;
    for (int j = 0; j < ROWS; j++) {
        int minValue = matrix[j][0];
        minValues[j].row = j;
        minValues[j].col = 0;
        minValues[j].value = minValue;

        for (int i = 1; i < COLS; i++) {
            
            if (matrix[j][i] < minValue) {
                minValue = matrix[j][i];
                minValues[j].row = j;
                minValues[j].col = i;
                minValues[j].value = minValue;
            }
            else if (matrix[j][i] == minValue){
                printf("overvrite (%d row:%d col:%d) with new min value (row:%d col:%d)?\n",minValue,minValues[j].row+1,minValues[j].col+1,j+1,i+1);
                printf("1->Yes\n2->No\n");
                scanf("\n%d",&tempdecision);
                if(tempdecision==1){
                    minValue = matrix[j][i];
                    minValues[j].row = j;
                    minValues[j].col = i;
                    minValues[j].value = minValue;
                    printf("overvrited, new value:%d, row:%d col:%d\n",minValue,minValues[j].row+1,minValues[j].col+1);
                }
                else{
                    printf("no overwriting curent value:value:%d, row:%d col:%d\n",minValue,minValues[j].row+1,minValues[j].col+1);
                }

            }
        }
    }
}

int main() {
    
    // int matrix[ROWS][COLS] = { //change value manualy
    //     //D2
    //     {1,3,3,-2},
    //     {0,-1,2,1},//D1
    //     {-2,2,0,0}
    // };

    int matrix[ROWS][COLS] = { 
        //D2
        {3,2},
        {-1,1},//D1
       
    };
    struct MatrixValueInfo maxValuesCols[COLS];
    struct MatrixValueInfo maxValuesRows[ROWS];
    struct MatrixValueInfo minValuesCols[COLS];
    struct MatrixValueInfo minValuesRows[ROWS];

    struct MinResult Minfinal;
    struct MaxResult Maxfinal;

    int mode;

    //Display matrix in terminal
    printf("Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
         printf("|");
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("|\n");
    }

    printf("Mode select:\n1->D1(kol)minimizes D2(Row)maximizes\n2->D1(kol)maximizes D2(Row)minimizes\n");
    scanf("%d",&mode);
    printf("mode: %d\n",mode);
    if(mode==1)
    {
        findMaxRowValue(matrix, maxValuesRows);
        printf("Max value in every Row:\n");
        for (int j = 0; j < ROWS; j++) {
            printf("Row %d, Column %d, Value %d\n", maxValuesRows[j].row + 1, maxValuesRows[j].col + 1, maxValuesRows[j].value);
        }
        findMinColValue(matrix, minValuesCols);
        printf("Lowest value in every column:\n");
        for (int j = 0; j < COLS; j++) {
            printf("Row %d, Column %d, Value %d\n", minValuesCols[j].row + 1, minValuesCols[j].col + 1, minValuesCols[j].value);
        }
        Minfinal=findLowest(maxValuesRows, ROWS);
        Maxfinal=findMax(minValuesCols, COLS);
        printf("----------------Final---------------------------\n");
        Balance(Minfinal, Maxfinal);
        printf("Row %d, Column %d, Value (safety level) %d\n", Minfinal.row + 1, Minfinal.col + 1, Minfinal.value);
        printf("Row %d, Column %d, Value (safety level) %d\n", Maxfinal.row + 1, Maxfinal.col + 1, Maxfinal.value);
        //printf("strategia bezpieczna dla D1: Row %d, Value %d\n", Minfinal.row + 1, Minfinal.value);
        //printf("strategia bezpieczna dla D2: Column %d, Value %d\n",  Maxfinal.col + 1, Maxfinal.value);

    }
    else if(mode==2)
    {
        findMinRowValue(matrix, minValuesRows);
        printf("Lowest vaue in every Row:\n");
        for (int j = 0; j < ROWS; j++) {
            printf("Row %d, Column %d, Value %d\n", minValuesRows[j].row + 1, minValuesRows[j].col + 1, minValuesRows[j].value);
        }
        findMaxColValue(matrix, maxValuesCols);
        printf("Max values in every column:\n");
        for (int j = 0; j < COLS; j++) {
            printf("Row %d, Column %d, Value %d\n", maxValuesCols[j].row + 1, maxValuesCols[j].col + 1, maxValuesCols[j].value);
        }
        Minfinal=findLowest(maxValuesCols, COLS);
        Maxfinal=findMax(minValuesRows, ROWS);
        printf("----------------finalny wynik---------------------------\n");
        Balance(Minfinal, Maxfinal);
        printf("Row %d, Column %d, Value (safety level) %d\n", Minfinal.row + 1, Minfinal.col + 1, Minfinal.value);
        printf("Row %d, Column %d, Value (safety level) %d\n", Maxfinal.row + 1, Maxfinal.col + 1, Maxfinal.value);
        //printf("safe option for D1: Row %d, Value %d\n", Minfinal.row + 1, Minfinal.value);
        //printf("safe option for: Column %d, Value %d\n",  Maxfinal.col + 1, Maxfinal.value);
    }
    // findMinColValue(matrix, minValuesCols);
    // findMinRowValue(matrix, minValuesRows);
    //findMaxRowValue(matrix, maxValuesRows);

   // findLowest(maxValuesCols, COLS);
    //findLowest(maxValuesRows, ROWS);
   // findMax(maxValuesCols, COLS);

    // printf("Max values in every column:\n");
    // for (int j = 0; j < COLS; j++) {
    //     printf("Column %d, Row %d, Value %d\n", maxValuesCols[j].col + 1, maxValuesCols[j].row + 1, maxValuesCols[j].value);
    // }
    //  printf("Największe wartości w każdym Rowu:\n");
    // for (int j = 0; j < ROWS; j++) {
    //     printf("Row %d, Column %d, Value %d\n", maxValuesRows[j].col + 1, maxValuesRows[j].row + 1, maxValuesRows[j].value);
    // }
    //    printf("Lowest value in every column:\n");
    // for (int j = 0; j < COLS; j++) {
    //     printf("Column %d, Row %d, Value %d\n", minValuesCols[j].col + 1, minValuesCols[j].row + 1, minValuesCols[j].value);
    // }
    //        printf("Lowest vaue in every Rowu:\n");
    // for (int j = 0; j < COLS; j++) {
    //     printf("Column %d, Row %d, Value %d\n", minValuesRows[j].col + 1, minValuesRows[j].row + 1, minValuesRows[j].value);
    // }


    return 0;
}
