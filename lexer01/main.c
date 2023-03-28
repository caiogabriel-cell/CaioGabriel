#include <stdio.h>
#include <stdlib.h>

void tokenizar(FILE *a) {
  int i = 0;
  char c;

  do{
     c = fgetc(a);
    
    if (c == '+'){
        printf("Mais\n");
      }
      else if (c == '-'){
        printf("Menos\n");
      }
      else if (c == '*'){
        printf("Multiplicação\n");
      }
      else if (c == '/'){
        printf("Divisão\n");
      }  
      else if (c == ' '){
        
      }
      else if (c == NULL){
        printf("Nulo\n");
      }
      else if (c != '\0'){
        
      }
      else {
        fprintf(stdout, "Indeterminado: %c\n", c);
      }
  }while(c != EOF); 
}

int main(int argc, char **argv) {
  FILE* arquivo;
  arquivo = fopen(argv[1], "r");

  tokenizar(arquivo);
  return 0;
}

