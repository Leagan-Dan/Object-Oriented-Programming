#include <iostream>
#include "Map.h"
#include "Node.h"
#include "List.h"

using namespace std;

template<class K, class V>
Map<K,V>::Map() {
	capacity = 10;
	length = 0;
	container = new List<K, V>[capacity];
	allElements = new Node<K, V>*[capacity];
}

template<class K, class V>
void Map<K, V>::Set(K key, V value)
{
	Node<K, V>* newNode = new Node <K, V>(value, key);
	container[key].add(newNode);
	length++;
}

template<class K, class V>
bool Map<K, V>::Get(const K& key, V& value)
{
	keyIndex = key;
	Node<K, V>* temp = container[keyIndex].root;
	while (temp != nullptr) {
		if ()
		{
			temp->value = value;
			return true;
		}
		temp = temp->next;
	}
}

template<class K, class V>
int Map<K, V>::Count()
{
	return lenght;
}

template<class K, class V>
void Map<K, V>::Clear()
{
	delete[] container;
	capacity = 10;
	length = 0;
	container = new List<K, V>[capacity];
	allElements = new Node<K, V>*[capacity];
	length = 0;
}

template<class K, class V>
void Map<K, V>::Delete()
{

}

template<class K, class V>
bool Map<K, V>::Includes(const Map<K, V>& map)
{

}

template<class K, class V>
Node<K, V>& Map<K, V>::operator[] (K key)
{

}
