#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <list>
#include <stack>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std; 

// Every vertex in this BST is a C Struct (to expose all its members publicly)
struct BSTVertex {
  // all these attributes remain public to slightly simplify the code although this may not be the best practice
  // BSTVertex* parent; // now removed, all code below thus becomes simpler by a bit
  BSTVertex* left;
  BSTVertex* right;
  int key;
  int height; // will be used in AVL lecture
};

// This is just a sample implementation
// There are other ways to implement BST concepts...
template <typename T1>
class BST {
protected:
  BSTVertex* root;

  BSTVertex* insert(BSTVertex* T, T1 v) {
    if (T == NULL) {                             // insertion point is found
      T = new BSTVertex;
      T->key = v;
      // T->parent = 
      T->left = T->right = NULL;
      T->height = 0;                             // used in AVL lecture
    }
    else if (T->key < v)                         // search to the right
      T->right = insert(T->right, v);
      // T->right->parent = T;
    else                                         // search to the left
      T->left = insert(T->left, v);
      // T->left->parent = T;
    return T;                                    // return the updated BST
  }

  void inorder(BSTVertex* T) {
    if (T == NULL) return;
    inorder(T->left);                            // recursively go to the left
    cout << ' ' << T->key;                       // visit this BST node
    inorder(T->right);                           // recursively go to the right
  }

  void preorder(BSTVertex* T) {
    if (T == NULL) return;
    cout << ' ' << T->key;                       // visit this BST node
    preorder(T->left);                           // recursively go to the left
    preorder(T->right);                          // recursively go to the right
  }

  T1 findMin(BSTVertex* T) {
         if (T == NULL)       return -1;         // BST is empty, no minimum
    else if (T->left == NULL) return T->key;     // this is the min
    else                      return findMin(T->left); // go to the left
  }

  T1 findMax(BSTVertex* T) {
         if (T == NULL)        return -1;        // BST is empty, no maximum
    else if (T->right == NULL) return T->key;    // this is the max
    else                       return findMax(T->right); // go to the right
  }

  BSTVertex* search(BSTVertex* T, T1 v) {
         if (T == NULL)   return NULL;           // not found
    else if (T->key == v) return T;              // found
    else if (T->key < v)  return search(T->right, v); // search to the right
    else                  return search(T->left, v); // search to the left
  }

  T1 successor(BSTVertex* T) {                   // find the successor of T->key
    if (T->right != NULL)                        // we have right subtree
      return findMin(T->right);                  // this is the successor
    else {
      // the one explained in VisuAlgo animation
      // BSTVertex* par = T->parent;
      // BSTVertex* cur = T;
      // // if par(ent) is not root and cur(rent) is its right children
      // while ((par != NULL) && (cur == par->right)) {
      //   cur = par;                            // continue moving up
      //   par = cur->parent;
      // }
      // return par == NULL ? -1 : par->key;     // this is the successor of T

      // the alternative implementation that does NOT use parent pointers
      BSTVertex* succ = NULL;
      BSTVertex* cur = root;                     // start from the root
      while ((cur != NULL) && (cur != T)) {      // search for T
        if (T->key < cur->key) {
          succ = cur;                            // candidate successor
          cur = cur->left;                       // go left
        }
        else
          cur = cur->right;                      // go right
      }
      return succ == NULL ? -1 : succ->key;
    }
  }

  T1 predecessor(BSTVertex* T) {                 // find the predecessor of T->key
    if (T->left != NULL)                         // we have left subtree
      return findMax(T->left);                   // this is the predecessor
    else {
      // the one explained in VisuAlgo animation
      // BSTVertex* par = T->parent;
      // BSTVertex* cur = T;
      // // if par(ent) is not root and cur(rent) is its left children
      // while ((par != NULL) && (cur == par->left)) { 
      //   cur = par;                            // continue moving up
      //   par = cur->parent;
      // }
      // return par == NULL ? -1 : par->key;     // this is the successor of T

      // the alternative implementation that does NOT use parent pointers
      BSTVertex* pred = NULL;
      BSTVertex* cur = root;                     // start from the root
      while ((cur != NULL) && (cur != T)) {      // search for T
        if (T->key < cur->key)
          cur = cur->left;                       // go left
        else {
          pred = cur;                            // candidate predecessor
          cur = cur->right;                      // go right
        }
      }
      return pred == NULL ? -1 : pred->key;
    }
  }

  BSTVertex* remove(BSTVertex* T, T1 v) {
    if (T == NULL) return NULL;                  // cannot find the item

    if (T->key == v) {                           // the node to be deleted
      if ((T->left == NULL) && (T->right == NULL)) { // this is a leaf
        delete T;
        T = NULL;                                // simply erase this node
      }
      else if ((T->left == NULL) && (T->right != NULL)) // only one child at right
        // T->right->parent = T->parent;         // ma, take care of my child
        T = T->right;                            // bypass T
      else if ((T->left != NULL) && (T->right == NULL)) // only one child at left
        // T->left->parent = T->parent;          // ma, take care of my child
        T = T->left;                             // bypass T
      else { // has two children, find the successor of v to avoid quarrel
        int successorV = successor(v);           // predecessor is also OK btw
        T->key = successorV;                     // replace with successorV
        T->right = remove(T->right, successorV); // delete the old successorV
      }
    }
    else if (T->key < v)                         // search to the right
      T->right = remove(T->right, v);
    else                                         // search to the left
      T->left = remove(T->left, v);
    return T;                                    // return the updated BST
  }

  // will be used in AVL lecture
  int getHeight(BSTVertex* T) {
    if (T == NULL) return -1;
    else return max(getHeight(T->left), getHeight(T->right)) + 1;
  }

public:
  BST() { root = NULL; }

  void insert(int v) { root = insert(root, v); }

  void inorder() { inorder(root); cout << '\n'; }

  void preorder() { preorder(root); cout << '\n'; }

  int findMin() { return findMin(root); }

  int findMax() { return findMax(root); }

  int search(T1 v) {
    BSTVertex* res = search(root, v);
    return res == NULL ? -1 : res->key;
  }

  int successor(T1 v) { 
    BSTVertex* vPos = search(root, v);
    return vPos == NULL ? -1 : successor(vPos);
  }

  int predecessor(T1 v) { 
    BSTVertex* vPos = search(root, v);
    return vPos == NULL ? -1 : predecessor(vPos);
  }

  void remove(T1 v) { root = remove(root, v); }

  int getHeight() { return getHeight(root); } // will be used in AVL lecture
  int middle() {
      return 0;
  }


};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    BST<long> bst;
    while (cin >> str) {
        if (str == "#") {
            long middle = bst.middle();
            bst.remove(middle);
            cout << middle << '\n';
        } else {
            long i = stoi(str);
            bst.insert(i);
        }
    }
    
    return 0;
}