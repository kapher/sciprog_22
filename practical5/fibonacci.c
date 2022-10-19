#include<stdio.h>
#include<stdlib.h>

//Input arguments: f(n-1) and f(n-2)
//On exit, they have values of f(n) and f(n-1)
void fibonacci(long *a, long *b);

int main()
{

  int n,i;
  long f1=1, f0=0;

  printf("Enter a positive integer n\n");
  scanf("%d", &n);
  
  if(n<1){
     printf("The number is not positive\n");
     exit(1);
  }

  printf("The fibonacci sequence is:\n");
  printf("%ld, %ld, ", f0, f1);

  for(i=2; i<=n; i++){
    fibonacci(&f1, &f0);
    printf("%ld, ", f1);
   
    if(((i+1)%10) == 0) printf("\n");
  }
  return 0;
}

void fibonacci(long *a, long *b){

  long next;

  //*a = f(n-1), *b=f(n-2) next=f(n)
  next=*a+*b;

  //*a=f(n), *b=f(n-1)
  *b=*a;
  *a=next;

}  


