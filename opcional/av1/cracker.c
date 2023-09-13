#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  FILE *f = fopen("./teste.in", "w+");
  char *str;
  //Você deve preparar a string de entrada (STDIN) aqui!
  fwrite(str, 1, strlen(str), f);  
  fclose(f);

  system("sudo echo 0 > /proc/sys/kernel/randomize_va_space");
  system("./solucao < teste.in");
  system("sudo echo 2 > /proc/sys/kernel/randomize_va_space");
}