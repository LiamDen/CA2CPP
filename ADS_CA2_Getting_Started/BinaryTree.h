#include <iostream>
#include <iomanip> //used for setw() in print()

using namespace std;

/// @brief an example of something we could store in a Node, and hence a BinaryTree
class Student {
public:
	int age;

	Student(int age) : age(age) {
	}
	int getAge() {
		return this->age;
	}

	/// @brief note how we must provide overridden versions of any operators used in the BinaryTree:add()
	bool operator<=(const Student& rhs) {
		return this->age <= rhs.age;
	}

	/// @brief note how we must provide overridden versions of any operators used in the BinaryTree:add()
	bool operator==(const Student& rhs) {
		return this->age == rhs.age;
	}
};

/// @brief another example which is more complex because the measurable value (used for sorting the tree is calculated from w*h*d*volume)
struct AmazonOrder {
public:
	float width, height, depth;
	float priceByVolume; //big volume packages should cost more!

	AmazonOrder() : width(0), height(0), depth(0), priceByVolume(0) {
	}

	AmazonOrder(float width, float height, float depth, float priceByVolume) {
		this->width = width;
		this->height = height;
		this->depth = depth;
		this->priceByVolume = priceByVolume;
	}

	/// @brief note how we must provide overridden versions of any operators used in the BinaryTree:add()
	bool operator<=(const AmazonOrder& rhs) {
		return this->getData() <= rhs.getData();
	}

	/// @brief note how we must provide overridden versions of any operators used in the BinaryTree:add()
	bool operator==(const AmazonOrder& rhs) {
		return this->getData() == rhs.getData();
	}

	/// @brief some internal calculatation to turn all the fields into a single comparable value
	float getData() const {
		return width * height * depth * priceByVolume;
	}
};

/// @brief a node which stores data and is used by the BinaryTree class
class Node {
public:
	int data;

	Node() {};
	Node(int data) : data(data) {};

	/// @brief note how we must provide any overridden operators used in the BinaryTree::add() - see line 136
	//Node y;
	// Node x = y;
	Node& operator=(const Node& rhs)
	{
		//copy
		this->data = rhs.data;

		//return refernce to Node (remember that "this" is a pointer so we must de-reference (using &) and get object)
		return *this;
	}

	/// @brief print the node contents - used in print()!
	friend ostream& operator<<(ostream& os, const Node& node) {
		os << node.data;
		return os;
	}
};

/// @brief a binary tree based on an array implementation
class BinaryTree
{
public:
	//data array
	Node* dataArray;
	int defaultValue;

	int count = 0;
	int capacity = 0;

	/// @brief instantiate and provide a default T so we can clear the array with some default/start value
	BinaryTree(int numLevels, int defaultValue)
	{
		//save the vars
		this->count = 0;
		this->capacity = static_cast<int>(pow(2, numLevels) - 1);
		this->defaultValue = defaultValue;

		//make the array
		dataArray = new Node[capacity];

		//clear initial values
		clear();
	}

	/// @brief free arrar resources
	~BinaryTree()
	{
		delete[] dataArray;
		capacity = 0;
		count = 0;
	}

	/// @brief adds a new item to the tree and grows, if necessary
	void add(int data)
	{
		int position = 0;

		//root node? array[0] != nullptr
		Node currentNode = dataArray[position];

		//if nothing in the array at start position then insert data and return
		if (currentNode.data == this->defaultValue)
		{
			dataArray[position].data = data;
			count++;
			return;
		}
		else
		{
			//keep looking left/right to find an empty array cell
			while (currentNode.data != this->defaultValue)
			{
				//compare new data to currentNode.data
				//note we are doing a <= comparison so whatever the data is (e.g. Student) will need to override the <= operator
				if (data <= currentNode.data)
					position = 2 * position + 1;				//if less, go left
				else
					position = 2 * position + 2; 				//if more, go right

				//check that we dont overrun the end of the array and grow
				if (position >= capacity) {
					Node* grownDataArray = grow(dataArray, capacity, 2 * position);
					//set the new capacity otherwise the print wont show the new grown content
					this->capacity = 2 * position;
					//free the old array
					delete[] dataArray;
					//make dataArray point at new grown array
					dataArray = grownDataArray;

					//we used to just throw an exception but we have grow() so use it!
					//throw "No more space in tree - here is where we call a grow() function!";
				}

				//move down to left/right and repeat until we find an empty node (i.e. data == -1)
				currentNode = dataArray[position];
			}

			//found an empty node on the correct side and so add the data
			dataArray[position].data = data;

			count++;
		}
	}

	/// @brief print
	void print() {
		if (count == 0)
			return;

		for (int i = 0; i < capacity; i++)
			//print the contents and give each row 16 characters - just to make things look nice!
			cout << "[" << std::setw(2) << i << "]| " << std::setw(16) << dataArray[i] << " | " << endl;
	}

	/// @brief clear
	void clear() {
		for (int i = 0; i < capacity; i++)
			dataArray[i] = defaultValue;
	}

	/// @brief get capacity
	int getCount() {
		return this->count;
	}

	/// @brief takes a pointer to the first element in an array of Nodes and grow and return grown node (+ old contents)
	Node* grow(Node* tree, int capacity, int newCapacity)
	{
		if (newCapacity <= capacity)
			throw std::invalid_argument("newCapacity should be at larger than original to grow array!");

		//make the new array
		Node* grown = new Node[newCapacity];

		//copy the data from the original into the grown
		for (int i = 0; i < capacity; i++) {
			grown[i] = tree[i];
		}

		//initialize the unused/unset values in the grown
		for (int i = capacity; i < newCapacity; i++) {
			grown[i] = Node(this->defaultValue);
		}

		return grown;
	}
};