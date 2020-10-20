#include <stdio.h>
#include <cs50.h>

void check_is_valid(long card_num);

int main(void)
{

  long card_num = get_long("Please input card num\n");

  //kicks of the check for a card

  check_is_valid(card_num);
}

int get_sum(long n)
//sums and doubles the correct numbers for the card check Luhn’s algorithm
{
  int sum = 0;
  while (n != 0)
  {
    sum += n % 10;
    //last number is added directly to sum
    n /= 10;
    //last number removed
    int num_to_double = 2 * (n % 10);
    //second to last number doubled
    if (num_to_double >= 10)
    {
      //if doubled number more than one digit, we add each number individualy with the code below
      while (num_to_double != 0)
      {
        sum += num_to_double % 10;
        num_to_double /= 10;
        //12 becomes sum + 1 + 2
      }
    }
    else
    {
      sum += num_to_double;
      //if double is single digit we just add it
    }
    n /= 10;
  }
  return sum;
}

int get_first_two_num(long n)
{
  int num1 = 0;
  int num2 = 0;
  while (n != 0)
  {
    num2 = num1;
    num1 = n;
    n /= 10;
  }
  return num2;
  //returns the first two numbers to check later
}

int get_card_num_length(long n)
{
  int count = 0;
  while (n != 0)
  {
    n /= 10; // n = n/10
    ++count;
  }
  return count;
  //counts how long the card number is
}

bool num_check_master(int n)
{
  for (int i = 51; i < 56; i++)
  {
    if (n == i)
    {
      return true;
    }
  }
  return false;
  // returns false if first two numbers dont match 51 - 55
}

void check_is_valid(long card_num)
{
  int sum = get_sum(card_num);
  int first_two_num = get_first_two_num(card_num);
  int card_length = get_card_num_length(card_num);
  bool valid_number = num_check_master(first_two_num);
  //collects all the info we will need to run conditionals

  if (sum % 10 == 0 && (first_two_num == 34 || first_two_num == 37) && card_length == 15)
  {
    printf("AMEX\n");
  }
  else if (sum % 10 == 0 && first_two_num / 10 == 4 && (card_length == 13 || card_length == 16))
  {
    printf("VISA\n");
  }
  else if (sum % 10 == 0 && valid_number && card_length == 16)
  {
    printf("MASTERCARD\n");
  }
  else
  {
    printf("INVALID\n");
  }
}