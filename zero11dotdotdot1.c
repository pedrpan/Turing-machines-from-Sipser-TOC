#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zero11dotdotdot1(char s[], int i);

main()
{
  int stringsize, keylen, i=1;
  char *string = malloc(1);

  while((string[i-1] = getchar()) != EOF)
    string = realloc(string, ++i);
  string[i-1]='\0';
  stringsize = i-2;
  if (zero11dotdotdot1(string, i)==1)
    printf("machine accepts\n");
  else
    printf("machine rejects\n");
}

int zero11dotdotdot1(char s[], int i){
  int j = 0;
  int q = 0;
  printf("M is in state %d\n and our string is equal to \n", q);
  printf(s);
  printf("\n");
  while(1){
    printf("M is in state %d\n and our string is equal to \n", q);
    printf(s);
    printf("\n");
    if (q == 0){
      if (s[j] == '0')
        s[j++] ='1', q = 1;
      else
        return 0;
    }
    else if (q == 1){
      if (s[j] == '1')
        s[j--] ='0', q = 3;
      else if (s[j++] == '\0')
        return 1;
    }
    else if (q == 3){
      if (s[j] == '1')
        s[j++] ='0', q = 0;
      else
        return 0;
    }
  }
}
