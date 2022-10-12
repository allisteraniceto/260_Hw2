#include "logic.h"

/**
 * Logical And of the Inputs
 * 
 * The characters a and b are either '1' or '0'. The return
 * is the character '1' if a and b are both '1' otherwise
 * '0' is returned.
 */
char logic_AND(char a, char b) {
    if (a == b && a == '1') {
        return '1';
    }
    return '0';
}

/**
 * Logical Or of the Inputs
 * 
 * The characters a and b are either '1' or '0'. The return
 * is the character '1' if a or b are '1' otherwise '0' is
 * returned.
 */
char logic_OR(char a, char b) {
    if (a == '1' || b == '1') {
        return '1';
    }
    return '0';
}

/**
 * Logical Not of the Input
 * 
 * The character a is either '1' or '0'. The return is the
 * character '0' if a is '1' otherwise '0' is returned.
 */
char logic_NOT(char a) {
    if (a == '1') {
        return '0';
    }
    return '1';
}

/**
 * Logical Nor of the Inputs (Points 1)
 * 
 * The characters a and b are either '1' or '0'. The return
 * is the logical not of the characters a or b.
 * 
 * NOTE: Use the functions logic_NOT, logic_AND, logic_OR
 * to implement this function.
 */
char logic_NOR(char a, char b) { //if AND is not true (0), then return true
    if (logic_OR(a,b)!='1'){
        return '1';
    }
    return '0';
}

/**
 * Logical Nand of the Inputs (Points 1)
 * 
 * The characters a and b are either '1' or '0'. The return
 * is the logical not of the characters a and b.
 *
 * NOTE: Use the functions logic_NOT, logic_AND, logic_OR
 * to implement this function.
 */
char logic_NAND(char a, char b) {
    if (logic_AND(a,b)!='1'){ //if AND is not true (0), then return true
        return '1';
    }
    return '0';
}

/**
 * Logical Xor of the Inputs (Points 3)
 * 
 * The characters a and b are either '1' or '0'. The return
 * is the logical '1' if character a is '1' and b is '0' or
 * if b is '1' and a is '0'.
 *
 * NOTE: Use the functions logic_NOT, logic_AND, logic_OR
 * to implement this function.
 */
char logic_XOR(char a, char b) {
    if ((logic_OR(a,b)=='1')&& !(a=='1' && b=='1')){ //if a,b pass or AND a,b are both not 1, return true
        return '1'; 
    }
    return '0';
}

/**
 * Logical single bit full addr. (Points 5)
 * 
 * INPUTS:
 *   char cin => carry in bit.
 *   char a => input bit.
 *   char b => input bit.
 *   char *cout => carry out bit.
 *   char *s => sum bit.
 *
 * All characters are either '1' or '0'.
 *
 * S = A xor B xor C_in
 * C_out = (A and B) or (A and C_in) or (B and C_in)
 *
 * NOTE: Use the functions logic_AND, logic_OR, logic_XOR
 * to implement this function.
 */
void logic_FULL_ADDR(char cin, char a, char b, char *cout, char *s) {
    char v;
    char w;
    char x;
    char y;
    char z;

    //sum bit (S)
    w=logic_XOR(a,b); //w = A xor B
    s=logic_XOR(cin,w); //Cin xor (A xor B)

    //carry bit (C_out)
    x=logic_AND(a,b); //x = A and B
    y=logic_AND(a,cin); //y = A and C_in
    z=logic_AND(b,cin); //z = B and C_in

    v=logic_OR(y, z); //v = (A and C_in) or (B and C_in)
    cout=logic_OR(z, v); //u= (A and B) or [(A and C_in) or (B and C_in)]
}

/**
 * Logical single bit 2:1 Multiplexer. (Points 5)
 * 
 * INPUTS:
 *   char s => selector bit.
 *   char d_1 => input bit.
 *   char d_0 => input bit.
 *
 * All characters are either '1' or '0'. Return is defined
 * by the following boolean equation.
 *
 * Y = (d_1 and s) or (d_0 and not s)
 *
 * NOTE: Use the functions logic_NOT, logic_AND, logic_OR
 * to implement this function.
 */
char logic_MUX_2_1(char s, char d_1, char d_0) {
    char u,v,y;
    u = logic_AND(d_1, s);
    v = logic_AND(d_0, !s);
    y = logic_OR(u, v);
    return y;
}

/**
 * Logical single bit 4:1 Multiplexer. (Points 10)
 * 
 * INPUTS:
 *   char *s => selector bit.
 *   char d_3 => input bit.
 *   char d_2 => input bit.
 *   char d_1 => input bit.
 *   char d_0 => input bit.
 *
 * All characters are either '1' or '0'. The selector bit is a
 * pointer to at least two characters. The return is defined
 * by the following boolean equation.
 *
 * Y = (d_3 and s[1] and s[0]) or (d_2 and not s[1] and s[0]) \
 *   or (d_1 and s[1] and not s[0]) or (d_0 and not s[1] and not s[0])
 *
 * NOTE: Use the functions logic_NOT, logic_AND, logic_OR
 * to implement this function.
 */
char logic_MUX_4_1(char *s, char d_3, char d_2, char d_1, char d_0) {
    return '0';
}

/**
 * Logical single bit decoder. (Points 5)
 * 
 * INPUTS:
 *   char e => enable bit.
 *   char a => input bit.
 *   char *y1 => output bit.
 *   char *y0 => output bit.
 *
 * All characters are either '1' or '0'. The y0 and y1 are
 * defined by the following boolean equation.
 *
 * y0 = (e and not a)
 * y1 = (e and a)
 *
 * NOTE: Use the functions logic_NOT, logic_AND, logic_OR
 * to implement this function.
 */
void logic_DECODER(char e, char a, char *y1, char *y0) {
}
