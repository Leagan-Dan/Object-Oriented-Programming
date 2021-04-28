#pragma once
#include "List.h"
#include "Node.h"
using namespace std;

template<class K, class V>
class Map
{
	int capacity;
	int length;
	List<K, V>* container;
	Node<K, V>** allElements;

public:
	Map();
	void Set(K, V);
	bool Get(const K& key, V& value);
	int Count();
	void Clear();
	void Delete();
	bool Includes(const Map<K, V>& map);
	Node<K, V>& operator[] (K);
	/*MyIterator<K, V> begin();
	MyIterator<K, V> end();*/
};

