
template <typename T>
bool hasPairsOfPredecessorNSuccessor(DNode<T>* PPSNodes) {
  // Check if the input node is null or if it is the first or last node in the list
  if (!PPSNodes || !PPSNodes->prev || !PPSNodes->next) return false;

  // Otherwise, the node has a pair of predecessor and successor nodes
  return true;
};
