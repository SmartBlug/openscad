#ifndef TRAVERSER_H_
#define TRAVERSER_H_

enum Response {ContinueTraversal, AbortTraversal, PruneTraversal};

class Traverser
{
public:
  enum TraversalType {PREFIX, POSTFIX, PRE_AND_POSTFIX};

  Traverser(class Visitor &visitor, const class AbstractNode &root, TraversalType travtype)
		: visitor(visitor), root(root), traversaltype(travtype) {
  }
  virtual ~Traverser() { }
  
  void execute();
private:
  // FIXME: reverse parameters
  void traverse(const class State &state, const AbstractNode &node);

  Visitor &visitor;
  const AbstractNode &root;
  TraversalType traversaltype;
};

#endif
