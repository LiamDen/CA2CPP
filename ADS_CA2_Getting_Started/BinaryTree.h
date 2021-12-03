#include <iostream>

class BinaryTree
{
public:
	//array
	int count = 0;
	int capacity = 0;

	BinaryTree()
	{
		count = 0;
		capacity = 15;
	}

	BinaryTree(int numLevels) //levels = 3
	{
		count = 0;
		capacity = pow(2, numLevels) - 1;
	}

	~BinaryTree()
	{
		for (int i = 0; i < capacity; i++)
		{
			//set to nullptr
		}

		delete[] dataArray;
		capacity = 0;
		count = 0;;
	}

	void add(int item)
	{
		if (count < capacity)
		{
		}
		else
			throw "Tree must be grown!";
	}

	//print

	//clear

	//count
};
/*
* whatever struct or class that we store in our tree needs to provide some way to compare its data (e.g. student age) with
* the data in a node/cell in the array. therefore, we need to impplement <, >= or <=, > operators for comparison
class Student {
public:
	int age;

	bool operator<=(const Student& rhs);
	bool operator>(const Student& rhs);
	bool operator==(const Student& rhs);
	bool operator!=(const Student& rhs);
};
*/

//
//template <class T>
//class BinaryTree
//{
//public:
//	//array
//	int size = 0;
//
//	BinaryTree();
//	BinaryTree(int numLevels);
//	void add(T item);
//	void remove();
//	~BinaryTree();
//};//
//template<class T>
//inline BinaryTree<T>::BinaryTree()
//{
//}
//
//template<class T>
//inline BinaryTree<T>::BinaryTree(int numLevels)
//{
//}
//
//template<class T>
//inline void BinaryTree<T>::add(T item)
//{
//}
//
//template<class T>
//inline void BinaryTree<T>::remove()
//{
//}
//
//template<class T>
//inline BinaryTree<T>::~BinaryTree()
//{
//}
