/**
 * NOTE: For all functions in this file feel free to use
 * any of the single bit functions in logic.h.
 */
#include "logic32.h"
#include "logic.h"



/**
 * Logical 32bit And operation. (Points 5)
 * 
 * INPUTS:
 *   char *a => input a.
 *   char *b => input b.
 *   char *y => output y.
 *
 * All characters are either '1' or '0'. The bits of y are set
 * to the logical and of a and b.
 */
void logic_AND32(char *a, char *b, char *y) {
    for (int i = 32; i >= 0 ; i--){
        y[i]=logic_AND(a[i],b[i]);
    }
}

/**
 * Logical 32bit Or operation. (Points 5)
 * 
 * INPUTS:
 *   char *a => input a.
 *   char *b => input b.
 *   char *y => output y.
 *
 * All characters are either '1' or '0'. The bits of y are set
 * to the logical or of a and b.
 */
void logic_OR32(char *a, char *b, char *y) {
    for (int i = 32; i >=0; i--){
        y[i]=logic_OR(a[i], b[i]);
    }
}

/**
 * Logical 32bit Not operation. (Points 5)
 * 
 * INPUTS:
 *   char *a => input a.
 *   char *y => output y.
 *
 * All characters are either '1' or '0'. The bits of y are set
 * to the logical not of a.
 */
void logic_NOT32(char *a, char *y) {
    for (int i = 32; i>=0; i--){
        y[i]=logic_NOT(a[i]);
    }
}

/**
 * Logical 32bit Add operation. (Points 5)
 * 
 * INPUTS:
 *   char *a => input a.
 *   char *b => input b.
 *   char *s => sum of a and b.
 *
 * All characters are either '1' or '0'. The bits of s are set
 * to the sum of a and b.
 * 
 * NOTE: Use the function logic_FULL_ADDR to implement this.
 */
void logic_ADD32(char *a, char *b, char *s) {
    char cout = '0'; //used for carry
    char cin = '0'; //base case first carry input
    char x; //used to sum
    for (int i = 32; i>=0; i--){
        logic_FULL_ADDR(cin,a[i],b[i],&cout, &x); //call full adder;
        s[i]=x; //s[i] = sum
        cin = cout; //make carry equal to cin
    }
}

/**
 * Logical 32bit Subtract operation. (Points 5)
 * 
 * INPUTS:
 *   char *a => input a.
 *   char *b => input b.
 *   char *s => sum of a and b.
 *
 * All characters are either '1' or '0'. The bits of s are set
 * to the subtraction of a and b (a - b).
 * 
 * NOTE: Use the function logic_FULL_ADDR and logic_NOT to
 * implement this.
 */
void logic_SUB32(char *a, char *b, char *s) { // a + (-b)
    //flip bits of b
    for (int i=32; i >=0; i--){
        b[i]=logic_NOT(b[i]);
    }
    //add one to b
    char one[33]="00000000000000000000000000000001\0"; //1 in 32 bit notation
    logic_ADD32(b, one, b); //b = b+1
    //a + (-b)
    logic_ADD32(a,b,s);
}

/**
 * Logical 32bit Set Less Than. (Points 5)
 * 
 * INPUTS:
 *   char *a => input a.
 *   char *b => input b.
 *
 * All characters are either '1' or '0'. The return is '1' if
 * a is less than b.
 * 
 * NOTE: Use the function logic_SUB32 to implement this.
 */
char logic_SLT32(char *a, char *b) {
    char s[33];
    logic_SUB32(a,b,s); //s = a - b
    if(s[0]=='1'){ //if most significant bit is 1, then it is negative (therefore a < b)
        return '1';
    } 
    return '0'; //if subtraction is positive, then a > b
}

/**
 * Logical 32bit Extend. (Points 5)
 * 
 * INPUTS:
 *   char e => extend character.
 *   int start => bit to start extending.
 *   char *a => input a.
 *   char *y => output extended.
 *
 * All characters are either '1' or '0'. The output y is set
 * to extend until the start offset. Then the output y is set
 * to the input a for the rest of the output.
 * 
 * NOTE: Use the function logic_SUB32 to implement this.
 */
void logic_EXTEND(char e, int start, char *a, char *y) {
    int s=(-start)+33; //make start equal to element position
    //copy a into output y;
    for (int i=0; i<=33; i++){
        y[i]=a[i];
    }
    for (int i=0; i<s; i++){ //end of it to the start of the bit to be extended
        y[i]=e; //make bit equal to extend character
    }
}

/**
 * Logical 32bit 2:1 Mux. (Points 5)
 * 
 * INPUTS:
 *   char s => selector character.
 *   char *d_1 => input 32bit word.
 *   char *d_0 => input 32bit word.
 *   char *y => output.
 *
 * All characters are either '1' or '0'. The output y is set
 * to the return of logic_MUX_2_1() given the selector.
 * 
 * NOTE: Use the function logic_MUX_2_1 to implement this.
 */
void logic_MUX32_2_1(char s, char *d_1, char *d_0, char *y) {
    for (int i=32; i>=0; i--){ //iterate through 32 bit words
        y[i]=logic_MUX_2_1(s, d_1[i], d_0[i]); //input each bit of d_1 and d_1 into multiplexer and set to output y
    }
}

/**
 * Logical 32bit 2:1 Mux. (Points 5)
 * 
 * INPUTS:
 *   char *s => selector character.
 *   char *d_3 => input 32bit word.
 *   char *d_2 => input 32bit word.
 *   char *d_1 => input 32bit word.
 *   char *d_0 => input 32bit word.
 *   char *y => output.
 *
 * All characters are either '1' or '0'. The output y is set
 * to the return of logic_MUX_4_1() given the selector.
 * 
 * NOTE: Use the function logic_MUX_4_1 to implement this.
 */
void logic_MUX32_4_1(char *s, char *d_3, char *d_2, char *d_1, char *d_0, char *y) {
    for (int i=32; i>=0; i--){
        y[i]=logic_MUX_4_1(s, d_3[i], d_2[i], d_1[i], d_0[i]);
    }
}

/**
 * Logical 32bit Arithmetic Logic Unit (ALU). (Points 15)
 * 
 * INPUTS:
 *   char *f => function selector.
 *   char *a => input 32bit word.
 *   char *b => input 32bit word.
 *   char *y => output.
 *
 * All characters are either '1' or '0'. The output y is set
 * to the correct function as defined by the table in the
 * slides. Also review the logic diagram to help you hook
 * up all the logic functions.
 */
void logic_ALU(char *f, char *a, char *b, char *y) {
    char slt[33];
    char sum[33];
    char nb[33];
    char bnb[33];
    char aband[33];
    char abor[33];
    char f_o[2];
    char c_i = f[0];
    slt[33] = sum[33] = nb[33] = bnb[33] = aband[33] = abor[33] = '\0';
    f_o[0] = f[1];
    f_o[1] = f[2];
    logic_NOT32(b, nb);
    logic_MUX32_2_1(f[0], nb, b, bnb);
    logic_AND32(a, bnb, aband);
    logic_OR32(a, bnb, abor);
    for(int i = 0; i < 32; i++) {
        logic_FULL_ADDR(c_i, a[31-i], bnb[31-i], &c_i, &(sum[31-i]));
    }
    logic_EXTEND('0', 1, sum, slt);
    logic_MUX32_4_1(
        f_o,
        slt,
        sum,
        abor,
        aband,
        y
    );
}