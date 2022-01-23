#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H

#include <iostream>
#include <iomanip>   // for printing functionalities
#include <vector>
#include <stdexcept> // for runtime_error
#include <string>

using namespace std;

class TreeExcept : public runtime_error {
    public:
        TreeExcept(const string& msg) : runtime_error(msg) {}
};

template <typename T>
class LinkedBinaryTree {
    public:
        class Node {
            public:
                Node(const T& el);
            public:
                T el;
                Node* parent;
                Node* left;
                Node* right;
                Node() : el(), parent(nullptr), left(nullptr), right(nullptr) {}

            friend class LinkedBinaryTree<T>;
        };
        class Position {
            public:
                Position();
                Position(LinkedBinaryTree<T>::Node* node);
                Position(const Position& pos);
                Position& operator =(const Position& pos);
                bool operator ==(const Position& p) const { return node == p.node; }
                T& operator*();
                T& element() const;
                bool isRoot() const;
                bool isExternal() const;
                bool isInternal() const;
                Position parent() const;
                Position* operator->() { return node; }
                void setParent(Position chNode){ node->parent = chNode.node; } // Set parent
                Position left() const;
                void setLeft(Position chNode){ node->left = chNode.node; }  // Set left child
                Position right() const;
                void setRight(Position chNode){ node->right = chNode.node; } // Set right child

                Position sibling() const;
            private:
                Node* node;
                void copy(const Position& pos);

            friend class LinkedBinaryTree<T>;
        };
        typedef vector<Position> PositionList;
    public:
        LinkedBinaryTree();
        LinkedBinaryTree(const LinkedBinaryTree& tree);
        virtual ~LinkedBinaryTree();
        LinkedBinaryTree& operator =(const LinkedBinaryTree& tree);
        int size() const;
        bool empty() const;
        Position root() const;
        Position setRoot(const T& key);
        void addRoot();
        PositionList& positions() const;
        Position addChild(const Position& parent, const T& el);
        void expandExternal(const Position& p);
        Position removeAboveExternal(const Position& p);
        void print(Node* node, string indent, bool last) const;
        void print() const;
        int height(const Position& pos) const; // TODO: remove
        int depth(const Position& pos) const; // TODO: remove
        Node* setLeft(const Position& pos, const T& el);
        void setRight(const Position& pos, const T& el);
        Position preorderNext(const Position& pos);
        Position postorderNext(const Position& pos);
    protected:
        Node* _root;
        int n;
        void deleteTree(Node* node);
        void copy(const LinkedBinaryTree& tree);
        void preorder(Node* v, PositionList& pl) const;
};

// LinkedBinaryTree default constructor
template <typename T>
LinkedBinaryTree<T>::LinkedBinaryTree() {
    _root = nullptr;
    n = 0;
}

// LinkedBinaryTree destructor
template <typename T>
LinkedBinaryTree<T>::~LinkedBinaryTree() {
    deleteTree(_root);
}

template <typename T>
void LinkedBinaryTree<T>::deleteTree(LinkedBinaryTree<T>::Node* node) {
    if(node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
        node = nullptr;
        n--;
    }
}

template <typename T>
void LinkedBinaryTree<T>::addRoot() {
    _root = new Node;
    n = 1;
}

template <typename T>
void LinkedBinaryTree<T>::expandExternal(const Position& p) {
    // if(p.isExternal()) {
        Node* v = p.node;
        v->left = new Node;
        v->left->parent = v;

        v->right = new Node;
        v->right->parent = v;
        n += 2;
    // }
}

template <typename T>
typename LinkedBinaryTree<T>::PositionList& LinkedBinaryTree<T>::positions() const {
    PositionList pl;
    preorder(_root, pl);
    return pl;
}

template <typename T>
void LinkedBinaryTree<T>::preorder(Node* v, PositionList& pl) const {
    pl.push_back(v);
    if(v->left != nullptr) preorder(v->left, pl);
    if(v->right != nullptr) preorder(v->right, pl);
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::removeAboveExternal(const Position& p) {
    // if(p.isExternal()) {
        Node* w = p.node; Node* v = w->parent;
        Node* sib = (w == v->left ? v->right : v->left);
        if(v == _root) {
            _root = sib;
            sib->parent = nullptr;
        } else {
            Node* u = v->parent;
            if(v == u->left){
                u->left = sib;
            } else {
                u->right = sib;
            }
            sib->parent = u;
        }

        delete w;
        delete v;
        n -= 2;

        return Position(sib);
    // } else {
    //     throw TreeExcept("p is not external");
    // }
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::root() const {
    return Position(_root);
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::setRoot(const T& key) {
    if(_root) {
        throw TreeExcept("root already set!");
    }
    _root = new Node(key);
    n = 1;

    return root();
}

template <typename T>
int LinkedBinaryTree<T>::size() const {
    return n;
}

template <typename T>
bool LinkedBinaryTree<T>::empty() const {
    return size() == 0;
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::addChild(const Position& parent, const T& el) {
    Node* node = new Node(el);
    node->parent = parent.node;
    parent.node->children.push_back(node);
    n++;

    return Position(node);
}

template <typename T>
void LinkedBinaryTree<T>::print(Node* node, string indent, bool last) const {
    // The 0 nodes are the emptry external nodes, only the first level acts as a virtual root
    if (node) {
		   cout<<indent;
		   if (last) {
		      cout<<"R----";
		      indent += "     ";
		   } else {
		      cout<<"L----";
		      indent += "|    ";
		   }
        
		   cout << node->el.key() << endl;
		   print(node->left, indent, false);
		   print(node->right, indent, true);
		}
}

template <typename T>
void LinkedBinaryTree<T>::print() const {
    print(_root, "", true);
}

template <typename T>
int LinkedBinaryTree<T>::height(const Position& pos) const {
    if(pos.isExternal()) {
        return 0;
    }
    return 1 + max(height(pos.node->left), height(pos.node->right));
}

template <typename T>
int LinkedBinaryTree<T>::depth(const Position& pos) const {
    if(pos.isRoot()) {
        return 0;
    }
    return 1 + depth(pos.parent()); 
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::preorderNext(const Position& pos) {
    if (pos.left().node) {
        return pos.left();
    } else if(pos.parent().left().node == pos.node) {
        return pos.parent().right();
    } else {
        Position curr = pos.parent();
        while(true) {
            if(curr.node == _root) {
                throw TreeExcept("No Successor of this element");
            } else if(curr.parent().left().node == curr.node) {
                return curr.parent().right();
            }
            curr = curr.parent();
        }
    }
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::postorderNext(const Position& pos) {
    if(pos.node == _root) {
        throw TreeExcept("No Successor of this element");
    } else if(pos.node == pos.parent().right().node) {
        return pos.parent();
    } else {
        if(pos.parent().right().left().node) {
            Position curr = pos.parent().right().left();
            while(curr.left().node) {
                curr = curr.left();
            }
            return curr;
        } else {
            return pos.parent().right();
        }
    }
}

template <typename T>
LinkedBinaryTree<T>::LinkedBinaryTree(const LinkedBinaryTree& tree) {
    copy(tree);
}

template <typename T>
LinkedBinaryTree<T>& LinkedBinaryTree<T>::operator =(const LinkedBinaryTree& tree) {
    copy(tree);
}

template <typename T>
void LinkedBinaryTree<T>::copy(const LinkedBinaryTree& tree) {
    _root = tree._root;
    n = tree.n;
}

// Position default constructor
template <typename T>
LinkedBinaryTree<T>::Position::Position() {
    node = nullptr;
}

// Position parameter constructor
template <typename T>
LinkedBinaryTree<T>::Position::Position(LinkedBinaryTree<T>::Node* node) {
   this->node = node;
}

// Position copy constructor
template <typename T>
LinkedBinaryTree<T>::Position::Position(const Position& pos) {
   copy(pos);
}

// Position = overloaded
template <typename T>
typename LinkedBinaryTree<T>::Position& LinkedBinaryTree<T>::Position::operator =(const Position& pos) {
    copy(pos);
    return *this;
}

// Position checks isRoot
template <typename T>
bool LinkedBinaryTree<T>::Position::isRoot() const {
    if(!node) {
        throw TreeExcept("No node!");
    }
    return (node->parent == nullptr);
}

// Position checks isExternal
template <typename T>
bool LinkedBinaryTree<T>::Position::isExternal() const {
    if(!node) {
        throw TreeExcept("No node!");
    }
    return (node->left == nullptr && node->right == nullptr);
}

template <typename T>
bool LinkedBinaryTree<T>::Position::isInternal() const {
    if(!node) {
        throw TreeExcept("No node!");
    }
    return (node->left != nullptr && node->right != nullptr);
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::Position::parent() const {
    if(!node) {
        throw TreeExcept("Access null position");
    }
    if(!node->parent) {
        cout << node->el.value() << endl;
        throw TreeExcept("Access null parent");
    }
    return Position(node->parent);
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::Position::left() const {
    if(!node) {
        throw TreeExcept("Access null position");
    }
    return Position(node->left);
}

template <typename T>
typename LinkedBinaryTree<T>::Node* LinkedBinaryTree<T>::setLeft(const typename LinkedBinaryTree<T>::Position& pos, const T& el) {
    if(pos.node->left) {
        throw TreeExcept("Left child already set");
    }
    pos.node->left = new Node(el);
    pos.node->left->parent = pos.node;
    n++;

    return pos.node->left;
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::Position::right() const {
    return Position(node->right);
}

template <typename T>
void LinkedBinaryTree<T>::setRight(const typename LinkedBinaryTree<T>::Position& pos, const T& el) {
    if(pos.node->right) {
        throw TreeExcept("Right child already set");
    }
    pos.node->right = new Node(el);
    pos.node->right->parent = pos.node;
    n++;
}

template <typename T>
T& LinkedBinaryTree<T>::Position::operator *() {
    if(!node) {
        throw TreeExcept("Dereference null position");
    }
    return node->el;
}

template <typename T>
T& LinkedBinaryTree<T>::Position::element() const {
    if(!node) {
        throw TreeExcept("Dereference null position");
    }
    return node->el;
}

// Position copy
template <typename T>
void LinkedBinaryTree<T>::Position::copy(const Position& pos) {
    this->node = pos.node;
}

// Node constructor
template <typename T>
LinkedBinaryTree<T>::Node::Node(const T& el) {
    this->el = el;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}


#endif