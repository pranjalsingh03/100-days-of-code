#include <stdio.h>

int main() {
  float income, tax;

  printf("Enter your taxable income: ");
  scanf("%f", &income);

  if (income <= 250000) {
    tax = 0;
  } else if (income > 250000 && income <= 500000) {
    tax = (income - 250000) * 0.05;
  } else if (income > 500000 && income <= 1000000) {
    tax = 12500 + (income - 500000) * 0.2;
  } else {
    tax = 112500 + (income - 1000000) * 0.3;
  }

  printf("Your taxable income is: Rs. %.2f\n", income);
  printf("Your income tax is: Rs. %.2f\n", tax);

  return 0;
}