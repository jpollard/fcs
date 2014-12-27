/* 2.2.4.c
 * Joe Pollard, 12/26/14
 *
 * Problem 2.2.4 
 * 
 * Write a C function that takes two linked lists of characters as arguments and returns TRUE if the fist string preced the second, ignoring case
 */

#include <stdlib.h>
#include <stdio.h>

// Linked list of chars
struct list_char {
  char letter;
  struct list_char *next;
};

// Defined list as a "String"
typedef struct list_char String;

/* Prototype */
int compStringIt(String *str1, String *str2);
int compStringRec(String *str1, String *str2);

void main(){
  String *str1, *str2, *head;
  int i;

  head = NULL;

  for(i=1; i <= 10; i++){
    str1 = (String *)malloc(sizeof(String));
    str1->letter = (char)('a' + i);
    str1->next = head;
    head = str1;
  }

  for(i=1; i <= 10; i++){
    str2 = (String *)malloc(sizeof(String));
    str2->letter = (char)('J' + i);
    str2->next = head;
    head = str2;
  }

  str2 = head;

  if(compStringRec(str1, str2)){
    printf("True\n");
  } else {
    printf("False\n");
  }
}


/*
 * compare 2 linked lists of chars and return TRUE if list1 precedes list2, iteratively
 */
int compStringIt(String *str1, String *str2){
  int lessThan = 1;

  printf("str1\tstr2\n");
  printf("----------------\n");

  while(str1 && str2){
    if(str2->letter < str1->letter){
      lessThan = 0;
    }
    printf("%c\t%c\n", str1->letter, str2->letter);
    str1 = str1->next;
    str2 = str2->next;
  }

  return lessThan;
}

/*
 * compare 2 linked lists of chars and return TRUE if list1 precedes list2, recursively
 */
int compStringRec(String *str1, String *str2){
  int lessThan = 1;
  printf("%c\t%c\n", str1->letter, str2->letter);

  if(tolower(str1->letter) < tolower(str2->letter)){
    if((str1->next != NULL) && (str2->next != NULL)){
      lessThan = compStringRec(str1->next, str2->next);
    }
  } else {
    lessThan = 0;
  }

  return lessThan;
}
