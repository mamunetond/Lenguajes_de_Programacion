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

IdNode::IdNode(std::string var) :
   AST(),
   var(var)
{}


}

int RecallNode::evaluate() {
  return calc->recall();
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
}
}

ClearNode::ClearNode() :
   AST()
{}

ClearNode::~ClearNode() {}

int ClearNode::evaluate() {
  
}

