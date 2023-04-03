#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokenizar(FILE *a) {
  int i = 0;
  int cont = 0;
  char c;
  char texto[100];

  while(fgets(texto, 100, a) != NULL){
    
  }
  fclose(a);

  while(i < strlen(texto)){
    if (texto[i] == '+'){
      printf("Mais\n");
      i = i + 1;
    }
    else if (texto[i] == '-'){
      printf("Menos\n");
      i = i + 1;
    }
    else if(texto[i] == '*'){
      if(texto[i+1] == '*'){
        printf("Potenciação\n");
        if(texto[i+2] != '\0' && texto[i+2] != NULL){
          i = i + 2;
        }
        else if(texto[i+1] != '\0' && texto[i+1] != NULL){
          i = i + 1;
        }
      }
      else if(texto[i+1] == '\0'){
        
      }
      else {
        printf("Multiplicação\n");
        i = i + 1;
      }
    }  
    else if (texto[i] == '/'){
      printf("Divisão\n");
      i = i + 1;
    }  
    else if (texto[i] == ' '){
      i = i + 1;
    }
    else if (texto[i] == NULL){
      printf("Nulo\n");
      i = i + 1;
    }
    else if (texto[i] != '\0'){
      printf("Indeterminado: %c\n", texto[i]);
      i = i + 1;
    }
  }
/*
  do{
     c = fgetc(a);
    
    if (c == '+'){
        printf("Mais\n");
      }
      else if (c == '-'){
        printf("Menos\n");
      }
      else if (c == '*'){
        cont = cont + 1;
        if(cont / 2 == 0){
          printf("Potenciação\n");
        }
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
*/
}
int main(int argc, char **argv) {
  FILE* arquivo;
  arquivo = fopen(argv[1], "r");

  tokenizar(arquivo);
  return 0;
}

