/**************************************************************************
 *
 *  Context-sensitive rules associated with certain endings.
 *
 *  The notations of the rules are the same as in Lovins' paper
 *  except that rule A is replaced by a NULL in the data structure.
 *
 *  Function parameters:
 *      - stem_length: possible stem length
 *      - end        : pointer points to the end of the possible stem.
 *
 *************************************************************************/
 

//#include "string_wrapper.h"

#include <string.h>

/********* Context-sensitive rule function declarations ******************/
 
static int B();		static int C();
static int D();		static int E();
static int F();		static int G();
static int H();		static int I();
static int J();		static int K();
static int L();		static int M();
static int N();		static int O();
static int P();		static int Q();
static int R();		static int S();
static int T();		static int U();
static int V();		static int W();
static int X();		static int Y();
static int Z();		static int AA();
static int BB();	static int CC();

static int B(int stem_length,char* end)
{
    return (stem_length >= 3);
}

static int C(int stem_length,char* end)
{
    return (stem_length >= 4);
}
 
static int D(int stem_length,char* end)
{
    return (stem_length >= 5);
}
 
static int E(int stem_length,char* end)
{
    return (*end != 'e');
}
 
static int F(int stem_length,char* end)
{
    return ((stem_length >= 3) && (*end != 'e'));
}
 
static int G(int stem_length,char* end)
{
    return ((stem_length >= 3) && (*end == 'f'));
}
 
static int H(int stem_length,char* end)

{
    char p1, p2;
    p1 = *end;
    p2 = *(end-1);
    return ((p1 == 't') || ((p1 == 'l') && (p2 == 'l')));
}
 
static int I(int stem_length,char* end)

{
    char p1;
    p1 = *end;
    return ((p1 != 'o') && (p1 != 'e'));
}
 
static int J(int stem_length,char* end)
{
    char p1;
    p1 = *end;
    return ((p1 != 'a') && (p1 != 'e'));
}

static int K(int stem_length,char* end)

{
    char p1;
    p1 = *end;
    return ((stem_length >= 3) &&
           ((p1 == 'l') || (p1 == 'i') ||
           ((p1 == 'e') && (*(end-2) == 'u'))));
}
 
static int L(int stem_length,char* end)

{
    char p1, p2;
    p1 = *end;
    p2 = *(end-1);
    if (p1 == 's')
        return (p2 == 'o');
    else
        return ((p1 != 'u') && (p1 != 'x'));
}
 
static int M(int stem_length,char* end)

{
    char p1;
    p1 = *end;
    return ((p1 != 'a') && (p1 != 'c') &&
            (p1 != 'e') && (p1 != 'm'));
}
 
static int N(int stem_length,char* end)
{
    if (stem_length >= 3)
    {
        if (*(end-2) == 's')
            return (stem_length >= 4);
        else
            return 1;
    }
    else
       return 0;
}
 
static int O(int stem_length,char* end)

{
    char p1;
    p1 = *end;
    return ((p1 == 'l') || (p1 == 'i'));
}
 
static int P(int stem_length,char* end)

{
    return (*end != 'c');
}
 
static int Q(int stem_length,char* end)

{
    char p1;
    p1 = *end;
 
    return ((stem_length >= 3) && (p1 != 'l') && (p1 != 'n'));
}
 
static int R(int stem_length,char* end)
{
    char p1;
    p1 = *end;
    return ((p1 == 'n') || (p1 == 'r'));
}
 
static int S(int stem_length,char* end)
{
    char p1,p2;
    p1 = *end;
    p2 = *(end-1);
 
    if (p1 == 't')
        return (p2 != 't');
    else
        return ((p1 == 'r') && (p2 == 'd'));
}
 
static int T(int stem_length,char* end)

{
    char p1,p2;
    p1 = *end;
    p2 = *(end-1);
 
    if (p1 == 't')
        return (p2 != 'o');
    else
        return (p1 == 's');
}
 
static int U(int stem_length,char* end)
{
    char p1;
    p1 = *end;
 
    return ((p1 == 'l') || (p1 == 'm') ||
            (p1 == 'n') || (p1 == 'r'));
}
 
static int V(int stem_length,char* end)
{
    return (*end == 'c');
}
 
static int W(int stem_length,char* end)

{
    char p1;
    p1 = *end;
 
    return ((p1 != 's') && (p1 != 'u'));
}
 
static int X(int stem_length,char* end)

{
    char p1;
    p1 = *end;
 
    if (p1 == 'e')
        return ((stem_length >= 3) && (*(end-2) == 'u'));
    else
        return ((p1 == 'l') || (p1 == 'i'));
}
 
static int Y(int stem_length,char* end)

{
    return ((*end == 'n') && (*(end-1) == 'i'));
}
 
static int Z(int stem_length,char* end)

{
    return (*end != 'f');
}
 
static int AA(int stem_length,char* end)

{
    char p1, p2;
    p1 = *end;
    p2 = *(end-1);
 
    if (p1 == 'h')
        return ((p2 == 'p') || (p2 == 't'));
    else if (p1 == 'r')
        return ((p2 == 'e') || (p2 == 'o'));
    else if (p1 == 's')
        return (p2 == 'e');
    else
        return ((p1 == 'd') || (p1 == 'f') ||
                (p1 == 'l') || (p1 == 't'));
}
 
static int BB(int stem_length,char* end)

{
    if (stem_length >= 3)
    {   if (stem_length >= 4)
            return (strncmp(end-3,"ryst",4) != 0);
        else
            return (strncmp(end-2,"met",3) != 0);
    }
    else
       return 0;
}
 
static int CC(int stem_length,char* end)
{
    return (*end == 'l');
}

