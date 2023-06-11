#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define L 1 /* matAの行数 */
#define M 2 /* matAの列数・matBの行数 */
#define N 3 /* matBの列数 */

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double identity(double x){
    return x;
}

int main(void) {
    printf("重み積和,活性化関数後(三層目のみ恒等関数)\n");
    printf("第1層目\n");

    /* 入力 */
    double X1[L][M] = {
        {1.0, 0.5},
    };

    /* 重み-1層目 */
    double W1[M][N] = {
        {0.1, 0.3, 0.5},
        {0.2, 0.4, 0.6},
    };

    /* バイアス1 */
    double B1[L][N] = {
        {0.1, 0.2, 0.3},
    };

    /* 重み付き和の結果を格納 */
    double A1[L][N];
    double vecX[M];
    double vecW[M];
    double A = 0.0;

    int i, j, k;

    /* 行列全体の成分を求める */
    for (i = 0; i < L; i++) {
        /* １行分の成分を求める */
        for (j = 0; j < N; j++) {
            /* 内積を求めるのに必要なベクトルを用意 */
            for (k = 0; k < M; k++) {
                /* 入力のi(1)行目の成分だけのベクトルを用意 */
                vecX[k] = X1[i][k];
                /* 重みのj列目の成分だけのベクトルを用意 */
                vecW[k] = W1[k][j];
            }
            /* 内積を計算 */
            A = 0.0;
            for (k = 0; k < M; k++) {
                /* ２つのベクトルの同じ位置の成分を掛け合わせたものを足し合わせていく */
                A += vecX[k] * vecW[k];
            }
            /* 内積をmatCの成分として格納 */
            A1[i][j] = A + B1[i][j];
        }
    }

    /* 第1層目の活性化関数：シグモイド関数 */
    double Z1[L][N];
    for (i = 0; i < L; i++) {
        for (j = 0; j < N; j++) {
            printf("%lf, ", A1[i][j]);

            double x = A1[i][j];
            Z1[i][j] = sigmoid(x);
            printf("%lf\n", Z1[i][j]);
        }
        printf("\n");
    }

    /* 第2層目 */
    /* 重み-2層目 */
    printf("第2層目\n");
    double W2[N][M] = {
        {0.1, 0.4},
        {0.2, 0.5},
        {0.3, 0.6},
    };

    /* バイアス2 */
    double B2[L][2] = {
        {0.1, 0.2},
    };

    /* 重み付き和の結果を格納 */
    double A2[L][2];
    double vecX2[N];
    double vecW2[N];

    /* 行列全体の成分を求める */
    for (i = 0; i < L; i++) {
        /* １行分の成分を求める */
        for (j = 0; j < 2; j++) {
            /* 内積を求めるのに必要なベクトルを用意 */
            for (k = 0; k < N; k++) {
                /* 入力のi(1)行目の成分だけのベクトルを用意 */
                vecX2[k] = Z1[i][k];
                /* 重みのj列目の成分だけのベクトルを用意 */
                vecW2[k] = W2[k][j];
            }
            /* 内積を計算 */
            A = 0.0;
            for (k = 0; k < N; k++) {
                /* ２つのベクトルの同じ位置の成分を掛け合わせたものを足し合わせていく */
                A += vecX2[k] * vecW2[k];
            }
            /* 内積をmatCの成分として格納 */
            A2[i][j] = A + B2[i][j];
        }
    }

    /* 第2層目の活性化関数：シグモイド関数 */
    double Z2[L][2];
    for (i = 0; i < L; i++) {
        for (j = 0; j < 2; j++) {
            printf("%lf, ", A2[i][j]);

            double x = A2[i][j];
            Z2[i][j] = sigmoid(x);
            printf("%lf\n", Z2[i][j]);
        }
        printf("\n");
    }

    /* 第3層目 */
    /* 重み-3層目 */
    printf("第3層目\n");
    double W3[2][2] = {
        {0.1, 0.3},
        {0.2, 0.4},
    };

    /* バイアス3 */
    double B3[L][M] = {
        {0.1, 0.2},
    };

    /* 重み付き和の結果を格納 */
    double A3[L][M];
    double vecX3[M];
    double vecW3[M];

    /* 行列全体の成分を求める */
    for (i = 0; i < L; i++) {
        /* １行分の成分を求める */
        for (j = 0; j < M; j++) {
            /* 内積を求めるのに必要なベクトルを用意 */
            for (k = 0; k < M; k++) {
                /* 入力のi(1)行目の成分だけのベクトルを用意 */
                vecX3[k] = Z2[i][k];
                /* 重みのj列目の成分だけのベクトルを用意 */
                vecW3[k] = W3[k][j];
            }
            /* 内積を計算 */
            A = 0.0;
            for (k = 0; k < M; k++) {
                /* ２つのベクトルの同じ位置の成分を掛け合わせたものを足し合わせていく */
                A += vecX3[k] * vecW3[k];
            }
            /* 内積をmatCの成分として格納 */
            A3[i][j] = A + B3[i][j];
        }
    }

    /* 第3層目の活性化関数：恒等関数 */
    double Z3[L][M];
    for (i = 0; i < L; i++) {
        for (j = 0; j < M; j++) {
            printf("%lf, ", A3[i][j]);

            double x = A3[i][j];
            Z3[i][j] = identity(x);
            printf("%lf\n", Z3[i][j]);
        }
        printf("\n");
    }
    return 0;
}
