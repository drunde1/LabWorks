#pragma once
#include "TFigure.h"
TFigure** tfigures = NULL;

class MyContainer
{
public:
	MyContainer()
	{
		Size = 0;
		head = nullptr;
		MessageBox::Show("Container(list class) is created!");
	}
	~MyContainer()
	{
		Free();
	}

	void pop_front()
	{
		Node* temp = head;

		head = head->pNext;

		delete temp;

		Size--;

	}

	void push_back(TFigure* data)
	{
		if (head == nullptr)
		{
			head = new Node(data);	
		}
		else
		{
			Node* current = this->head;

			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node(data);

		}

		Size++;
	}

	void Free()
	{
		while (Size)
		{
			pop_front();
		}
	}

	int GetSize() { return Size; }

	void Iterator(int a, Graphics^ canvas, int newx=0, int newy=0)
	{
		Node* current;
		switch (a)
		{
		case 0:
			canvas->Clear(Color::FromArgb(145, 225, 86));
		case 1:
			current = this->head;

			while (current->pNext != nullptr)
			{
				current->data->Show(canvas);
				current = current->pNext;
			}
			current->data->Show(canvas);

		case 2:
			current = this->head;
			while (current->pNext != nullptr)
			{
				current->data->MoveTo(newx, newy, canvas);
				current = current->pNext;
			}
			current->data->MoveTo(newx, newy, canvas);

		}
	}
private:

	class Node
	{
	public:
		Node* pNext;
		TFigure* data;

		Node(TFigure* data = NULL, Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node *head;
};