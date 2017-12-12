#pragma once
#include <iostream>
template <typename T>
class Node {
public:
	Node();
	~Node();
	void PutValue(int key, T value);
	void PutLeft(int key,T value);
	void PutRight(int key, T value);
	T ReturnValue();
	int ReturnKey();
	void ReplaceBy(Node* node);
	Node* Left();
	Node* Right();
	bool notEmpty();
	void Traverse();
	
private:
	T value_;
	int key_;
	Node<T>* left_;
	Node<T>* right_;
	bool empty_ = true;
};

template <typename T>

Node<T>::Node()
{
}
template <typename T>
Node<T>::~Node()
{
}

template <typename T>
void Node<T>::PutValue(int key, T value)
{
	key_ = key;
	value_ = value;
	empty_ = false;
	right_ = new Node<T>();
	left_ = new Node<T>();
}

template <typename T>
void Node<T>::PutLeft(int key, T value)
{
	left_->PutValue(key, value);
}

template <typename T>
void Node<T>::PutRight(int key, T value)
{
	right_->PutValue(key, value);
}

template <typename T>
T Node<T>::ReturnValue()
{
	return value_;
}

template <typename T>
int Node<T>::ReturnKey()
{
	return key_;
}

template <typename T>
void Node<T>::ReplaceBy(Node * node)
{
	*this = *node;
}

template <typename T>
Node<T> * Node<T>::Left()
{
	return left_;
}

template <typename T>
Node<T> * Node<T>::Right()
{
	return right_;
}

template <typename T>
bool Node<T>::notEmpty()
{
	return (not empty_);
}

template<typename T>
void Node<T>::Traverse()
{
	if (not right_->empty_) {
		right_->Traverse();
	}
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "My adress is: " << this << std::endl;
	std::cout << "My key is: " << key_ << std::endl;
	std::cout << "My value is: " << value_ << std::endl;
	std::cout << "My right son is: " << right_ << std::endl;
	std::cout << "My left son is: " << left_ << std::endl;

	if (not left_->empty_) {
		left_->Traverse();
	}
}
