#include <stdio.h>
int i=0;
int j=0;
int main(){
     char s1[100]="sri";
     char s2[]="dharan";
     while(s1[i]!='\0'){
         i++;
     }
     while(s2[j]!='\0'){
         s1[i]=s2[j];
         i++;
         j++;
     }
     s1[i]='\0';
     printf("Concatenated string is: %s\n",s1);
     return 0;
}

