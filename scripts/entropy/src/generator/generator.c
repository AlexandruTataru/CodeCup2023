/*

  Made by Marcel Vlastuin, marcel@codecup.nl.
  Generator for the game Entropy (CodeCup 2023).
  For more information: www.codecup.org.
  This program is part of the Caia project for the CodeCup 2023.
  The code is "as it is".

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SRAND() gettimeofday(&tp_rand, NULL); es_rand=(long)tp_rand.tv_sec; em_rand=(long)tp_rand.tv_usec; srand(1000000*es_rand+em_rand)
#define RAND(x) (int)((float)(x)*(rand()/(RAND_MAX+1.0)))

static struct timeval tp_rand;
static long es_rand, em_rand;

#define N ( 7 )
#define M ( N * N )

int main ( void )
{
  int i, j, w, g;
  int lijstkleur[M];
  FILE * uit;
  SRAND ( );
  for ( i = 0; i < N; ++i )
  {
    for ( j = 0; j < N; ++j )
    {
      lijstkleur[i * N + j] = i + 1;
    }
  }
  for ( i = M; i > 1; --i )
  {
    g = RAND ( i );
    w = lijstkleur[g];
    lijstkleur[g] = lijstkleur[i - 1];
    lijstkleur[i - 1] = w;
  }
  uit = fopen ( "colour.txt", "wt" );
  for ( i = 0; i < M; ++i )
  {
    fprintf ( uit, "%d\n", lijstkleur[i] );
  }
  return 0;
}
