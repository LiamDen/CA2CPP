// 2021 - CA3 - Project - Q1 - BinaryTree

#include <iostream>
#include <exception>
#include "ADS_CA2_Getting_Started.h"
#include "BinaryTree.h"

void demoPointerArrayedBinaryTreeInts();

int main()
{
	cout << endl << "ADS - 2021 - CA - Binary Tree..." << endl;

	cout << endl << "demoPointerArrayedBinaryTreeInts()..." << endl;
	demoPointerArrayedBinaryTreeInts();

	cout << endl << "Done..." << endl;
}

void demoPointerArrayedBinaryTreeInts()
{
	//levels = 3, therefore capacity = 2^levels - 1 = 2^3 - 1 = 8 - 1 = 7
	BinaryTree myTree(3, -1);

	myTree.add(2);
	myTree.add(4);
	myTree.add(3);
	myTree.add(1);
	myTree.add(5);
	myTree.print();

	//once we make a template version of the BinaryTree<T> then we can add all sorts of items as long as they have some numeric quality (to use to go left/right on the tree)
	//AmazonOrder defaultOrder;
	//BinaryTree<AmazonOrder> amazonTree(4, defaultOrder);
	//amazonTree.add(AmazonOrder(0.8, 0.2, 1.5, 9.99));
	//amazonTree.add(4);
	//amazonTree.add(3);
	//amazonTree.add(1);
	//amazonTree.add(5);
	//amazonTree.print();
}