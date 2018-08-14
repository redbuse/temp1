// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	Node* node = new Node(' ');
	this->CurNode = node;
	count = 0;
  return;
}

void TypingMachine::HomeKey() {

	Node * CurNode = this->CurNode; //커서 노드

	//상황 가장 끝에1
	// 일반적일 경우
	// 원래 맨 앞
	//상황 가장 끝에1
	


	while (CurNode->GetPreviousNode())
	{
		CurNode = CurNode->GetPreviousNode();
	}
	this->CurNode = CurNode;


  return;
}

void TypingMachine::EndKey() {
	Node * CurNode = this->CurNode; //커서 노드

	//상황 가장 앞에
	// 일반적일 경우
	// 원래 맨 앞asdfasdfasf
	//상황 가장 끝에


	if (CurNode->GetNextNode() == nullptr)
		return;
	if (CurNode->GetNextNode()) {
		CurNode = CurNode->GetNextNode();
		CurNode->ErasePreviousNode();	
	}


	while (CurNode->GetNextNode())
	{
		CurNode = CurNode->GetNextNode();
	}
	//CurNode->InsertNextNode(this->sperator);
	this->CurNode = CurNode->GetNextNode();



	return;

}

void TypingMachine::LeftKey() {

	Node * CurNode = this->CurNode; //커서 노드
	//왼쪽으로 이동


	if (CurNode->GetPreviousNode()) {
		this->CurNode = CurNode->GetPreviousNode();
	}


		
  return;
}

void TypingMachine::RightKey() {
	Node * CurNode = this->CurNode; //커서 노드
	//오른쪽 이동


	if (CurNode->GetNextNode()) {
		this->CurNode = CurNode->GetNextNode();
	}



	return;
}

bool TypingMachine::TypeKey(char key) {

	Node* CurNode = this->CurNode;
	if ((32 <= key) && (key <= 126)){
		CurNode->InsertPreviousNode(key);
		
		//this->CurNode = CurNode->GetPreviousNode();
		this->count++;
		return true;
	}
	else
		return false;
  
}

bool TypingMachine::EraseKey() {


	Node* CurNode = this->CurNode;
	if (CurNode->ErasePreviousNode())
	{
		this->count--;
		return true;
	}else
	return false;
 
}

std::string TypingMachine::Print(char separator) {

	using namespace std;
	string str;

	Node * CurNode = this->CurNode;
	

	//맨 앞으로 이동
	while (CurNode != nullptr)
	{
		if (CurNode->GetPreviousNode() == nullptr)
		{
			break;
		}
		else CurNode = CurNode->GetPreviousNode();
	}

	while (CurNode != nullptr)
	{
		if (CurNode == this->CurNode)
		{
			if (separator != 0) //0 이 아니고
			{
				if (this->CurNode->prev == nullptr) {// home key 이면
					str.push_back(separator);
					if (CurNode->GetData() !=' ')
						str.push_back(CurNode->GetData());
				}
				else{
					if (CurNode->GetData() != ' ')
						str.push_back(CurNode->GetData());
					str.push_back(separator);
				}
				
			}			
		}else
		str.push_back(CurNode->GetData());
		CurNode = CurNode->GetNextNode();		
	}
	
  return str;
}
