#pragma once
#include "Node.h"
#include <utility> 

template <typename T>
class Tree {
public:
	Tree();
	~Tree();
	void PutValue(int key, T value);
	void DeleteValue(int key);
	int FindValue(int key);
	int operator [](int key);
	int operator + (std::pair<int, int> pair);
	void Traverse();
private:
	Node<T>* root_ = new Node<T>();
	Node<T>* FindNode(int key);
};

template <typename T>
Tree<T>::Tree()
{
}

template <typename T>
Tree<T>::~Tree()
{
}

template <typename T>
void Tree<T>::PutValue(int key, T value)
{
	Node<T>* node = root_;
	if (not node->notEmpty()) {
		root_->PutValue(key, value);
		return;
	}
	while (true) {
		if (node->ReturnKey() >= key) {
			if (node->ReturnKey() == key)
				return;
			if ((node->Left())->notEmpty()) {
				node = node->Left();
				continue;
			}
			else {
				node->PutLeft(key, value);
				return;
			}
		}
		else {
			if ((node->Right())->notEmpty()) {
				node = node->Right();
				continue;
			}
			else {
				node->PutRight(key, value);
				return;
			}
		}
	}
}

template <typename T>
void Tree<T>::DeleteValue(int key)
{
	Node<T>* tmp = FindNode(key);
	if (tmp) {
		if ((tmp->Right()->notEmpty())) {
			if (not (tmp->Left())->notEmpty()) {
				tmp->ReplaceBy(tmp->Right());
				return;
			}
			else {

			}
		}
		else if ((tmp->Left()->notEmpty())) {
			if (not (tmp->Right())->notEmpty()) {
				tmp->ReplaceBy(tmp->Left());
				return;
			}	
		}
	}
}

template <typename T>
int Tree<T>::FindValue(int key)
{
	return 0;
}

template <typename T>
int Tree<T>::operator[](int key)
{
	return 0;
}

template <typename T>
int Tree<T>::operator+(std::pair<int, int> pair)
{
	return 0;
}

template<typename T>
void Tree<T>::Traverse()
{
	if (root_->notEmpty())
		root_->Traverse();
	return;
}

template <typename T>
Node<T> * Tree<T>::FindNode(int key)
{
	Node* node = root_;
	while (node->notEmpty()) {
		if (node->ReturnKey() > key) {
			node = node->Right();
		}
		else if (node->ReturnKey() < key)
			node = node->Left();
		else
			return node;
	}
	return nullptr;
}
