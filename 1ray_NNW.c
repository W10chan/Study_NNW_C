#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define L 1 /* matAの行数 */
#define M 2 /* matAの列数・matBの行数 */
#define N 3 /* matBの列数 */

int main(void) {


/* 入力 */
double X[L][M] = {
    {1.0, 0.5},
};

/* 重み */
double W[M][N] = {
    {0.1, 0.3, 0.5},
    {0.2, 0.4, 0.6},
};

/* バイアス */
double B[L][N] = {
    {0.1, 0.2, 0.3},
};

 /* 重み付き和の結果を格納 */
double matC[L][N];

/* 内積を求めるためのベクトル */
double vecX[M];
double vecW[M];

/* 内積計算結果格納用 */
double A1 = 0.0;

int i, j, k;
//L=1 N=3 M=2
 /* 行列全体の成分を求める */
for (i = 0; i < L; i++) {

/* １行分の成分を求める */
    for (j = 0; j < N; j++) {

/* 内積を求めるのに必要なベクトルを用意 */
        for (k = 0; k < M; k++) {

    /* 入力のi(1)行目の成分だけのベクトルを用意 */
    vecX[k] = X[i][k];

    /* 重みのj列目の成分だけのベクトルを用意 */
    vecW[k] = W[k][j];

}

/* 内積を計算 */
            A1 = 0.0;
            for (k = 0; k < M; k++) {
/* ２つのベクトルの同じ位置の成分を
 掛け合わせたものを足し合わせていく */
                A1 += vecX[k] * vecW[k];

}
/* 内積をmatCの成分として格納 */
            matC[i][j] =  A1 + B[i][j];

}
}

/* matAとmatBの積を表示 */
    for (i = 0; i < L; i++) {
        for (j = 0; j < N; j++) {
            printf("%lf,", matC[i][j]);
        }
        printf("\n");
    }

    return 0;
}
