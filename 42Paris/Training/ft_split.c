#include <stdio.h>
#include <stdlib.h>

/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);*/
#include <stdlib.h>
int ft_lenght(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        i++;
    }
    return(i);
}
char **ft_split(char *str)
{
    int i ;
    char **split = NULL;
    i = 0;
    **split = malloc(sizeof(char) * ft_lenght(str));
    if(!split)
        return(0);
    while(str[i])
    {
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            i++; //t
        }
        i++;
    }
    return(split);
}

int main()
{
    char    *s = "Hello World";
    ft_split(s);
}
