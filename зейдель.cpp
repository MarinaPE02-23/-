#include <stdio.h>
#include <math.h>

int main()
{
    float a[4][4] = {
        {19, -4, -9, -1},
        {-2, 20, -2, -7},
        {6, -5, -25, 9},
        {0, -3, -9, 12}
    };
    float d[4] = {100, -5, 34, 69};
    float x[4] = {0};
    float b[4][4] = {0};
    float g[4] = {0};
    float x1[4] = {0};
    int i, j;
    int k = 0;
    int y = 0;
    float z;
    float xk[4] = {0};
    float e;

    printf("Matrix A of coefficients:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%.4f   ", a[i][j]);
        printf("\n");
    }
    printf("\n Vector B coefficients:\n");
    for (i = 0; i < 4; i++)
        printf("%.4f  ", d[i]);
    printf("\n\n");
    printf("Input the error:");
    scanf("%f", &e);
    printf("\t%.5f\n\n", e);

    for (j = 0; j < 4; j++)
    {
        g[j] = d[j];
        x[j] = g[j];
        x1[j] = x[j];
        for (i = 0; i < 4; i++)
        {
            if (i == j)
                b[j][i] = 1 - a[j][i];
            else
                b[j][i] = -a[j][i];
        }
    }

    printf("Transformed matrix:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%.4f   ", b[i][j]);
        printf("\n");
    }
    printf("\n");

    do
    {
        y = 0;
        k++;
        printf("Number of the iteration %d\t\n", k);
        for (j = 0; j < 4; j++)
        {
            xk[j] = g[j];
            for (i = 0; i < 4; i++)
            {
                xk[j] += b[j][i] * x1[i];
            }
        }

        for (j = 0; j < 4; j++)
        {
            z = fabs(xk[j] - x[j]);
            printf("x[%d]: %.4f, xk[%d]: %.4f\n", j, x[j], j, xk[j]);
            printf("|x[%d]-xk[%d]|=%.4f", j, j, z);
            x[j] = xk[j];
            if (z < e)
            {
                y++;
            }
            printf("\n");
        }
        printf("\n");
    } while (y < 4);

    printf("Number of iterations :\t%d\n\n", k);

    printf("Result with error %.5f:\n", e);
    for (i = 0; i < 4; i++)
    {
        printf("\n x[%d]=%.4f ", i, x[i]);
    }

    return 0;
}
