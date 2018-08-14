// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	n_data = data;
	prev = nullptr;
	next = nullptr;

	return;
}

char Node::GetData() {


	return this->n_data;
}

Node* Node::GetPreviousNode() {

	return this->prev;
}

Node* Node::GetNextNode() {
	return this->next;
}

Node* Node::InsertPreviousNode(char data) {

	Node* nd = new Node(data);

	if (this->prev == nullptr){
		this->prev = nd;
		nd->next = this;
	}
	else{
		this->prev->next = nd;
		nd->prev = this->prev;
		this->prev = nd;
		nd->next = this;

	}
	return nd;
}

Node* Node::InsertNextNode(char data) {

	Node* nd = new Node(data);


	if (this->next == nullptr){
		this->next = nd;
		nd->prev = this;

	}
	else {
		this->next->prev = nd;
		nd->next = this->next;
		this->next = nd;
		nd->prev = this;
	}



	return nd;
}

bool Node::ErasePreviousNode() {


	if (this->prev == nullptr)
	{
		return false;
	}
	else
	{

		if (this->prev->prev == nullptr){
			Node * temp = this->prev;
			this->prev = nullptr;
			delete(temp);


		}
		else{

			Node * temp = this->prev;
			this->prev->prev->next = this;
			this->prev = this->prev->prev;
			delete(temp);


		}
		return true;

	}
}

bool Node::EraseNextNode() {


	if (this->next == nullptr)
	{

		return false;
	}
	else{

		if (this->next->next == nullptr){
			Node * temp = this->next;
			this->next = nullptr;
			delete(temp);

		}
		else{
			Node * temp = this->next;
			this->next->next->prev = this;
			this->next = this->next->next;
			delete(temp);

		}
		return true;
	}


}
