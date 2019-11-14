#include <stdio.h>
#include <stdlib.h>

int turingpoweroftwo(char s[]);

int main(){
  int stringsize, i=1;
  char *string = malloc(1);

  while((string[i-1] = getchar()) != EOF)
    string = realloc(string, ++i);
  string[i-1]='\0';
  
  if (turingpoweroftwo(string)==1)
    printf("The machine accepts");
  else
    printf("The machine rejects");
  
  return 0;
}

int turingpoweroftwo(char s[]){
  int j = 0;
  int q = 1;
  printf("M is in state %d\n and our string is equal to \n", q);
  printf("%s", s);
  printf("\n");
  s[j++] = 'u';
  if (s[j] == '\0')
    return 1;
  q = 2;
  while(1){
    printf("M is in state %d\n and our string is equal to \n", q);
    printf("%s", s);
    printf("\n");
    if (q == 2){
      if (s[j] == '0')
        s[j++] ='x', q = 3;
      else if (s[j++] == '\0')
        return 1;
    }
    else if (q == 3){
      if (s[j] == '0')
        ++j, q = 4;
      else if (s[j] == 'x')
        ++j;
      else if (s[j] == '\0')
        --j, q = 5;
    }
    else if (q == 5){
      if (s[j] == '0')
        --j;
      else if (s[j] == 'x')
        --j;
      else if (s[j] == 'u')
        ++j, q = 2;
    }
    else if (q == 4){
      if (s[j] == '0')
        s[j++] ='x', q = 3;
      else if (s[j] == 'x')
        ++j;
      else if (s[j] == '\0')
        return 0;
    }
  }
}
