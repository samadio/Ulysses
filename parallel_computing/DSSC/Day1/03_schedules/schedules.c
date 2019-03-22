#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/time.h>


void print_usage(int * a, int N, int nthreads) {

  int tid, i;

  for(tid = 0; tid < nthreads; ++tid) {
    printf("%d: ", tid);
    for( i = 0; i < N; ++i) {
      if(a[i] == tid) {
	printf("*");
      } else {
	printf(" ");
      }
    }
    printf("\n");
  }
}


double seconds()
/* Return elapsed time on second from January 1, 1970 */
{
    struct timeval tmp;
    double sec;
    gettimeofday( &tmp, (struct timezone *)0 );
    sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
    return sec;
}


int main() {
  
  double t1, t2;

  t1 = seconds();
  // TODO
  t2 = seconds();

  fprintf( stdout, "\n\nTime of execution %.3g seconds", t2 - t1 );

  return 0;
}
