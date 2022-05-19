#include <iostream>

using namespace std;

template<typename T>
class Node {
public:
	Node<T>* left;
	Node<T>* right;
	T key;
	
	Node(T _key)
	{
		this->key = _key;
		this->left = NULL;
		this->right = NULL;
	}
};

template<typename T>
class BinarySearchTree {
public:
	BinarySearchTree()
	{
		root = NULL;
	}
	
	~BinarySearchTree()
	{
		
	}
	
	bool search(T _key)
	{
		Node<T>* cursor = root;
		
		while ( cursor != NULL )
		{
			if ( cursor->key == _key )
			{
				cout << _key << "를 찾음." << endl;
				return true;
			}
			else if ( cursor->key > _key )
			{
				cursor = cursor->left;
			}
			else
			{
				cursor = cursor->right;
			}
		}
		
		cout << _key << "를 찾지 못함." << endl;
		return false;
	}
	
	void insert(T _key)
	{
		if ( root == NULL )
		{
			root = new Node<T>(_key);
		}
		else
		{
			Node<T>* cursor = root;
			Node<T>* newNode = new Node<T>(_key);
			Node<T>* temp;
			while ( cursor != NULL )
			{
				temp = cursor;
				if ( newNode->key < cursor->key )
				{
					cursor = cursor->left;
				}
				else
				{
					cursor = cursor->right;
				}
			}
			if ( newNode->key < temp->key )
			{
				temp->left = newNode;
			}
			else
			{
				temp->right = newNode;
			}
		}
	}
	
	void remove(T _key)
	{
		
		
	}
	
	void display()
	{
		this->inorder();
	}
	
private:
	
	Node<T>* root;
	
	void inorder(Node<T>* cursor)
	{
		if ( cursor != NULL )
		{
			inorder(cursor->left);
			cout << cursor->key << " " << endl;
			inorder(cursor->right);
		}
	}
	
	Node<T>* searchMinNode(Node<T>* cursor)
	{
		if ( cursor == NULL )
		{
			return NULL;
		}
		
		while ( cursor->right != NULL )
		{
			cursor = cursor->right;
		}
		return cursor;
	}
	
};

int main(void)
{
	
	
}
