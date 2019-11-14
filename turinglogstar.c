#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int turinglogstar(char s[], int i);

int main(){
  int stringsize, i=1;
  char *string = malloc(1);

  while((string[i-1] = getchar()) != EOF)
    string = realloc(string, ++i);
  string[i-2]='\0';

  if (turinglogstar(string, i)==1)
    printf("machine accepts\n");
  else
    printf("machine rejects\n");
  return 0;
}


int turinglogstar(char s[], int i){
  int j = 0;
  int q = 0;
  printf("M is in state %d\n and our string is equal to \n", q);
  printf("%s", s);
  printf("\n");
  while(1){
    printf("M is in state %d\n and our string is equal to \n", q);
    printf("%s", s);
    printf("\n");
    if (q == 0){
      if (s[j] == '1')
        s[j++] = '0', q = -1;
      else
        return 1;
    }
    if (q == -1){
      if (s[j] == '1')
        ++j, q = 1;
      else{
        s = realloc(s, ++i), s[j+1] = '\0', s[j--] = '#';
        return 1;
      }
    }
    else if (q == 1){
      if (s[j] == '1')
        ++j, q = 1;
      else if (s[j] == '\0')
        s = realloc(s, ++i), s[j+1] = '\0', s[j--] = '#', q = 4;
      else
        return 0;
    }
    else if (q == 2){
      if (s[j] == '1')
        ++j;
      else if (s[j] == '\0')
        s = realloc(s, ++i), s[j+1] = '\0', s[j--] = '1', q = 3;
      else
        return 0;
    }
    else if (q == 3){
      if (s[j] == '1')
        --j;
      else if (s[j] == '#')
        --j, q = 4;
      else
        return 0;
    }
    else if (q == 4){
      if (s[j] == 'x')
        --j;
      else if (s[j] == '1')
        s[j--] = 'x', q = 5;
      else if (s[j] == '0')
        ++j, q = 8;
      else
        return 0;
    }
    else if (q == 5){
      if (s[j] == 'x')
        --j;
      else if (s[j] == '1')
       --j, q = 6;
      else if (s[j] == '0')
        ++j, q = 7;
    }
    else if (q == 6){
      if (s[j] == 'x')
        --j;
      else if (s[j] == '1')
       s[j--] = 'x', q = 5;
      else if (s[j] == '0')
        ++j, q = 7;
    }
    else if (q == 7){
      if (s[j] == 'x')
        ++j;
      else if (s[j] == '1')
        ++j;
      else if (s[j] == '#')
        ++j, q = 2;
      else
        return 0;
    }
    else if (q == 8){
      if (s[j] == 'x')
        ++j;
      else if (s[j] == '#')
        ++j, q = 0;
    }
  }
}
