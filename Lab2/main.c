#include <stdio.h>
#include <math.h>
int fact(int n)
{
  if (n<0)
  {
    return 0;
  }
  if (n==0)
  {
    return n = 1;
  }
  return n * fact(n - 1);
}
double calc(const double m, double x, int n)
{
  double exp = 0;
  double res = m;
  for (int i = 1; i < n; i++)
  {
    res *= (m + i);
  }
  res *= (m + n - 1);
  exp = res * pow(x, n) / fact(n);
  exp += 1;
  
  return exp;
}
int main()
{
  double a, b, exp = 0, x, m;
  const double h = 0.05;
  double d = 0.001;
  int n;
    printf("Enter interval\n");
  scanf_s("%lf %lf", &a, &b);//Ввести інтервал від 0.1--0.5
  printf("Enter n, x, m:");
  scanf_s("%d %lf %lf", &n, &x, &m);//Ввести змінні n,x,m.
  printf("interval = (%.2lf %.2lf), x = %.2lf, exp = %.2lf", a, b, x, exp);
  if (x < 0.1 && x > 0.5)
  {
    printf("Enter x in range of (0.1, 0.5)");
    return 1;

  }
  int i = 0;
  for (x = a; x <= b; x += h)
  {
    double exp_prev = 0;
    exp_prev = calc(m, x, n - 1);
    exp = calc(m, x, n);
    n++;
    printf("%d : x = %lf : exp = %lf\n ", i, x, exp);
    i++;
    if (fabs(exp - exp_prev) < d) {
      break;
    }
  }
}
