#include <stdio.h>

/*
Write by Tahnasib Gafarov. 
https://github.com/thmsbgfrv
*/

//User Can Modifie This Part For Modifie Results like board size and etc
#define LENGTH 8 //board size (LENGTH x LENGTH)
#define printMode 1 //if 1 means print  results  if 0 show just totalnumber of results
int showFirstN = 0; //if less than 1 means calculate all results,


int row[LENGTH];
int lDiag[(LENGTH * 2 - 1)];
int rDiag[(LENGTH * 2 - 1)];
int numberOfExamples = 0;

void print();

int checkColumn(int i);

int checkRow(int i);

void addLDiag(int i, int j);

int checkLDiag(int i, int j);

void addRDiag(int i, int j);

int checkRDiag(int i, int j);

int placeQueens(int i, int j);

void placeSingleQueen(int i, int a);

void removeSingleQueen(int i, int a);

void removeLDiag(int i, int a);

void removeRDiag(int i, int a);

int main() {
    for (int i = 0; i < LENGTH * 2 - 2; ++i) {
        lDiag[i] = 0;
        rDiag[i] = 0;
        if (i < LENGTH) {
            row[i] = -1;
        }
    }
    placeQueens(0, 0);
    if (numberOfExamples < 1) {
        printf("\nThere are no example!");
    } else if (printMode == 0) {
        printf("\nThere ara total %d example:", numberOfExamples);
    }
    return 0;
}

int placeQueens(int i, int j) {

    if (i > (LENGTH - 1)) {
        numberOfExamples++;
        if (showFirstN < 1) {
            if (printMode == 1)
                print();
            return -1;
        }
        showFirstN--;
        if (printMode == 1)
            print();
        if (showFirstN == 0) {
            return -3;
        } else {
            return -1;
        }
    }
    for (int a = j; a < LENGTH; ++a) {
        if (checkRow(i) == 0 && checkColumn(a) == 0 && checkLDiag(i, a) == 0 && checkRDiag(i, a) == 0) {
            placeSingleQueen(i, a);
            int res = placeQueens(i + 1, 0);
            if (res == -1) {
                removeSingleQueen(i, a);
            } else if (res == -3) {
                return -3;
            }
        }
    }
    return -1;
}

void removeSingleQueen(int i, int a) {
    row[i] = -1;
    removeLDiag(i, a);
    removeRDiag(i, a);
}

void removeRDiag(int i, int a) {
    int index = i + a;
    rDiag[index] = 0;
}

void removeLDiag(int i, int a) {
    if (a >= i) {
        int index = ((LENGTH - 1) + i - a);
        lDiag[index] = 0;
    } else if (a < i) {
        int index = ((LENGTH - 1) + (i - a));
        lDiag[index] = 0;
    }
}

void placeSingleQueen(int i, int a) {
    row[i] = a;
    addLDiag(i, a);
    addRDiag(i, a);
}

/*
 * return 1 if there is quenn in that diag
 * */
int checkLDiag(int i, int j) {
    if (j >= i) {
        int index = ((LENGTH - 1) + i - j);
        if (lDiag[index] == 1)
            return 1;
    } else if (j < i) {
        int index = ((LENGTH - 1) + (i - j));
        if (lDiag[index] == 1)
            return 1;
    }
    return 0;
}

void addLDiag(int i, int j) {
    if (j >= i) {
        int index = ((LENGTH - 1) + i - j);
        lDiag[index] = 1;
    } else if (j < i) {
        int index = ((LENGTH - 1) + (i - j));
        lDiag[index] = 1;
    }
}

/*
 * return 1 if there is quenn in that diag
 * */
int checkRDiag(int i, int j) {
    int index = i + j;
    if (rDiag[index] == 1)
        return 1;
    return 0;
}

void addRDiag(int i, int j) {
    int index = i + j;
    rDiag[index] = 1;
}

/*
 * i row
 * @return 1 if there was queen in row else 0 otherwise
 */
int checkRow(int i) {
    if (row[i] > -1) {
        return 1;
    }
    return 0;
}

/*
 * @return 1 if there was queen in column else 0 otherwise
 */
int checkColumn(int i) {

    for (int j = 0; j < LENGTH; j++) {
        if (row[j] == i) {
            return 1;
        }
    }
    return 0;
}

void print() {

    int a = numberOfExamples;
    printf("\n\n\n\n\nEight Queen Example No:%d\n", a);
    for (int k = 0; k < 4 * LENGTH + 1; ++k) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < LENGTH; ++i) {
        printf("|");
        for (int j = 0; j < LENGTH; ++j) {
            if (j == row[i] && row[i] > -1) {
                printf(" v |");
            } else {
                printf("   |");
            }
        }
        printf("\n");
        for (int k = 0; k < 4 * LENGTH + 1; ++k) {
            printf("-");
        }
        printf("\n");
    }
}
