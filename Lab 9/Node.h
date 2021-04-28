#pragma once

template<class K, class V>
class Node {
public:
	V value;
	K key;

	Node<K, V>* next = nullptr;

	Node(V value, K key) : value(value), key(key) {};
	Node() {};
	void operator =(V value);
	~Node();
};
