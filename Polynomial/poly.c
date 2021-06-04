#include "poly.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/**
 * @brief initialize the polynomial struct to have a variable
 * @param poly polynomial
 * @param variable variable to be assigned
 */
void initialize_polynomial(struct Polynomial *poly, char variable){
    poly->variable = variable;
    
    //set all coefficients to 0
    for (int i =0; i < MAXTERMS; i++) {
        poly->coefficients[i] = 0;
    }
}

/**
 * @brief read in polynomial's coefficients
 * @param destination polynomial to be saved to
 * @param input coefficients of polynomial
 * @return true if successful
 */
bool read_polynomial(struct Polynomial *poly, char characterArray[]){
    //erase previous values
    for (int i =0; i < MAXTERMS; i++) {
        poly->coefficients[i] = 0;
    }
    // index of currently reading
    int index = 0;
    //find first coefficient
    int zeroCoef = atoi(characterArray);
    //move index if negative
    if (zeroCoef < 0){
        index++;
    }
    
    poly->coefficients[0] = zeroCoef;

    //find next section to read
    while(isdigit(characterArray[index]) && index < strlen(characterArray)){
//            printf("1 WHILE CURRENTLY AT: %c WITH INDEX %d\n", characterArray[index], index);
        index++;
    }  


    //breakpoint in case the end is reached
    if(index == strlen(characterArray) - 4){
        return true;
    } else if (index == strlen(characterArray)-1){
        return true;
    }
    
    char var;
    int coef;
    int exp;
    int sign = 1;
    
//    printf("BEOFR @ WHILE, CURRENTLY AT: %c WITH INDEX %d\n", characterArray[index], index);

    //loop until index hits the end of the "string" - format <_#v#>
    while(index < strlen(characterArray)-4){ 
     
        //skip spacing to + or -
        while(characterArray[index] != ' ' && index < strlen(characterArray)){
            index++;
            if (index > strlen(characterArray)-4){
                return true;
            }
        }  
        index++;
        
        //set positive vs negative
        if (characterArray[index] == '+'){
            sign = 1;
        }else{
            sign = -1;
        }

        
        //skip non digits/spacing again
        while(!isdigit(characterArray[index]) && (index <= strlen(characterArray))){
                index++;
        }
        
        //create "substring"
        char p[strlen(characterArray) - index];

        memcpy(p, &characterArray[index], strlen(characterArray)-index);
//        int c = 0;
//        while (c < sizeof(characterArray)){
//            p[c] = characterArray[index+c-1];
//            //haha c++
//            c++;
//            printf("COPYING: %c",p[c]);
//        }
//        p[c] = '\0';
//        for (int i = 0; i < strlen(p); i++){
//            printf("COPIED: %c", p[i]);
//        }
            
        sscanf(p, "%d%c%d", &coef, &var, &exp);
//        printf("VARIABLE: %d", coef);

        if(exp > 0 && exp < MAXTERMS && var == poly->variable){
            poly -> coefficients[exp] = (coef * sign);
            index++;
            if (index > strlen(characterArray)-4){
                return true;
            }

        } else if (exp > 0 && exp < MAXTERMS){
            //weird reading of sscanf
            index++;
        } else {
            return false;
        }
    
    } 
    return true;
}

/**
 * @brief write out the polynomial
 * @param polynomial polynomial to be written
 */
void write_polynomial(struct Polynomial *poly){
    int zeroCount = 0;
    // loop through each polynomial
    for(int i = 0; i < MAXTERMS; i++){
        //only print if coefficient is not 0
        if(poly->coefficients[i] != 0){
            int coef =  poly->coefficients[i];
            if (coef == 0){
                zeroCount++;
            }

            //print first coefficient with no x variable
            if (i == 0) {
                if (coef < 0){
                    printf("-");
                    printf("%d", (coef * -1)); 
                } else {
                    printf("%d", coef);
                }
            } else {
                if (coef < 0){
                    printf(" - ");
                    printf("%d", (coef * -1)); 
                } else {
                    printf(" + ");
                    printf("%d", coef);
                }
            }
            
            if(i != 0){
                printf("%c%d", poly->variable, i);
            } 
        } else if (i == 0){
            printf("%d", poly->coefficients[0]);
        }
    }
    if (zeroCount == MAXTERMS){
        printf("%d", 0);
    }
}


/**
 * @brief sum up the polynomials
 * @param p1 result
 * @param p2 first poly to add
 * @param p3 second poly to add
 * @return true if successful sum
 */
bool sum_polynomial(struct Polynomial *p1, struct Polynomial *p2,struct Polynomial *p3){
    //check compatible variables
    if(p2->variable == p3->variable ){
        //set result variable
        p1->variable = p2->variable;
        //add all coefficients
        for(int i = 0; i < MAXTERMS; i++){
            p1->coefficients[i] = p2->coefficients[i] + p3->coefficients[i];
        } 
    }else{
        return false;
    }
    return true;
}




