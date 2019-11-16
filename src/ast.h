#pragma once

#include <string>
#include <cstdlib>

using namespace std;

class AST {
 public:
   AST();
   virtual ~AST() = 0;
   virtual int evaluate() = 0;
  

};

class BinaryNode : public AST {
 public:
   BinaryNode(AST* left, AST* right);
   ~BinaryNode();

   AST* getLeftSubTree() const;
   AST* getRightSubTree() const;

 private:
   AST* leftTree;
   AST* rightTree;
};

class UnaryNode : public AST {
 public:
   UnaryNode(AST* sub);
   ~UnaryNode();

   AST* getSubTree() const;

 private:
   AST* subTree;
};


class NumNode : public AST {

public:     //metodos
 NumNode(int n);

   int evaluate();
   string compile();

private:
  int val;

};

class IdNode : public AST {

public:
  IdNode(std::string var);
   int evaluate();
   string compile();

private:
  std::string var;

};

class RecallNode : public AST {

public:     //metodos
   RecallNode();
   int evaluate();
   string compile();

};

class InitVarNode : public UnaryNode {
public:
  InitVarNode(std::string var, AST* sub);
  ~InitVarNode();

  int evaluate();
  string compile();

private:
 std::string var;
};

class StoreNode : public UnaryNode {
public:
  StoreNode(AST* sub);
  ~StoreNode();

  int evaluate();
  string compile();
};

class ClearNode : public AST {
public:
   ClearNode();
  ~ClearNode();

   int evaluate();
  string compile();

};
