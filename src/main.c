#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>


char* getInput();
void lowercase(char *str);
void reverse(char *str);
void print(char* str);

int main()
{
   int selection = 0;
   char *string;

   printf("This program takes a string of words and reverses it.\n");
   printf("*****************************************************\n\n");

   while(selection != 3)
   {
      printf("Enter string\t(0\n");
      printf("Reverse string\t(1\n");
      printf("Print string\t(2\n");
      printf("Exit\t\t(3\n\n");
      printf("Please select an option: ");

      scanf("%d", &selection);
      printf("\n");

      switch(selection)
      {
         case 0: string = getInput(); break;
         case 1: reverse(string); break;
         case 2: print(string); break;
         case 3: printf("exiting...\n"); break;
         default: printf("Invalid input!\n\n");
      }
   }

   free(string);

   return 0;
}

char* getInput()
{
   char *str = NULL;
   size_t size = 0;
   char c;

   printf("Begin ('@' to finish): ");

   while((c = getc(stdin)) != '@')
   {
      str = realloc(str, size + 1);
      if(str == NULL)
      {
         fprintf(stderr, "Error allocating memory!\n\n");
         exit(1);
      }
      str[size++] = c;
   }
   str = realloc(str, size + 1);
   if(str == NULL)
   {
      fprintf(stderr, "Error allocating memory!\n\n");
      exit(1);
   }
   str[size] = '\0';

   printf("Thank you.\n\n");

   return str;
};

void lowercase(char *str)
{
   int length = strlen(str);
   for(int i = 0; i < length; i++)
   {
      str[i] = tolower(str[i]);
   }
}

void reverse(char* str)
{
   if(str == NULL)
   {
      fprintf(stderr, "String is empty!\n\n");
   }
   else 
   {
      lowercase(str);
      int length = strlen(str);

      for(int i = 0; i < length / 2; i++)
      {
         char temp = str[i];
         str[i] = str[strlen(str) - i - 1];
         str[strlen(str) - i - 1] = temp;
      }
      printf("Successfully reversed string.\n\n");
   }
}

void print(char* str)
{
   if(str == NULL)
   {
      fprintf(stderr, "String is empty!\n\n");
   }
   else 
   {
      printf("%s\n\n", str);
   }
}
