#include <stdio.h>

#define L 2 /* matAの行数 */
#define M 2 /* matAの列数・matBの行数 */
#define N 2 /* matBの列数 */

int main(void) {

//int matA[2][3]; /* ２行３列の行列 */

/* ２つの行列を用意 */
int matA[L][M] = {
    {1, 2},
    {3, 4},
};
int matB[M][N] = {
    {5, 6},
    {7, 8},
};

 /* matAとmatBの積の結果となる行列 */
int matC[L][N];

/* 内積を求めるためのベクトル */
int vecA[M];
int vecB[M];

/* 内積計算結果格納用 */
int inner_product = 0;

int i, j, k;

 /* 行列全体の成分を求める */
for (i = 0; i < L; i++) {

/* １行分の成分を求める */
    for (j = 0; j < N; j++) {

/* 内積を求めるのに必要なベクトルを用意 */
        for (k = 0; k < M; k++) {

    /* matAのi行目の成分だけのベクトルを用意 */
    vecA[k] = matA[i][k];

    /* matBのj列目の成分だけのベクトルを用意 */
    vecB[k] = matB[k][j];

}

/* 内積を計算 */
            inner_product = 0;
            for (k = 0; k < M; k++) {
/* ２つのベクトルの同じ位置の成分を
 掛け合わせたものを足し合わせていく */
                inner_product += vecA[k] * vecB[k];

}
/* 内積をmatCの成分として格納 */
            matC[i][j] = inner_product;

}
}

/* matAとmatBの積を表示 */
    for (i = 0; i < L; i++) {
        for (j = 0; j < N; j++) {
            printf("%d,", matC[i][j]);
        }
        printf("\n");
    }

    return 0;
}
