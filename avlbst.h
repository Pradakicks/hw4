#ifndef AVLBST_H
#define AVLBST_H

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <exception>
#include <iostream>

#include "bst.h"

struct KeyError {};

/**
 * A special kind of node for an AVL tree, which adds the balance as a data
 * member, plus other additional helper functions. You do NOT need to implement
 * any functionality or add additional data members or helper functions.
 */
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value> {
 public:
  // Constructor/destructor.
  AVLNode(const Key &key, const Value &value, AVLNode<Key, Value> *parent);
  virtual ~AVLNode();

  // Getter/setter for the node's height.
  int8_t getBalance() const;
  void setBalance(int8_t balance);
  void updateBalance(int8_t diff);

  // Getters for parent, left, and right. These need to be redefined since they
  // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
  // for more information.
  virtual AVLNode<Key, Value> *getParent() const override;
  virtual AVLNode<Key, Value> *getLeft() const override;
  virtual AVLNode<Key, Value> *getRight() const override;

 protected:
  int8_t balance_;  // effectively a signed char
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
 * An explicit constructor to initialize the elements by calling the base class
 * constructor
 */
template <class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key &key, const Value &value,
                             AVLNode<Key, Value> *parent)
    : Node<Key, Value>(key, value, parent), balance_(0) {}

/**
 * A destructor which does nothing.
 */
template <class Key, class Value>
AVLNode<Key, Value>::~AVLNode() {}

/**
 * A getter for the balance of a AVLNode.
 */
template <class Key, class Value>
int8_t AVLNode<Key, Value>::getBalance() const {
  return balance_;
}

/**
 * A setter for the balance of a AVLNode.
 */
template <class Key, class Value>
void AVLNode<Key, Value>::setBalance(int8_t balance) {
  balance_ = balance;
}

/**
 * Adds diff to the balance of a AVLNode.
 */
template <class Key, class Value>
void AVLNode<Key, Value>::updateBalance(int8_t diff) {
  balance_ += diff;
}

/**
 * An overridden function for getting the parent since a static_cast is
 * necessary to make sure that our node is a AVLNode.
 */
template <class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const {
  return static_cast<AVLNode<Key, Value> *>(this->parent_);
}

/**
 * Overridden for the same reasons as above.
 */
template <class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const {
  return static_cast<AVLNode<Key, Value> *>(this->left_);
}

/**
 * Overridden for the same reasons as above.
 */
template <class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const {
  return static_cast<AVLNode<Key, Value> *>(this->right_);
}

/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/

template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value> {
 public:
  virtual void insert(const std::pair<const Key, Value> &new_item);  // TODO
  virtual void remove(const Key &key);                               // TODO
 protected:
  virtual void nodeSwap(AVLNode<Key, Value> *n1, AVLNode<Key, Value> *n2);

  // Add helper functions here
  virtual void insertFix(AVLNode<Key, Value> *p, AVLNode<Key, Value> *n);
  virtual void removeFix(AVLNode<Key, Value> *p, int diff);
  virtual void rotateLeft(AVLNode<Key, Value> *currN);
  virtual void rotateRight(AVLNode<Key, Value> *currN);
};

/*
 * Recall: If key is already in the tree, you should
 * overwrite the current value with the updated value.
 */
template <class Key, class Value>
void AVLTree<Key, Value>::insert(const std::pair<const Key, Value> &new_item) {
  if (this->root_ == NULL) {
    this->root_ =
        new AVLNode<Key, Value>(new_item.first, new_item.second, nullptr);
  } else {
    AVLNode<Key, Value> *curr = static_cast<AVLNode<Key, Value> *>(
        this->root_);  // Verify if this is okay to do
    while (curr) {
      if (curr->getKey() == new_item.first) {
        curr->setValue(new_item.second);
        return;
      } else if (curr->getKey() > new_item.first) {
        if (curr->getLeft()) {
          curr = curr->getLeft();
        } else {
          AVLNode<Key, Value> *newNode =
              new AVLNode<Key, Value>(new_item.first, new_item.second, curr);
          //   t->setBalance(0);
          curr->setLeft(newNode);
          if (curr->getBalance() == -1 || curr->getBalance() == 1) {
            curr->setBalance(0);
          } else {
            curr->setBalance(-1);
            insertFix(curr, newNode);
          }
          return;
        }
      } else {
        if (curr->getRight()) {
          curr = curr->getRight();
        } else {
          AVLNode<Key, Value> *newNode =
              new AVLNode<Key, Value>(new_item.first, new_item.second, curr);
          //   t->setBalance(0);
          curr->setRight(newNode);
          if (curr->getBalance() == -1 || curr->getBalance() == 1) {
            curr->setBalance(0);
          } else {
            curr->setBalance(1);
            insertFix(curr, newNode);
          }
          return;
        }
      }
    }
  }
}

template <class Key, class Value>
void AVLTree<Key, Value>::insertFix(AVLNode<Key, Value> *p,
                                    AVLNode<Key, Value> *n) {
  if (p == nullptr || p->getParent() == nullptr) return;

  AVLNode<Key, Value> *g = p->getParent();

  if (g->getLeft() == p) {
    g->setBalance(g->getBalance() - 1);

    switch (g->getBalance()) {
      case 0:
        break;
      case -1:
        insertFix(g, p);
        break;
      case -2:
        //  ToDo
        // Since we assume p is left child g , we only need to check if n is
        // left of p for zig zig
        if (p->getLeft() == n) {
          rotateRight(g);
          g->setBalance(0);
          p->setBalance(0);
        } else {
          rotateLeft(p);
          rotateRight(g);
          switch (n->getBalance()) {
            case -1:
              p->setBalance(0);
              g->setBalance(1);
              n->setBalance(0);
              break;
            case 0:
              p->setBalance(0);
              g->setBalance(0);
              n->setBalance(0);
              break;
            case 1:
              p->setBalance(-1);
              g->setBalance(0);
              n->setBalance(0);
              break;
            default:
              break;
          }
        }
      default:
        break;
    }
  } else {
    g->setBalance(g->getBalance() + 1);

    switch (g->getBalance()) {
      case 0:
        break;
      case 1:
        insertFix(g, p);
        break;
      case 2:
        if (p->getRight() == n) {
          rotateLeft(g);
          g->setBalance(0);
          p->setBalance(0);
        } else {
          rotateRight(p);
          rotateLeft(g);
          switch (n->getBalance()) {
            case 1:
              p->setBalance(0);
              g->setBalance(-1);
              n->setBalance(0);
              break;
            case 0:
              p->setBalance(0);
              g->setBalance(0);
              n->setBalance(0);
              break;
            case -1:
              p->setBalance(1);
              g->setBalance(0);
              n->setBalance(0);
              break;
            default:
              break;
          }
        }
      default:
        break;
    }
  }
}

template <class Key, class Value>
void AVLTree<Key, Value>::rotateLeft(AVLNode<Key, Value> *currN) {
  if (currN == nullptr || currN->getRight() == nullptr) return;
  AVLNode<Key, Value> *rightChild = currN->getRight();

  currN->setRight(rightChild->getLeft());
  if (rightChild->getLeft()) {
    currN->getRight()->setParent(currN);
  }

  rightChild->setParent(currN->getParent());
  if (currN->getParent() == nullptr) {
    this->root_ = rightChild;
  } else if (currN->getParent()->getLeft() == currN) {
    currN->getParent()->setLeft(rightChild);
  } else {
    currN->getParent()->setRight(rightChild);
  }

  currN->setParent(rightChild);
  rightChild->setLeft(currN);
  return;
}

template <class Key, class Value>
void AVLTree<Key, Value>::rotateRight(AVLNode<Key, Value> *currN) {
  if (currN == nullptr || currN->getLeft() == nullptr) return;
  AVLNode<Key, Value> *leftChild = currN->getLeft();

  currN->setLeft(leftChild->getRight());
  if (leftChild->getRight()) {
    currN->getLeft()->setParent(currN);
  }

  leftChild->setParent(currN->getParent());
  if (currN->getParent() == nullptr) {
    this->root_ = leftChild;
  } else if (currN->getParent()->getRight() == currN) {
    currN->getParent()->setRight(leftChild);
  } else {
    currN->getParent()->setLeft(leftChild);
  }

  currN->setParent(leftChild);
  leftChild->setRight(currN);
  return;
}

/*
 * Recall: The writeup specifies that if a node has 2 children you
 * should swap with the predecessor and then remove.
 */
template <class Key, class Value>
void AVLTree<Key, Value>::remove(const Key &key) {
  AVLNode<Key, Value> *node =
      static_cast<AVLNode<Key, Value> *>(this->internalFind(key));
  if (node) {
    if (node->getRight() && node->getLeft()) {
      nodeSwap(node,
               static_cast<AVLNode<Key, Value> *>(this->predecessor(node)));
    }

    AVLNode<Key, Value> *p = node->getParent();
    int diff = 0;
    if (p != nullptr) {
      if (p->getLeft() == node) {
        diff = 1;
      } else {
        diff = -1;
      }
    }
    if (!node->getLeft() && !node->getRight()) {
      if (this->root_ == node) {
        delete this->root_;
        this->root_ = nullptr;
        return;
      } else {
        this->removeNode(node);
      }
    } else {
      // We assume its one child left
      // because we wouldve already
      // swapped with predecessor
      this->removeOneChildNode(node);
    }

    removeFix(p, diff);
  }
}

template <class Key, class Value>
void AVLTree<Key, Value>::removeFix(AVLNode<Key, Value> *node, int diff) {
  if (node) {
    AVLNode<Key, Value> *p = node->getParent();
    int ndiff = 0;
    if (p) {
      if (p->getLeft() == node) {
        ndiff = 1;
      } else {
        ndiff = -1;
      }
    } else {
      std::cout << "OTHER DEBUGGER!!!" << std::endl;
    }

    if (diff == -1) {
      int currBalance = node->getBalance() + diff;
      switch (currBalance) {
        case -2: {
          AVLNode<Key, Value> *c = node->getLeft();
          switch (c->getBalance()) {
            case -1: {
              rotateRight(node);
              node->setBalance(0);
              c->setBalance(0);
              removeFix(p, ndiff);
              break;
            }
            case 0: {
              rotateRight(node);
              node->setBalance(-1);
              c->setBalance(1);
              break;
            }
            case 1: {
              AVLNode<Key, Value> *g = c->getRight();
              rotateLeft(c);
              rotateRight(node);
              switch (g->getBalance()) {
                case 1: {
                  node->setBalance(0);
                  c->setBalance(-1);
                  g->setBalance(0);
                  break;
                }
                case 0: {
                  node->setBalance(0);
                  c->setBalance(0);
                  g->setBalance(0);
                  break;
                }
                case -1: {
                  node->setBalance(1);
                  c->setBalance(0);
                  g->setBalance(0);
                  break;
                }
              }
              removeFix(p, ndiff);
              break;
            }
          }
          break;
        }
        case -1: {
          node->setBalance(-1);
          break;
        }
        case 0: {
          node->setBalance(0);
          removeFix(p, ndiff);
          break;
        }
      }
    } else if (diff == 1) {
      int currBalance = node->getBalance() + diff;
      switch (currBalance) {
        case 2: {
          AVLNode<Key, Value> *c = node->getRight();
          switch (c->getBalance()) {
            case 1: {
              rotateLeft(node);
              node->setBalance(0);
              c->setBalance(0);
              removeFix(p, ndiff);
              break;
            }
            case 0: {
              rotateLeft(node);
              node->setBalance(1);
              c->setBalance(-1);
              break;
            }
            case -1: {
              AVLNode<Key, Value> *g = c->getLeft();
              rotateRight(c);
              rotateLeft(node);

              switch (g->getBalance()) {
                case -1: {
                  node->setBalance(0);
                  c->setBalance(1);
                  g->setBalance(0);
                  break;
                }
                case 0: {
                  node->setBalance(0);
                  c->setBalance(0);
                  g->setBalance(0);
                  break;
                }
                case 1: {
                  node->setBalance(-1);
                  c->setBalance(0);
                  g->setBalance(0);
                  break;
                }
              }
              removeFix(p, ndiff);
              break;
            }
          }
          break;
        }
        case 1: {
          node->setBalance(1);
          break;
        }
        case 0: {
          node->setBalance(0);
          removeFix(p, ndiff);
          break;
        }
      }
    }
  }
}

template <class Key, class Value>
void AVLTree<Key, Value>::nodeSwap(AVLNode<Key, Value> *n1,
                                   AVLNode<Key, Value> *n2) {
  BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
  int8_t tempB = n1->getBalance();
  n1->setBalance(n2->getBalance());
  n2->setBalance(tempB);
}

#endif
