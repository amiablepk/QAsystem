/*****************************************************************************
 *
 *   Transformational Rules used in Recoding Stem Terminations
 *
 *   Parameter in functions:
 *       ch : the second last character of the old ending
 *            (after removing one of double consonants) 
 *
 ****************************************************************************/
 

/************ Conditional rules associated with transformations **************/

static int aio();
static int s();
static int pt();
static int m();
static int n();

static int aio(char ch)					/* Rule number 9     */
{
    return ((ch != 'a') && (ch != 'i') && (ch != 'o'));
}
 
static int s(char ch)					/* Rule Number 24    */
{
    return (ch != 's');
}
 
static int pt(char ch)					/* Rule number 28    */
{
    return ((ch != 'p') && (ch != 't'));
}
 
static int m(char ch)					/* Rule number 30    */
{
    return (ch != 'm');
}
 
static int n(char ch)					/* Rule number 32    */

{
    return (ch != 'n');
}

