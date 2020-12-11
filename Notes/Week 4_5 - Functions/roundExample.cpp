#include <math.h>
#include <stdio.h>

double round (double);

int main()
{

printf( "Round 9.8 is  %f", round(9.8)); 

}

double round( double number)
{
return (number >= 0 ? floor(number+0.5) : floor(number-0.5));
}
