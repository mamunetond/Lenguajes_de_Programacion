#include "parser.h"
#include "excepcion.h"
#include <string>
#include <sstream>

Parser::Parser(istream* in) {
   scan = new Scanner(in);
}

Parser::~Parser() {
   try {
      delete scan;
   } catch (...) {}
}

AST* Parser::parse() {
   return prog();
}

AST* Parser::prog() {

   AST* result = expr();
   Token* t = scan->getToken();

   if (t->getType() != eof) {
     cout << "* parser error" << endl;
     throw ParseError;
   }
   
   return result;

}

AST* Parser::expr() {
   return restExpr(term());
}

AST* Parser::restExpr(AST* e) {
  Token* t = scan->getToken();
}

AST* Parser::term() {
  return restTerm(storable());
}

AST* Parser::restTerm(AST* e) {
    Token* t = scan->getToken();

   AST* result = nullptr;

   switch(t->getType()) {
   default:
     scan->putBackToken();
     result = e;
     break;
   }

   return result;
}

AST* Parser::storable() {
 return memOperation(factor());
}

AST* Parser::memOperation(AST* e) {

  AST* result = e;

    Token *t = scan->getToken();

  if (t->getType() == keyword){
    if(t->getLex() == "S") {
      return new StoreNode(result);
    }
    else {
      cout << "* parse error" << endl;
      throw ParseError;
    }
  }

  else {
    scan->putBackToken();
  }
  return result;

}

AST* Parser::factor() {

  AST* result;
  Token* t = scan->getToken();

   if (t->getType() == identifier) {
      istringstream in(t->getLex());
      string val;
      in >> val;
      return new IdNode(val);
   }

      else if(t->getLex() == "C") {
      return new ClearNode();
    }
    else {
      cout << "* Parse error" << endl;
      throw ParseError;
    }
  }

   if (t->getType() == lparen) {
     AST *result = expr();
      t = scan->getToken();
     if (t->getType() != rparen) {
       cout << "* Parse error" << endl;
       throw ParseError;
     }
     return result;
   }

   cerr << "* Parse error" << endl;
   throw ParseError;
}









   
