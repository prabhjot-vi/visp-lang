# About

Visp is an Lips-like/S-expression language

## grammar

``` ebnf
alphabet ::= "a" | "b" | "c" | "d" | "e" | "f" | "g" 
            | "h" | "i" | "j" | "k" | "l" |  "m" | "n" 
            | "o" | "p" | "q" | "r" | "s" | "t" | "u" 
            | "v" | "w" | "x" | "y" | "z"
            | "A" | "B" | "C" | "D" | "E" | "F" | "G" 
            | "H" | "I" | "J" | "K" | "L" | "M" | "N" 
            | "O" | "P" | "Q" | "R" | "S" | "T" | "U" 
            | "V" | "W" | "X" | "Y" | "Z" ;

digit without zero ::= "1" | "2" | "3" | "4" | "5"
                        | "6" | "7" | "8" | "9" ;

digit ::= "0" | digit without zero ;

positive integer ::= digit without zero , { digit } ;

character ::= letter | digit ;

string ::= { character } ;

underscore ::= "_" ;

identifier ::= alphabet | underscore , 
                { alphabet | digit | underscore } ;

print ::= "print" ;
add ::= "+" ;
sub ::= "-" ;
mul ::= "*" ;
div ::= "/" ;

binary keyword ::= add | sub | mul | div ;

unary keyword ::= print ;

keyword ::= unary keyword | binary keyword ;

left paren ::= "(" ;

right paren ::= ")" ;

expression ::= left paren ,
            [ 
                ( binary keyword , positive integer , positive integer )
                | ( unary keyword , string )
            ] 
            , right paren ;
```
