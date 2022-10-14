#include <stdio.h>
#include <math.h>

float degtorad(float degang);
float traprule(int N, float TanArr[N+1]);

int main(void)
{
  int N =12, i;
  float TanArr[N+1], deg, rad;
  // Calculate the values of f(xi) where i =0, ..., 12
  // and xi are in radians (as array elements)
  for(i=0; i <=N; i++)
  {
    deg = i *5.0;
    rad = degtorad(deg);
    TanArr[i] = tan(rad);
    printf("TanArr[%d]=%f (f(x) at x=%d)\n", i , TanArr[i],i);
  }

  float area = traprule(N, TanArr);

  // Approximated result
  printf("\nTrapezoidal result is : %f\n", area);
  // Actual result
  // Integral of tan is ln(2)
  printf("Real result is: %f\n", log(2.0));

  return 0;
}

float degtorad(float theta)
{
  return M_PI * theta /180.;
}

float traprule(int N, float TanArr[N + 1])
{
  int i;
  float b_deg=60.0;
  float area, mult_rad;


  //Sum tan(a)+tan(b)
  area=TanArr[0]+TanArr[N];
  //Calculate the area at pts x1, x2, ..., x11 by multiplying by 2
  //adding them together
  for(i=1; i<N; i++){
    area=area+2*TanArr[i];
  }

  //Multiply partial area by (pi/3)/(2*12)
  //Covert it to radians first
  mult_rad=(M_PI*((b_deg)/(2*N)))/180;
  area = mult_rad*area;
  return area;
}

