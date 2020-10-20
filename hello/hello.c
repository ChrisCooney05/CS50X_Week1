#include <stdio.h>
#include <cs50.h>

int main(void)
{
  //we need strict typing for variables
  string name = get_string("What is your name?\n");

  //%s is a placeholder for a string, name in this case
  printf("Hello, %s\n", name);
}