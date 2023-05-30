#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_TAMANHO 255
#define HEADER 42   
#define STA 16
#define LDA 32
#define ADD 48
#define OR 64
#define AND 80
#define NOT 96
#define JMP 128
#define JN 144
#define JZ 160
#define HLT 240

int verificaNegativo(uint8_t num){
  return num >> 7;
}

int verificaExtensao(char *nomeArquivo){
  char *ext = strrchr(nomeArquivo, '.');
  
  if (strcmp(ext,".nar") != 0){
    printf("\nO arquivo deve ser do formato .nar!\n");
    return 1;
  }

  return 0;
}

void lerBinario(char *nomeArquivo){
  if(verificaExtensao(nomeArquivo)){
    exit(0);
  }

  static uint8_t c[MAX_TAMANHO];
  FILE *f;
  f = fopen(nomeArquivo, "r");
  fseek(f, 0, SEEK_SET);
  fread(c, 512, 1, f);
  
  for(int i = 0; c[i] != HLT; i++){
    printf(" %u ", c[i]);
  }

  printf("\n");
}

void geracaoBinario(char *buffer, int tamanhoBuffer, char *nomeArquivo){
  FILE *f = fopen(nomeArquivo, "wb");
  fwrite(buffer, 1, tamanhoBuffer, f);
  fclose(f);
}

void verificaBytes(char *nomeArquivo){
  uint8_t c[MAX_TAMANHO], Ac, PC;
  int cont = 3;
  FILE *f;
  f = fopen(nomeArquivo, "r");
  fseek(f, 0, SEEK_SET);
  fread(c, 512, 1, f);
  
  if(c[0] != HEADER){
    printf("\nRejeitado! O primeiro byte deve ser 42.");
    exit(0);
  }
  
  Ac = c[1];
  PC = c[2];
 
  while(c[cont] != HLT){
    switch(c[cont]){
      case STA:
        cont++;
        c[c[cont]] = Ac;
        break;
      
      case LDA:
        cont++;
        Ac = c[c[cont]];
        break;
    
      case ADD:
        cont++;
        Ac += c[c[cont]];
        break;

      case OR:
        cont++;
        Ac |= c[c[cont]];
        break;

      case AND:
        cont++;
        Ac &= c[c[cont]];
        break;

      case NOT:
        Ac = ~Ac;
        break;

      case JMP:
        cont++;
        cont = c[cont];
        cont--;
        break;

      case JN:
        cont++;
        if(verificaNegativo( c[c[cont]]) )
        cont = c[cont];
          cont--;
        break;
      
      case JZ:
        if(Ac == 0){
          cont++;
          cont = c[cont];
          cont--;
        }
        break;
    }
    cont++;
  }

  PC = cont;

  printf("\nACUMULADOR: %u\n", Ac);
  printf("\nProgram counter: %u\n", PC);

}

int main(int argc, char **argv) {
  lerBinario(argv[1]);
  verificaBytes(argv[1]);

	return 0;
}