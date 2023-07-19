#include <stdio.h>

#include "util.h"
point linear_approximation(float *x, float *y, int siz) {
    float a;
    float b;
    float sum_xy = 0;
    float sum_x = 0;
    float sum_y = 0;
    float sum_x2 = 0;
    for (int i = 0; i < siz; i++) {
        sum_xy += x[i] * y[i];
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i] * x[i];
    }
    a = (siz * sum_xy - sum_x * sum_y) / (siz * sum_x2 - sum_x * sum_x);
    b = (sum_x2 * sum_y - sum_xy * sum_x) / (siz * sum_x2 - sum_x * sum_x);
    point ans = {a, b};
    return ans;
}


// 決定係数
#include <stdio.h>

#include "util.h"
float coefficient_determination(float *x, float *y, int siz, point result) {
    float ans_1;
    float ans_2;
    float a = result.a;
    float b = result.b;
    for (int i = 0; i < siz; i++) {
        ans_1 += (y[i] - a * x[i] - b) * (y[i] - a * x[i] - b);
        ans_2 += (y[i] - avg(y, siz)) * (y[i] - avg(y, siz));
    }
    return 1 - ans_1 / ans_2;
}

// 決定係数
#include <stdio.h>

#include "util.h"
float coefficient_determination(float *x, float *y, int siz,
                                point_multi result) {
    float ans_1;
    float ans_2;
    float a0 = result.a0;
    float a1 = result.a1;
    float a2 = result.a2;
    for (int i = 0; i < siz; i++) {
        ans_1 += (y[i] - a0 - a1 * x[i] - a2 * x[i] * x[i]) *
                 (y[i] - a0 - a1 * x[i] - a2 * x[i] * x[i]);
        ans_2 += (y[i] - avg(y, siz)) * (y[i] - avg(y, siz));
    }
    return 1 - ans_1 / ans_2;
}
