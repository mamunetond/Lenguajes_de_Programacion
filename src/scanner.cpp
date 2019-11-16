#include "scanner.h"
#include "excepcion.h"
#include <iostream>
#include <string>

using namespace std;

//Uncomment this to get debug information
//#define debug

const int numberOfKeywords = 8;

const string keywd[numberOfKeywords] = {
                                        string("S"), string("T"), string("X"), string("Var"\
), string("->"), string("Nat"), string("Bool"), string("Y")
};

int isLetter(char c) {
   return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int isDigit(char c) {
  return (c >= '0' && c <= '9');
}

int isWhiteSpace(char c) {
  return (c == ' ' || c == '\t' || c == '\n');
  }

Scanner::Scanner(istream* in):
  inStream(in),
  lineCount(1),
  colCount(-1),
  needToken(true),
  lastToken(nullptr)
{}

Scanner::~Scanner() {
   try {
      delete inStream;
   } catch (...) {}
   }

void Scanner::putBackToken() {
   needToken = false;
}

Token* Scanner::getToken() {
   if (!needToken) {
      needToken=true;
      return lastToken;
   }

   Token* t;
   int state=0;
    bool foundOne=false;
   int c;
   string lex;
   TokenType type;
   int k;
   int column, line;

   c = inStream->get();

#ifdef debug
   cout << c << endl;
#endif

   while (!foundOne) {
    colCount++;
      switch (state) {
         case 0 :
            lex = "";
            column=colCount;
            line = lineCount;
            if (isLetter(c)) state=1;
            else if (isDigit(c)) state=2;
              colCount=-1;
               lineCount++;
            }
            else if (isWhiteSpace(c));
            else if (inStream->eof() or c== EOF) {
               foundOne=true;
               type=eof;
            }
            else {
              cout << "* scanner error" << endl;
               throw UnrecognizedToken;
                }
            break;
         case 1 :
           if (isLetter(c) || isDigit(c)) state=1;
            else {
               for (k=0;k<numberOfKeywords;k++)
                  if (lex == keywd[k]) {
                     foundOne = true;
                     type = keyword;
                  }
               if (!foundOne) {
                  type = identifier;
                   foundOne = true;
               }
            }
            break;
         case 2 :
            if (isDigit(c)) state=2;
            else {
               type = number;
               foundOne=true;
            }
            break;
         
         case 7 :
         type = lparen;
            foundOne=true;
            break;
         case 8 :
            type = rparen;
            foundOne=true;
            break;
         case 10 :
            type = equals;
            foundOne=true;
             break;
      }

      if (!foundOne) {
        lex = lex + (char)c;
         c = inStream->get();
#ifdef debug
         cout << c << endl;
#endif

      }
   }

   inStream->putback(c);
   colCount--;
   if (type == number || type == identifier || type == keyword) {
      t = new LexicalToken(type,new string(lex), line, column);
   }
   else {
      t = new Token(type,line,column);
   }

#ifdef debug
   cout << "just found " << lex << " with type " << type << endl;
#endif

   lastToken = t;
   return t;
   }






               



