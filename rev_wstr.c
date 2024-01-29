// creer un catcheur dl'alphabet dans boucle if true
#include <stdlib.h>
#include <stdio.h>
int ft_wordlen(char *str, int index)
{
    int i = index ;
    while(str[i])
    {
        if(str[i] == ' ' || str[i] == '\t')
            return(i);
        i++;
    }
    return(i);
}

int word_creator(char *str, int index)
{
    char *new_word;
    int i = 0;
    new_word = malloc(sizeof(char) * (ft_wordlen(str,index) + 1));
    if(!new_word)
        return(0);
    printf("Debug 3");

    while(str[index] != ' ' || str[index] != '\t')
    {
        printf("Debug 4");
        new_word[i] = str[index];
        i++;
        index++;
    }
    new_word[i] = '\0';
    return(0);
}
int word_catcher(char c)
{
    if(c != ' ' && c != '\t')
    {
        printf("Debug 1");
        return(1);
    }
    return(0);
}
void rev_wstr(char *str)
{
    int i = 0;
    int index = 0;
    while(str[i])
    {
        if(word_catcher(str[i])== 1)
        {
            index = i;
            printf("Debug 0 ");
            word_creator(str, index);
            index = 0;
        }
        i++;
    }
}

int main (int argc, char **argv)
{
    if(argc == 2)
    {
        printf("Debug 3");
        rev_wstr(argv[1]);
    }
}