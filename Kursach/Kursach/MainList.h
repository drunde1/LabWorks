#pragma once
#include "AdditionalList.h"
#include <vector>

class Departments
{
public:
	Departments(int size, string name)
	{
		Size = size;
		arr = new Department[Size + 1];
		arr[0].Name = name;
		arr[0].next = 0;
	}
	~Departments()
	{
		delete[] arr;
		Size = 0;
		arr = nullptr;
	}
	bool isEmpty()
	{
		if (arr[arr[0].next].List == nullptr && arr[arr[0].next].Name == "")
			return true;
		return false;
	}
	bool isFull()
	{
		if (searchFreeItem() == 0)
				return true;
		return false;
	}
	void add_Department(string name)
	{
		if (!isFull())
		{
			int newel = searchFreeItem();
			int index = 0;
			arr[newel].List = new Workers();
			arr[newel].Name = name;
			while (arr[arr[index].next].List != nullptr && arr[arr[index].next].Name.compare(name) < 0)
				index = arr[index].next;
			arr[newel].next = arr[index].next;
			arr[index].next = newel;
		}
		else
			cout << "Список отделов заполнен\n";
	}
	void add_Worker(string name, string surname, string post)
	{
		int index = search(name);
		if (index == 0 && !isFull())
		{
			add_Department(name);
			add_Worker(name, surname, post);
		}
		else if (index == 0 && isFull())
			cout << "Такого отдела нет и добавление невозможно\n";
		else if (index != 0)
			arr[index].List->Add(surname, post);
	}
	void pop_Department(string name)
	{
		if (!isEmpty() && search(name) != 0)
		{
			int pop = search(name);
			int index = 0;
			while (arr[index].next != pop)
				index = arr[index].next;
			arr[index].next = arr[pop].next;
			delete arr[pop].List;
			arr[pop].List = nullptr;
			arr[pop].next = 0;
			arr[pop].Name = "";
		}
		else if (isEmpty())
			cout << "Список отделов пуст\n";
		else if (search(name) == 0)
			cout << "Такого отдела нет\n";
	}
	void pop_Worker(string name, string surname)
	{
		if (search(name) != 0)
			arr[search(name)].List->pop(surname);
		else if (isEmpty())
			cout << "Список отделов пуст\n";
		else
			cout << "Такого отлела нет\n";
	}
	void print()
	{
		if (!isEmpty())
		{
			cout << "_____" << arr[0].Name << "_____\n";
			int index = arr[0].next;
			while (index != 0)
			{
				cout << arr[index].Name << ": " << endl;
				arr[index].List->print();
				cout << endl;
				index = arr[index].next;
			}
			cout << endl;
		}
	}
	vector<string> To_String()
	{
		vector<string> organization;
		organization.push_back(arr[0].Name);
		organization[0] += ":";
		int index = arr[0].next;
		while (index != 0)
		{
			organization[0] += arr[index].Name;
			if (arr[index].next != 0)
				organization[0] += ";";
			organization.push_back(arr[index].List->To_String());
			index = arr[index].next;
		}
		return organization;
	}
	void clear()
	{
		for (int i = 1; i < Size; i++)
		{
			delete arr[i].List;
			arr[i].Name = "";
			arr[i].next = 0;
		}
		Size = 0;
		arr = nullptr;
	}
	void Rename()
	{
		cout << "Введите новое название Организации:\n";
		cin >> arr[0].Name;
	}
	void RenameDepartment(string name)
	{
		int index = search(name);
		if (index != 0)
		{
			cout << "Введите новое название отдела:\n";
			cin >> name;
			arr[index].Name = name;
			index = 0;
		}
	}
private:
	int searchFreeItem()
	{
		for (int i = 1; i < Size + 1; i++)
		{
			if (arr[i].List == nullptr)
				return i;
		}
		return 0;
	}
	int search(string name)
	{
		if (!isEmpty())
		{
			for (int i = 1; i < Size + 1; i++)
			{
				if (arr[i].Name == name)
					return i;
			}
		}
		return 0;
	}
	class Department
	{
	public:
		int next;
		string Name;
		Workers* List;
		Department()
		{
			Name = "";
			next = 0;
			List = nullptr;
		}
		Department(string name, Workers* list = nullptr, int pointer = 0)
		{
			Name = name;
			next = pointer;
			List = list;
		}
		~Department()
		{
			Name = "";
			next = 0;
			delete List;
		}
	};
	int Size;
	Department* arr;
};