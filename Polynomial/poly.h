#ifndef POLY_H
#define POLY_H

#include <stdbool.h>

#define MAXDEGREE 19
#define MAXTERMS (MAXDEGREE + 1)

struct Polynomial{
    int coefficients[MAXTERMS];
    char variable;
};

void initialize_polynomial(struct Polynomial *polynomial, char variable);
bool read_polynomial(struct Polynomial *poly, char characterArray[]);
void write_polynomial(struct Polynomial *poly);
bool sum_polynomial(struct Polynomial *p1, struct Polynomial *p2, struct Polynomial *p3);


#endif // POLY_H
