#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

template <class KeyType, class ValType>
class MapElem
{
public:
	typedef KeyType ktype;
	typedef ValType vtype;
	
	KeyType key;
	ValType val;
	
	MapElem* link;
};

template <class HashMapElemType>
class HashMap
{
public:
	typedef typename HashMapElemType::ktype KeyType;
	typedef typename HashMapElemType::vtype ValType;
	
	HashMap(unsigned int c = 1000)
	{
		mapsize = 0;
		capacity = c;
		divisor = c - ( 1-c%2 );
		ht = new HashMapElemType* [capacity];
		for ( int i = 0 ; i < capacity ; i++ ) ht[i] = NULL;
	}
	
	~HashMap()
	{
		for ( int i = 0 ; i < capacity; i++ )
		{
			HashMapElemType* delNode = ht[i];
			HashMapElemType* temp;
			if ( delNode != NULL )
			{
				temp = delNode->link;
				delete delNode;
				while ( temp != NULL )
				{
					delNode = temp;
					temp = temp->link;
					delete delNode;
				}
				
			}
		}
		delete[] ht;
	}
	
	int size() 
	{
		return mapsize;
	}
	
	bool isEmpty()
	{
		return (mapsize == 0);
	}
	
	HashMapElemType* find(const KeyType k)
	{
		int hash_val = hashfunction(k);
		HashMapElemType* cursor = ht[hash_val];
		while ( cursor != NULL )
		{
			if ( cursor->key == k )
			{
				return cursor;
			}
			cursor = cursor->link;
		}
		return NULL;
	}
	
	void insert(const KeyType k, const ValType v)
	{
		int hash_val = hashfunction(k);
		HashMapElemType* cursor = find(k);
		if ( cursor != NULL )
		{
			cursor->val = v;
		}
		else
		{
			HashMapElemType* newNode = new HashMapElemType;
			newNode->key = k;
			newNode->val = v;
			newNode->link = ht[hash_val];
			ht[hash_val] = newNode;
			mapsize++;
		}
	}
	
	bool remove(const KeyType k)
	{
		int hash_val = hashfunction(k);
		HashMapElemType* cursor = find(k);
		HashMapElemType* prev = ht[hash_val];
		if ( cursor == NULL )
		{
			return false;
		}
		else
		{
			if ( ht[hash_val] == cursor )
			{
				ht[hash_val] = cursor->link;
				delete cursor;
				return true;
			}
			else
			{
				while ( prev->link != cursor )
				{
					prev = prev->link;
				}
				prev->link = cursor->link;
				delete cursor;
				return true;
			}
		}
	}
	
	void print()
	{
		
	}

private:
	unsigned int hashfunction(const KeyType k)
	{
		int hash_val = -1;
		int temp = 0;
		string data = k;
		transform(data.begin(), data.end(), data.begin(), ::tolower);
		const char *ps = data.c_str();
		
		while ( *ps )
		{
			if ( *ps >= 97 && *ps <= 122 )
			{
				temp += *ps++;
				if ( *ps )
				{
					temp += ((int)*ps++) << 8;
				}
			}
		}
		hash_val = temp % divisor;
		return hash_val;
	}
	

private:
	HashMapElemType** ht;
	unsigned int mapsize, capacity, divisor;
};
