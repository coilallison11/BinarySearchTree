//****************************************************************************************************
//
//         File:                        BinarySearchTree.h
//
//         Student:                     Allison Coil
//
//         Assignment:                  Assignment #6
//
//         Course Name:                 Data Structures   II
//
//         Course Number:               COSC 3100 - 01
//
//         Due:                         Oct 11, 2021
//
//
//         This class holds a binary search tree made up of nodes of an unknown data type.
//	       
//
//****************************************************************************************************

#include "Node.h"
#include <iostream>

//****************************************************************************************************

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

//****************************************************************************************************

template <typename TYPE>
class BinarySearchTree
{
	private:
		Node <TYPE> * root;
		void destroy (Node <TYPE> *& r);
		void insert (Node <TYPE> *& r, const TYPE & item);
		void inorder (std::ostream & os, Node <TYPE> * r) const;
		void preorder (std::ostream & os, Node <TYPE> * r) const;
		void postorder (std::ostream & os, Node <TYPE> * r) const;
		void searchD (const TYPE & item, bool & found, Node <TYPE> *& locPtr, Node <TYPE> *& parent) const;
		TYPE * search (Node <TYPE> * r, const TYPE & item) const;
		int height (Node <TYPE> * r) const;
		int max (int a, int b) const;

	public:
		BinarySearchTree ();
		~BinarySearchTree ();
		void destroy ();
		void insert (const TYPE & item);
		void inorder (std::ostream & os = std::cout) const;
		void preorder (std::ostream & os = std::cout) const;
		void postorder (std::ostream & os = std::cout) const;
		void deleteNode (const TYPE & item);
		TYPE * search (const TYPE & item) const;
		int height () const;
};

//****************************************************************************************************

template <typename TYPE> 
BinarySearchTree <TYPE> :: BinarySearchTree ()
{
	root = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
BinarySearchTree <TYPE> :: ~BinarySearchTree ()
{
	destroy (root);
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree <TYPE> :: destroy ()
{
	destroy (root);
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree <TYPE> :: destroy (Node <TYPE> *& r)
{
	if ( r )
	{
		destroy (r -> left);
		destroy (r -> right);
		delete r;
		r = nullptr;
	}
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree <TYPE> :: insert (const TYPE & item)
{
	insert (root, item);
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree <TYPE> :: insert (Node <TYPE> *& r, const TYPE & item)
{
	if ( ! r )
	{
		r = new Node <TYPE> (item);
	}
	else if ( item < r -> value )
	{
		insert (r -> left, item);
	}
	else if ( item > r -> value )
	{
		insert (r -> right, item);
	}
	else
	{
		std::cout << "Duplicate" << std::endl;
	}
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree <TYPE> :: inorder (std::ostream & os) const
{
	inorder (os, root);
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree <TYPE> :: inorder (std::ostream & os, Node <TYPE> * r) const
{
	if ( r )
	{
		inorder (os, r -> left);
		os << r -> value << std::endl;
		inorder (os, r -> right);
	}
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree <TYPE> :: preorder (std::ostream & os) const
{
	preorder (os, root);
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree <TYPE> :: preorder (std::ostream & os, Node <TYPE> * r) const
{
	if ( r )
	{
		os << r -> value << std::endl;
		preorder (os, r -> left);
		preorder (os, r -> right);
	}
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree <TYPE> :: postorder (std::ostream & os) const
{
	postorder (os, root);
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree <TYPE> :: postorder (std::ostream & os, Node <TYPE> * r) const
{
	if ( r )
	{
		postorder (os, r -> left);
		postorder (os, r -> right);
		os << r -> value << std::endl;
	}
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree <TYPE> :: searchD (const TYPE & item, bool & found, Node <TYPE> *& locPtr, Node <TYPE> *& parent) const
{
	locPtr = root;
	parent = nullptr;
	found = false;

	while ( ( ! found ) && ( locPtr ) )
	{
		if ( item < locPtr -> value )
		{
			parent = locPtr;
			locPtr = locPtr -> left;
		}
		else if ( item > locPtr -> value )
		{
			parent = locPtr;
			locPtr = locPtr -> right;
		}
		else
		{
			found = true;
		}
	}
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree <TYPE> :: deleteNode (const TYPE & item)
{
	Node <TYPE> * current;
	Node <TYPE> * parent;
	bool found;

	searchD (item, found, current, parent);

	if ( ! found )
	{
		std::cout << "Item not in tree." << std::endl;
	}
	else
	{
		if ( ( current -> left ) && ( current -> right ) )
		{
			Node <TYPE> * currentSucc = current -> right;
			parent = current;

			while ( currentSucc -> left )
			{
				parent = currentSucc;
				currentSucc = currentSucc -> left;
			}

			current -> value = currentSucc -> value;
			current = currentSucc;
		}

		Node <TYPE> * subtree = current -> left;

		if ( ! subtree )
		{
			subtree = current -> right;
		}

		if ( ! parent )
		{
			root = subtree;
		}
		else if ( parent -> left == current )
		{
			parent -> left = subtree;
		}
		else
		{
			parent -> right = subtree;
		}

		delete current;
	}
}

//****************************************************************************************************

template <typename TYPE>
TYPE * BinarySearchTree <TYPE> :: search (const TYPE & item) const
{
	return search (root, item);
}

//****************************************************************************************************

template <typename TYPE>
TYPE * BinarySearchTree <TYPE> :: search (Node <TYPE> * r, const TYPE & item) const
{
	TYPE * result = nullptr;

	if ( r )
	{
		if ( item < r -> value )
		{
			result = search (r -> left, item);
		}
		else if ( item > r -> value )
		{
			result = search (r -> right, item);
		}
		else
		{
			result = &(r -> value);
		}
	}

	return result;
}

//****************************************************************************************************

template <typename TYPE>
int BinarySearchTree <TYPE> :: height () const
{
	return height (root);
}

//****************************************************************************************************

template <typename TYPE>
int BinarySearchTree <TYPE> :: height (Node <TYPE> * r) const
{
	if ( ! r )
	{
		return 0;
	}
	else
	{
		return 1 + max (height (r -> left), height (r -> right));
	}
}

//****************************************************************************************************

template <typename TYPE>
int BinarySearchTree <TYPE> :: max (int a, int b) const
{
	int result;

	if ( a > b )
	{
		result = a;
	}
	else
	{
		result = b;
	}

	return result;
}

//****************************************************************************************************

#endif