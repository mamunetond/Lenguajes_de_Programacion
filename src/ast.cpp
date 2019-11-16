#include "ast.h"
#include <iostream>
#include <sstream>
#include <ostream>
#include <fstream>
#include <cstdlib>

// for debug information uncomment
//#define debug

AST::AST() {}

AST::~AST() {}

BinaryNode::BinaryNode(AST* left, AST* right):
   AST(),
   leftTree(left),
   rightTree(right)
{}

BinaryNode::~BinaryNode() {
#ifdef debug
   cout << "In BinaryNode destructor" << endl;
#endif

   try {
      delete leftTree;
   } catch (...) {}

   try {
      delete rightTree;
   } catch(...) {}
}
   
AST* BinaryNode::getLeftSubTree() const {
   return leftTree;
}

AST* BinaryNode::getRightSubTree() const {
   return rightTree;
}

UnaryNode::UnaryNode(AST* sub):
   AST(),
   subTree(sub)
{}

UnaryNode::~UnaryNode() {
#ifdef debug
   cout << "In UnaryNode destructor" << endl;
#endif

   try {
      delete subTree;
   } catch (...) {}
}
   
AST* UnaryNode::getSubTree() const {
   return subTree;
}

AddNode::AddNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int AddNode::evaluate() {
   return getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
}

s

IdNode::IdNode(std::string var) :
   AST(),
   var(var)
{}

int IdNode::evaluate() {
  if(calc->containVar(var))
    return calc->getVar(var);
  else
    calc->setVar(var, 0);
    return 0;
}

string IdNode::compile() {

  string line = "";
  evaluate();
  return line + "\n# VarNode \n"+
         "M[SP+0] := " + var + "\n"+
         "SP := SP - UNO \n";
}


RecallNode::RecallNode() :
   AST()
{}

int RecallNode::evaluate() {
  return calc->recall();
}

 string RecallNode::compile() {

  string line = "";
  return line + "\n# RecallNode \n"+         
         "SP      := SP + UNO \n"+
         "M[SP+1] := MEMORY \n";
}

InitVarNode::InitVarNode(std::string var, AST* sub) : UnaryNode(sub), var(var) {}

InitVarNode::~InitVarNode() {}

int InitVarNode::evaluate(){

  calc->setVar(var, getSubTree()->evaluate());
  return calc->getVar(var);
}

StoreNode::StoreNode(AST *sub) : UnaryNode(sub) { }

StoreNode::~StoreNode() {}

int StoreNode::evaluate() {
  int result = getSubTree()->evaluate();
  calc->store(result);
    
}
}

ClearNode::ClearNode() :
   AST()
{}

ClearNode::~ClearNode() {}

int ClearNode::evaluate() {
  return calc->clear();
}
PlusNode::PlusNode(AST *sub) : UnaryNode(sub) { }

PlusNode::~PlusNode() {}

int PlusNode::evaluate() {
  calc->plus(getSubTree()->evaluate());
  return calc->recall();  
}
