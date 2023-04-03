#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokenizar(FILE *a) {
  int i = 0;
  int contPonto = 0;
  int contVirg = 0;
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
      if(contPonto == 1){
        contPonto = contPonto - 1;
      }
      if(contVirg == 1){
        contVirg = contVirg - 1;
      }
    }
    else if (texto[i] == '0'){
      printf("%c\n", texto[i]);
      i = i + 1;
    }
    else if (texto[i] == '1'){
      printf("%c\n", texto[i]);
      i = i + 1;
    }
    else if (texto[i] == '2'){
      printf("%c\n", texto[i]);
      i = i + 1;
    }
    else if (texto[i] == '3'){
      printf("%c\n", texto[i]);
      i = i + 1;
    }
    else if (texto[i] == '4'){
      printf("%c\n", texto[i]);
      i = i + 1;
    }
    else if (texto[i] == '5'){
      printf("%c\n", texto[i]);
      i = i + 1;
    }
    else if (texto[i] == '6'){
      printf("%c\n", texto[i]);
      i = i + 1;
    }
    else if (texto[i] == '7'){
      printf("%c\n", texto[i]);
      i = i + 1;
    }
    else if (texto[i] == '8'){
      printf("%c\n", texto[i]);
      i = i + 1;
    }
    else if (texto[i] == '9'){
      printf("%c\n", texto[i]);
      i = i + 1;
    }
    else if (texto[i] == '.'){
      if(contPonto == 0){
        printf("%c\n", texto[i]);
        contPonto = contPonto + 1;
        i = i + 1;
      }
      else{
        i = i + 1;
      }
    }
    else if (texto[i] == ','){
     if(contVirg == 0){
        printf("%c\n", texto[i]);
        contVirg = contVirg + 1;
        i = i + 1;
      }
      else{
        i = i + 1;
      }
    }
    else if(texto[i+1] == '\0'){
        
    } 
    else if (texto[i] != '\0'){
      printf("Indeterminado: %c\n", texto[i]);
      i = i + 1;
    }
  }

}
int main(int argc, char **argv) {
  FILE* arquivo;
  arquivo = fopen(argv[1], "r");

  tokenizar(arquivo);
  return 0;
}

