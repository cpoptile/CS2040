// main driver for polynomial lab

#include "poly.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

// 20 terms, maximum 10 characters for a coefficient, maximum term size: 13 chars
//   Adding spaces gives about 300 characters for the input; set to 500 just 
//   for extra space.
const int MAXLEN = 500;

void report_sum_of(struct Polynomial *a, struct Polynomial *b);
void test_same_variable();

int main() {
  test_same_variable();

  struct Polynomial a;
  initialize_polynomial(&a, 'x');
  printf("Enter a polynomial over x, q to terminate:\n");
  char buf[MAXLEN];
  fgets(buf, MAXLEN, stdin);

  while ( tolower(buf[0]) != 'q' ) {
    if ( !read_polynomial(&a, buf) )
      printf("Bad polynomial: '%s'\n", buf);
    else {
      struct Polynomial b;
      initialize_polynomial(&b, 'x');
      printf("Enter a second polynomial over x:\n");
      fgets(buf, MAXLEN, stdin);
      if ( !read_polynomial(&b, buf) )
        printf("Bad second polynomial: '%s'\n", buf);
      else {
        report_sum_of(&a, &b);
        printf("\n");
      }
    }
    printf("Enter a polynomial over x, q to terminate:\n");
    fgets(buf, MAXLEN, stdin);
  }
  printf("Bye!\n");
  return 0;
}

void report_sum_of(struct Polynomial *a, struct Polynomial *b)
{
  printf("  ");
  write_polynomial(a);
  printf("\n+ ");
  write_polynomial(b);
  printf("\n--------------------------------------------------\n");
  struct Polynomial result;
  sum_polynomial(&result, a, b);
  write_polynomial(&result);
  printf("\n");
}

void test_same_variable()
{
  // simple tests of the polynomial API - features that are harder to test in 
  //   via user inputs
  struct Polynomial u, v, result;
  initialize_polynomial(&u, 'u');
  assert(read_polynomial(&u, "5 + 18u9"));
  initialize_polynomial(&v, 'v');
  assert(read_polynomial(&v, "9 - 12v3"));
  assert(!sum_polynomial(&result, &u, &v));
}