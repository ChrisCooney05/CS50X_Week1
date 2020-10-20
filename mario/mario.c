#include <stdio.h>
#include <cs50.h>

void build(int n);
// function prototype so I can hide function under the main call

int main(void)
{
  int n;
  do
  {
    n = get_int("give me a number\n");
  } while (n < 1 || n > 8);

  // checks number to make sure its over 1 but under 9

  build(n);
  //runs the build function
}

void buildLeft(int n)
//builds the left side and includes the standard two spaces between each side
{
  for (int i = 0; i < n; i++)
  {
    printf("#");
  }
  printf("  ");
}

void buildRight(int n)
//builds the right side of the pyramid and adds a new line
{
  for (int i = 0; i < n; i++)
  {
    printf("#");
  }
  printf("\n");
}

void buildSpace(int n)
//adds any spaces that may be needed to ensure a pyramid shape
{
  for (int i = 0; i < n; i++)
  {
    printf(" ");
  }
}

void build(int n)
//controls the build
{

  int count = 1;
  int space = n - 1;

  for (int i = 0; i < n; i++)
  {
    buildSpace(space);
    buildLeft(count);
    buildRight(count);
    count++;
    space--;
  }
}