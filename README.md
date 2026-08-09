# About

Visp is an Lips-like/S-expression language

## grammar

``` ebnf
alphabet ::= "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" | "j" | "k" | "l" |  "m" | "n" | "o" | "p" | "q" | "r" | "s" | "t" | "u" | "v" | "w" | "x" | "y" | "z" "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" | "J" | "K" | "L" | "M" | "N" | "O" | "P" | "Q" | "R" | "S" | "T" | "U" | "V" | "W" | "X" | "Y" | "Z" ;

digit without zero ::= "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;
digit ::= "0" | digit without zero ;

positive integer ::= digit without zero, { digit } ;

underscore ::= "_" ;

identifier ::= alphabet | underscore, { alphabet | digit | underscore } ;

keyword ::= "print" | "+" | "-" | "*" | "/" ;

left paren ::= "(" ;
right paren ::= ")" ;

list ::= left paren, keyword, right paren ;
```
