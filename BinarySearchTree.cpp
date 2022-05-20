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
		this->removeall(this->root);
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
		removeNode(root, _key);
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
	
	Node<T>* searchMaxNode(Node<T>* cursor)
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
	
	void removeall(Node<T>* cursor)
	{
		while ( cursor != NULL )
		{
			removeall(cursor->left);
			removeall(cursor->right);
			delete cursor;
		}
	}
	
	Node<T>* removeNode(Node<T>* node, T _key)
	{
		if ( node == NULL )
		{
			return node;
		}
		else if ( node->key > _key )
		{
			node->left = removeNode(node->left, _key);
		}
		else if ( node->key < _key )
		{
			node->right = removeNode(node->right, _key);
		}
		else
		{
			Node<T>* cursor = node;
			if ( node->left == NULL && node->right == NULL )
			{
				delete cursor;
				node = NULL;
			}
			else if ( node->right == NULL )
			{
				node = node->left;
				delete cursor;
			}
			else if ( node->left == NULL )
			{
				node = node->right;
				delete cursor;
			}
			else
			{
				cursor = searchMaxNode(node->left);
				node->key = cursor->key;
				node->left = removeNode(node->left, _key);
			}
		}
		
		return node;
	}
	
};

int main(void)
{
	BinarySearchTree<int>* bst = new BinarySearchTree<int> ();
	
	bst->insert(3);
	bst->insert(6);
	bst->insert(7);
	bst->insert(8);
	bst->insert(11);
	bst->insert(9);
	bst->insert(5);
	bst->insert(4);
	
	bst->display();
	
	return 0;
}
