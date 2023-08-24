#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(int argc, char *argv[]){
  if(argc == 3){
    char *operation = argv[2];
    const char *str_with_sign = argv[1];
    const char *str_no_sign = str_with_sign;
    if(*str_no_sign == '-' || *str_no_sign == '+'){
      str_no_sign++;
    }
    double value1 = custom_atof(str_no_sign);
    if(strcmp(operation, SQR) == 0){
      sqr(value1);
    }else if(strcmp(operation, ABSOLUTE) == 0){
      absolute(value1);
    }else{
	  printf("Error: invalid operand.\n");
	  exit(EXIT_FAILURE);
    }
  }else if(argc == 4){
    char *operation = argv[2];
    double value1 = atof(argv[1]);
    double value2 = atof(argv[3]);
    if(strcmp(operation, ADDITION) == 0){
      addition(value1, value2);
    }else if(strcmp(operation, SUBSTRACTION) == 0){
      substraction(value1, value2);
    }else if(strcmp(operation, MULTIPLICATION) == 0){
      multiplication(value1, value2);
    }else if(strcmp(operation, DIVISION) == 0){
	division(value1, value2);
    }else if(strcmp(operation, MODULO) == 0){
      modulo(value1, value2);
    }else if(strcmp(operation, EXPONENT) == 0){
      exponent(value1, value2);
    }else{
      printf("Error: invalid operand.\n");
    }
  }else if(argc == 2){
    char *value = argv[1];
    if(strcmp(value, "-v") == 0){
      version();
    }
  }else{
    printf("Usage: calc [arg] [operand] [arg]\n");
  }
}

void addition(double value1, double value2){
  double result = value1 + value2;
  printf("Result: %f\n", result);
}

void substraction(double value1, double value2){
  double result = value1 - value2;
  printf("Result: %f\n", result);
}

void multiplication(double value1, double value2){
  double result = value1 * value2;
  printf("Result: %f\n", result);
}

void division(double value1, double value2){
  if(value1 == 0.0){
    printf("Error: division by zero is disabled\n");
    exit(EXIT_FAILURE);
  }
  double result = value1 / value2;
  printf("Result: %f\n", result);
}

void modulo(double value1, double value2){
  while(value1 >= value2){
    value1 -= value2;
  }
  int result = value1;
  printf("Result: %d\n", result);
}

void exponent(double value1, double value2){
  while(value1 < value2){
    value1 = value1 * value2;
  }
  double result = value1;
  printf("Result: %f\n", result);
}

void sqr(double value1){
  double estimation = value1 / 2;
  for(int i = 0; i != 10; i++){
    estimation = (estimation + value1 / estimation) / 2;
  }
  double result = estimation;
  printf("Result: %f\n", result);
}

void version(){
  printf("%s\n", VERSION);
}

void absolute(double value1){
  double result = value1 >= 0 ? value1 : -value1;
  
  printf("Result : %f\n", result); 
}

double custom_atof(const char *str){
  unsigned short sign = 1;
  if(*str == '-'){
    sign = -1;
    str++;
  }else if(*str == '+'){
    str++;
  }
  double result = 0.0;
  while(*str >= '0' && *str <= '9'){
    result = result * 10.0 + (*str - '0');
    str++;
  }
  if(*str == '.'){
    double fraction = 0.1;
    str++;
    while(*str >= '0' && *str <= '9'){
      result += (*str - '0') * fraction;
      fraction /= 10.0;
      str++;
    }
  }
  return sign * result;
}
