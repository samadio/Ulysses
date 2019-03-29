#include<stdio.h>
#include<stdlib.h>
#include<omp.h>


double f( double x){
    return 1.0/(1.0+x*x);
}

int main(){
  size_t N=1000000000;
  double h=1.0/(N);
  double pi=0.0;
  int nthr= omp_get_num_threads();
  double tstart=omp_get_wtime();
  
  printf("Number of threads: %d",nthr);
  #pragma omp parallel //reduction(+:pi)
  {
    double local=0;
    int i;
    #pragma omp for schedule(static)
    for( i= 0 ; i <= N-1; i++)
    {
      local+=f((i*h)+h/2);    
    }
    local=local*4*h;
    #pragma omp atomic
    pi+=local;

    //#pragma omp critical
    //pi+=local;
  }
    double duration =omp_get_wtime()-tstart;
    printf("%lf in %lf sec\n", pi,duration);

    return 0;  
}
