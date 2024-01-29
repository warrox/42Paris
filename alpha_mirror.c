#include <unistd.h>

void alpha_mir(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] >= 97 && str[i] <= 122)
        {
            str[i]= 122-str[i] + 97;
        }
        else if(str[i] >= 65 && str[i] <= 90)
        {
            str[i]= 90-str[i] + 65;
        }
        write(1,&str[i],1);
        i++;
    }
}
int main (int argc, char **argv)
{
    if(argc ==2)
    {
        alpha_mir(argv[1]);
    }
    write(1,"\n",1);
}