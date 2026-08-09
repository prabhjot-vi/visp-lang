#include <iostream>
#include <string>
#include <vector>
#include <ostream>

enum class TokenType
{
  LParen,
  RParen,

  Add,
  Sub,
  Mul,
  Div,

  Number,
  String,

  Print,
};

std::ostream &operator<<(std::ostream &oStr, const TokenType &token_type)
{
  switch (token_type)
  {
  case TokenType::LParen:
    oStr << "LParen";
    break;
  case TokenType::RParen:
    oStr << "RParen";
    break;

  case TokenType::Add:
    oStr << "Add";
    break;
  case TokenType::Sub:
    oStr << "Sub";
    break;
  case TokenType::Mul:
    oStr << "Mul";
    break;
  case TokenType::Div:
    oStr << "Div";
    break;

  case TokenType::Number:
    oStr << "Number";
    break;
  case TokenType::String:
    oStr << "String";
    break;
  case TokenType::Print:
    oStr << "Print";
    break;

  default:
    std::cerr << "What is this TokenType: " << token_type << '\n';
    exit(1);
    break;
  }

  return oStr;
}

class Token
{
private:
  TokenType m_type;
  std::string m_value;

public:
  explicit Token(TokenType type, std::string value)
      : m_type(type), m_value(value) {}

  TokenType type() const
  {
    return m_type;
  }
  std::string value() const
  {
    return m_value;
  }

  void type(TokenType type)
  {
    m_type = type;
  }
  void value(std::string value)
  {
    m_value = value;
  }
};

std::ostream &operator<<(std::ostream &oStr, const Token &token)
{
  oStr << "Token(" << token.type() << ", \"" << token.value() << "\")";
  return oStr;
}

std::vector<Token> lexer(std::string_view expression)
{
  std::vector<Token> tokens{};

  tokens.push_back(Token(TokenType::Add, "+"));
  tokens.push_back(Token(TokenType::Sub, "-"));
  tokens.push_back(Token(TokenType::Mul, "*"));
  tokens.push_back(Token(TokenType::Div, "/"));
  tokens.push_back(Token(TokenType::Number, "101"));
  tokens.push_back(Token(TokenType::String, "Hello World"));
  tokens.push_back(Token(TokenType::Print, "print"));

  return tokens;
}

std::ostream &operator<<(std::ostream &oStr, const std::vector<Token> &tokens)
{
  oStr << "[\n";
  for (size_t index = 0; index < tokens.size(); ++index)
  {
    const Token &token = tokens.at(index);

    if (index == tokens.size() - 1)
    {
      oStr << '\t' << token << '\n';
    }
    else
    {
      oStr << '\t' << token << ",\n";
    }
  }
  oStr << "]";

  return oStr;
}

int main()
{
  std::string expression = "(+ 2 3)";

  std::vector<Token> tokens = lexer(expression);

  std::cout << tokens << '\n';

  return 0;
}
