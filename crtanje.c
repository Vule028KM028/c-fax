//
//  main.c
//  C Skola
//
//  Created by Vukasin Lazarevic on 29.10.23..
//

/*
3. (7p) Nacrtati sledeću figuru za unetu vrednost n.
Primer za n = 5: Primer za n = 6:

....^.... .....^.....
.../*\... ..../*\....
../***\.. .../***\...
./*****\. ../*****\..
---***--- ./*******\.
..|***|.. ----***----
..|***|.. ...|***|...
..|***|.. ...|***|...
..-----.. ...|***|...
...|***|...
...-----...
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int n = 0;
  printf("Unesi prirodan broj: ");
  scanf("%d", & n);

  for (int i = 1; i <= (n * 2) - 1; i++) {
    if (i == n) {
      printf("^");
      continue;
    }
    printf(".");
  }

  printf("\n");

  for (int i = 1; i <= n - 2; i++) {

    for (int j = 1; j <= (n * 2) - 1; j++) {
      //
      if (i + j == n) {
        printf("/");
      } else if (j - i == n) {
        printf("\\");
      } else if ((i + j) > n && (j - i) < n) {
        printf("*");
      } else {
        printf(".");
      }
    }

    printf("\n");
  }

  for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= (n * 2) - 1; j++) {

      if (i == 1) {
        if (n % 2 == 0) {

          if (j <= n / 2 + 1) {
            printf("-");
          } else if (j >= (n + 2) && j < n * 2) {
            printf("-");
          } else {
            printf("*");
          }

        } else {
          int sredina = (int) ceil((double) n / 2);

          if (j <= sredina) {
            printf("-");
          } else if (j >= ((n * 2) - sredina) && j < n * 2) {
            printf("-");
          } else {
            printf("*");
          }

        }

      } else if (i != 1 && i != n) {
        int sredina;

        if (n % 2 != 0) {
          sredina = (int)(n / 2);
        } else {
          sredina = (n / 2) - 1;
        }

        if (j == (n - sredina) || j == (n + sredina)) {
          printf("|");
        } else if (j > (n - sredina) && j < (n + sredina)) {
          printf("*");
        } else {
          printf(".");
        }

      } else {
        if (j <= n / 2 || j >= ((n * 2) - n / 2)) {
          printf(".");
        } else {
          printf("-");
        }
      }
    }

    printf("\n");
  }

  return 0;
}
