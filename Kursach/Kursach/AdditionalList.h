#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

class Workers
{
public:
	Workers()
	{
		Top = new Worker("Head", "Head");
	}
	~Workers()
	{
		Clear();
		delete Top;
		Top = nullptr;
	}
	bool isEmpty()
	{
		if (Top->next == nullptr)
			return true;
		return false;
	}
	string To_String()
	{
		string workers;
		Worker* curent = Top->next;
		while (curent != nullptr)
		{
			workers += curent->Surname;
			workers += "-";
			workers += curent->Post;
			if (curent->next != nullptr)
				workers += ";";
			curent = curent->next;
		}
		return workers;
	}
	void print()
	{
		if (!isEmpty())
		{
			Worker* curent = Top->next;
			while (curent != nullptr)
			{
				cout << curent->Surname << " - " << curent->Post << endl;
				curent = curent->next;
			}
		}
		else
			cout << "Список работников пуст\n";
	}
	void Add(string surname, string post)
	{
		if (isEmpty())
			Top->next = new Worker(surname, post);
		else
		{
			Worker* curent = Top;
			while (curent->next != nullptr && curent->next->Surname.compare(surname) < 0)
				curent = curent->next;
			while (curent->next != nullptr && curent->next->Surname.compare(surname) == 0 && curent->next->Post.compare(post) < 0)
				curent = curent->next;
			Worker* item = new Worker(surname, post);
			item->next = curent->next;
			curent->next = item;
		}
	}
	void Clear()
	{
		Worker* temp = Top->next;
		while (Top->next != nullptr)
		{
			Top->next = Top->next->next;
			delete temp;
			temp = Top->next;
		}
	}
	int FindSame(string surname)
	{
		int count = 0;
		Worker* curent = Top->next;
		while (curent != nullptr)
		{
			if (curent->Surname == surname)
				count++;
			curent = curent->next;
		}
		return count;
	}
	void pop(string surname)
	{
		if (!isEmpty() && FindSame(surname) > 1)
		{
			string post;
			cout << "В списке работников присутствуют однофамильцы, уточните должность:\n";
			while (true)
			{
				cin >> post;
				if (post.find_first_not_of("АБВГДЕЖЗИКЛМНОПРСТУФЧЦЧЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя") == string::npos)
					break;
				else
					cout << "Некорректный ввод\n";
			}
			pop(surname, post);
		}
		else if (!isEmpty() && FindSame(surname) == 1)
		{
			Worker* curent = Top;
			while (curent->next != nullptr && curent->next->Surname != surname)
				curent = curent->next;
			Worker* temp = curent->next;
			if (curent->next != nullptr)
				curent->next = curent->next->next;
			delete temp;
		}
		else if (!isEmpty() && FindSame(surname) == 0)
			cout << "Такого работника нет\n";
		else
			cout << "Список работников пуст\n";
	}
private:
	void pop(string surname, string post)
	{
		Worker* curent = Top;
		while (curent->next != nullptr && curent->next->Surname != surname)
			curent = curent->next;
		while (curent->next != nullptr && curent->next->Surname == surname && curent->next->Post != post)
			curent = curent->next;
		if (curent->next != nullptr && curent->next->Surname == surname && curent->next->Post == post)
		{
			Worker* temp = curent->next;
			curent->next = curent->next->next;
			delete temp;
		}
		else
			cout << "Такого работрника нет\n";
	}
	class Worker
	{
	public:
		Worker* next;
		string Surname;
		string Post;
		Worker(string surname, string post, Worker* pointer = nullptr)
		{
			Surname = surname;
			Post = post;
			next = pointer;
		}
		~Worker()
		{
			next = nullptr;
			Surname = "";
			Post = "";
		}
	};
	Worker* Top;
};