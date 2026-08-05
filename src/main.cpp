#include <iostream>
#include <string>

enum class Token
{
  Number,

  LParen,
  RParen,

  Add,
  Sub,
  Mul,
  Div,

  Print
};

int main()
{
  std::string expr = "(+ 2 3)";

  for (const char ch : expr)
  {
    std::cout << ch << '\n';
  }

  return 0;
}
