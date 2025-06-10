//****************************************************************************************************
//
//         File:                        BSTDriver.cpp
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
//         This program acts as a driver to test the BinarySearchTree class
//	       
//
//****************************************************************************************************

#include "BinarySearchTree.h"
#include "Stock.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//****************************************************************************************************

int main ()
{
	BinarySearchTree <int> intTree;
	const int MAX = 5000;
	const int MIN = 1;
	unsigned seed = time (0);
	srand (seed);
	int temp;

	BinarySearchTree <Stock> stockTree;
	fstream file ("Stock.txt");
	string name;
	string symbol;
	double price;
	Stock tempStock;
	char choice = 'A';
	Stock * sPtr;

	for ( int i = 0; i < 10; i ++ )
	{
		temp = ( rand () % ( MAX - MIN + 1 ) ) + MIN;
		intTree.insert (temp);
	}

	intTree.preorder ();
	cout << endl;
	intTree.inorder ();
	cout << endl;
	intTree.postorder ();
	cout << endl << "Height: " << intTree.height () << endl << endl;
	intTree.destroy ();

	for ( int i = 0; i < 8; i ++ )
	{
		if ( i > 0 )
		{
			file.ignore ();
		}

		getline (file, name);
		tempStock.setName (name);
		file >> symbol;
		tempStock.setSymbol (symbol);
		file >> price;
		tempStock.setPrice (price);
		stockTree.insert (tempStock);
	}

	while ( ( choice != 'F' ) && ( choice != 'f' ) )
	{
		cout << "A) Display a stock's name given its symbol" << endl;
		cout << "B) Display a stock's price given its symbol" << endl;
		cout << "C) Remove a stock" << endl;
		cout << "D) Insert a new stock" << endl;
		cout << "E) Display all stocks" << endl;
		cout << "F) Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch ( choice )
		{
			case 'A':
			case 'a':
				cout << endl << "Enter the stock symbol: ";
				cin >> symbol;
				tempStock.setSymbol (symbol);
				sPtr = stockTree.search (tempStock);

				if ( sPtr )
				{
					cout << sPtr -> getName () << endl << endl;
				}
				else
				{
					cout << symbol << " is not in the tree." << endl << endl;
				}
				break;
			case 'B':
			case 'b':
				cout << endl << "Enter the stock symbol: ";
				cin >> symbol;
				tempStock.setSymbol (symbol);
				sPtr = stockTree.search (tempStock);

				if ( sPtr )
				{
					cout << "$" << sPtr -> getPrice () << endl << endl;
				}
				else
				{
					cout << symbol << " is not in the tree." << endl << endl;
				}
				break;
			case 'C':
			case 'c':
				cout << endl << "Enter the stock symbol: ";
				cin >> symbol;
				tempStock.setSymbol (symbol);
				stockTree.deleteNode (tempStock);
				cout << symbol << " deleted." << endl << endl;
				break;
			case 'D':
			case 'd':
				cin.ignore ();
				cout << "Enter the stock name: ";
				getline (cin, name);
				tempStock.setName (name);
				cout << "Enter the stock symbol: ";
				cin >> symbol;
				tempStock.setSymbol (symbol);
				cout << "Enter the stock price: ";
				cin >> price;
				tempStock.setPrice (price);
				stockTree.insert (tempStock);
				cout << symbol << " added." << endl << endl;
				break;
			case 'E':
			case 'e':
				stockTree.inorder ();
				cout << endl;
				break;
			case 'F':
			case 'f':
				file << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				stockTree.inorder (file);
				break;
			default:
				cout << "Please enter a valid choice." << endl << endl;
		}
	}

	file.close ();
	return 0;
}

//****************************************************************************************************

/*
2990
88
1293
686
879
2387
3750
3725
3932
4718

88
686
879
1293
2387
2990
3725
3750
3932
4718

879
686
2387
1293
88
3725
4718
3932
3750
2990

Height: 5

A) Display a stock's name given its symbol
B) Display a stock's price given its symbol
C) Remove a stock
D) Insert a new stock
E) Display all stocks
F) Quit

Enter your choice: a

Enter the stock symbol: MSFT
Microsoft Corp.

A) Display a stock's name given its symbol
B) Display a stock's price given its symbol
C) Remove a stock
D) Insert a new stock
E) Display all stocks
F) Quit

Enter your choice: b

Enter the stock symbol: MSFT
$28.11

A) Display a stock's name given its symbol
B) Display a stock's price given its symbol
C) Remove a stock
D) Insert a new stock
E) Display all stocks
F) Quit

Enter your choice: c

Enter the stock symbol: MSFT
MSFT deleted.

A) Display a stock's name given its symbol
B) Display a stock's price given its symbol
C) Remove a stock
D) Insert a new stock
E) Display all stocks
F) Quit

Enter your choice: d
Enter the stock name: Emerson
Enter the stock symbol: EMR
Enter the stock price: 96.64
EMR added.

A) Display a stock's name given its symbol
B) Display a stock's price given its symbol
C) Remove a stock
D) Insert a new stock
E) Display all stocks
F) Quit

Enter your choice: e
Apple                    AAPL      $121.73

Advanced Micro Devices   AMD       $84.51

Emerson                  EMR       $96.64

Intel                    INTC      $60.78

Motorola Inc.            MOT       $17.49

NVIDIA                   NVDA      $548.58

Sony                     SNE       $105.81

Tesla                    TSLA      $564.33


A) Display a stock's name given its symbol
B) Display a stock's price given its symbol
C) Remove a stock
D) Insert a new stock
E) Display all stocks
F) Quit

Enter your choice: f

C:\Users\allis\Dropbox\Computer Science\Data Structures II\Programs\Assignment6\Debug\Assignment6.exe (process 12788) exited with code 0.
Press any key to close this window . . .

*/