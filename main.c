#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void forca(int estado){
  if(estado == 0){
    printf("\n ------------");
    printf("\n|           |");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  }
  else if(estado == 1){
    printf("\n ------------");
    printf("\n|           |");
    printf("\n|           o");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  }
  else if(estado == 2){
    printf("\n ------------");
    printf("\n|           |");
    printf("\n|           o");
    printf("\n|           |");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  }
  else if(estado == 3){
    printf("\n ------------");
    printf("\n|           |");
    printf("\n|           o");
    printf("\n|          /|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  }
  else if(estado == 4){
    printf("\n ------------");
    printf("\n|           |");
    printf("\n|           o");
    printf("\n|          /|\\");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  }
  else if(estado == 5){
    printf("\n ------------");
    printf("\n|           |");
    printf("\n|           o");
    printf("\n|          /|\\");
    printf("\n|          /");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  }
  else if(estado == 6){
    printf("\n ------------");
    printf("\n|           |");
    printf("\n|           o");
    printf("\n|          /|\\");
    printf("\n|          / \\");
    printf("\n|");
    printf("\n|      Você Perdeu!");
    printf("\n|");
    printf("\n-");
  }
}


int main() {
  int i;
  int erros = 0;
  char psec[100];

  printf("JOGADOR 1:");
  printf("\nInforme a Palavra Secreta: \n");
  fgets(psec, 100, stdin);
  
  printf("A palavra secreta é %s", psec);
  printf("A palavra tem %lu caracteres", strlen(psec)-1);
  
  for(i = 0; i < 30; i++){
    printf("\n");
  }



  
  psec[strlen(psec)-1] = '\0'; // psec vai ter o espaço da palavra menos 1 onde ficara o \0

  

  //copia da palavra secreta de psec para ptela
  char ptela[100];
  strcpy(ptela, psec); //comando para copiar o que esta em psec
  

  
  for(i = 0; i < strlen(ptela); i++){
    ptela[i] = '_';
  }



  //sistema do jogo
  while(1){
    forca(erros);

    printf("\nAdivinhe: ");
    for(i = 0; i<strlen(ptela); i++){
      printf("%c ", ptela[i]);
    }
    
    printf("\nLetra: ");
    char letra;
    scanf(" %c", &letra);

    

    //começa considerando se errou
    int quandoErrar = 1;
    for (i = 0; i<strlen(ptela); i++){
      if (letra == psec[i]){ 
        ptela[i] = letra;
        quandoErrar = 0; //se a letra for igual ele retira o erro, colocando = 0
      }
    }
    if(quandoErrar == 1){
      erros++;
    }



    
    //VERIFICA SE GANHOU
    if(strcmp(ptela, psec) == 0){
      printf("\nVOCÊ GANHOU! PARABÉNS!!!");
      break;
    }
    
    //VERIFICA SE PERDEU
    if(erros == 6){
      forca(erros);
      printf("=== GAME OVER ===");
      break;
    }

  }

 
  return 0;
}