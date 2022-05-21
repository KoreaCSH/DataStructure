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
		Node<T>* ptr = root;
		removeNode(ptr, _key);
	}
	
	void display()
	{
		this->inorder(this->root);
	}
	
	void searchMax()
	{
		Node<T>* temp = searchMaxNode(root);
		cout << temp->key << endl;
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
			Node<T>* cursor;
			if ( node->left == NULL && node->right == NULL )
			{
				delete node;
				node = NULL;
			}
			else if ( node->left != NULL && node->right == NULL )
			{
				if ( node == this->root )
				{
					cursor = this->root;
					this->root = this->root->left;
					delete cursor;
					return this->root;
				}
				cursor = node;
				node = node->left;
				delete cursor;
			}
			else if ( node->left == NULL && node->right != NULL )
			{
				if ( node == this->root )
				{
					cursor = this->root;
					this->root = this->root->right;
					delete cursor;
					return this->root;
				}
				cursor = node;
				node = node->right;
				delete cursor;
			}
			else
			{
				if ( node == root )
				{
					cursor = searchMaxNode(node->left);
					this->root->key = cursor->key;
					this->root->left = removeNode(node->left, cursor->key);
					return this->root;
				}
				cursor = searchMaxNode(node->left);
				node->key = cursor->key;
				node->left = removeNode(node->left, cursor->key);
			}
		}
		
		return node;
	}
	
};

int main(void)
{
	BinarySearchTree<int>* bst = new BinarySearchTree<int> ();
	
	bst->insert(5);
	bst->insert(3);
	bst->insert(7);
	bst->insert(2);
	bst->insert(4);
	bst->insert(6);
	bst->insert(8);
	
	bst->display();
	
	bst->search(4);
	bst->search(9);
	
	bst->remove(5);
	bst->remove(4);
	
	bst->display();
	
	return 0;
	
}
