// ADS_CA2_Getting_Started.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ADS_CA2_Getting_Started.h"
#include "BinaryTree.h"

void demoSimpleArrayedBinaryTree();
void demoPointerArrayedBinaryTree();

int main()
{
	demoSimpleArrayedBinaryTree();

	demoPointerArrayedBinaryTree();
}

void demoPointerArrayedBinaryTree()
{
	int length = 20;
	Node* tree[20];

	for (int i = 0; i < length; i++) {
		tree[i] = nullptr;
	}

	//add new data
	int data = 20;
	int position = 0;

	//find the parent node
	auto currentNode = tree[position];

	//no parent
	if (currentNode == nullptr)
	{
		Node n(20);
		currentNode = &n;
	}
}

void demoSimpleArrayedBinaryTree()
{
	int length = 20;
	Node tree[20];
	Node grown[40];

	for (int i = 0; i < 20; i++) {
		grown[i] = tree[i];
	}

	for (int i = 20; i < 40; i++) {
		grown[i] = Node();
	}

	for (int i = 0; i < length; i++) {
		tree[i] = Node();
	}

	//if less, look for left child
	//else if more, look for right child

	//add new data
	int data = 20;
	int position = 0;

	//find the parent node
	auto currentNode = tree[position];

	//no parent
	if (currentNode.data == -1)
	{
		currentNode.data = 20;
	}
	else
	{
		//if yes, compare data to parent
		if (data <= currentNode.data)
		{
			//calculate the left node position
			position = 2 * position + 1;

			//check position >= capacity
			//throw an exception and replace with grow()

			//set left as new current
			currentNode = tree[position];
			if (currentNode.data == -1)
			{
				currentNode.data = data;
			}
		}
		else
		{
			position = 2 * position + 2;

			//check position >= capacity
			//throw an exception and replace with grow()

			//set left as new current
			currentNode = tree[position];
			if (currentNode.data == -1)
			{
				currentNode.data = data;
			}
		}
	}
}