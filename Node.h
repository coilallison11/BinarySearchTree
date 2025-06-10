//****************************************************************************************************
//
//         File:                        Node.h
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
//         This structure creates a single node for use in a binary search tree. It holds data of
//		   an unknown type as well as the address of its right child node and the address of
//		   its left child node.
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE value;
	Node <TYPE> * left;
	Node <TYPE> * right;

	Node ();
	Node (TYPE v, Node <TYPE> * l = nullptr, Node <TYPE> * r = nullptr);
};

//****************************************************************************************************

template <typename TYPE>
Node <TYPE> ::Node ()
{
	value = 0;
	left = nullptr;
	right = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
Node <TYPE> ::Node (TYPE d, Node <TYPE> * l, Node <TYPE> * r)
{
	value = d;
	left = l;
	right = r;
}

//****************************************************************************************************

#endif