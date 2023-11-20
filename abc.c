#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LEN 80 /* difined by the question */

/*
Given a string of characters, we search for ascending sequences of characters from the English alphabet, with a length of at least 3,
Each sequence will be shortened to three characters: the first letter of the sequence, a hyphen, and the last letter of the sequence.
*/

void shrink_string(char s[]); /* the metod that will do the hard work on the string */

int main ()
{
    int i;
    char c, userString[LEN]={'\0'};
    printf("please enter your string\n");
    for(i=0;i<LEN-1 && ((c=getchar())!='\n');i++) /* simple loop to get the string from user or file, i am expecting for a single long word up to 79 chars that what i understud from the question */
        userString[i]=c;
    shrink_string(userString); /* call for the metod to fix the string */
    printf("\nyour string after the shrink is:\n%s\n",userString);
    return 0;
}

void shrink_string(char s[])
{
    int i,j,k,len; /* i,j,k are pointers that i will use for the string */
    len=strlen(s);
    for(i=0;i<len-1;) /* first loop that going throu all the string */
    {
        if(islower(s[i])||isupper(s[i])) /* i am looking for the letters cause every thing else not importent else i go next char */
        {
          if((s[i]+2==s[i+1]+1)&&(s[i+1]+1==s[i+2])) /* check if first 3 letters by ascending order if not i go next char */
          {
            s[i+1]='-'; /* second char in the 3 letter combination is - */
            for(j=i+2;j<len;) /* second loop to check how long the ascending order is */
            {
                if(s[j]+1==s[j+1])
                    j++;
                else
                {
                    k=i+2;
                    i=i+3;
                    for(;j<len+1;) /* third loop to delete all the chars that arent needed */
                    {
                        s[k]=s[j];
                        k++;
                        j++;
                    }
                }
            }
          }
          else i++;
        }
        else i++;
    }
}
