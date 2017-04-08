#include <stdio.h>
int main(){
char c=0;
while((c=getchar())!=0)
if(c!='\n')
printf("Print char: %c\n",c);
return 0;
}
