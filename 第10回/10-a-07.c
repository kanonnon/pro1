#include <stdio.h>

double my_average(double);

// 引数としてdouble型変数を１つ受け取り、これまでに引数として与えられた数の平均値を返す
double my_average(double x)
{
    static double sum = 0, count = 0;
    sum += x;
    count++;
    return sum / count;
}

int main()
{
    printf("%f\n", my_average(3.3));
    printf("%f\n", my_average(4.4));
    printf("%f\n", my_average(5.5));
    printf("%f\n", my_average(6.6));
    return 0;
}