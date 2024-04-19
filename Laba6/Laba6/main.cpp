#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	void pop_front();

	void push_back(T data);

	void clear();

	int GetSize() { return Size; }

	T& operator[](const int index);

	void push_front(T data);

	void insert(T data, int index);

	void removeAt(int index);

	void pop_back();

private:


	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

int entering()
{
	setlocale(0, "");
	string p;
	bool flag{ true };

	while (flag)
	{
		getline(cin, p);

		if (!p.empty() && p.find_first_not_of("0123456789") == string::npos)
			flag = false;
		else
			cout << "Данные введены некоректно, попробуйте снова : " << endl;
	}
	return stoi(p);
}

template<typename T>
void choose(List<vector<T>>& Lst)
{
	cout << endl;
	cout << "Выберите функцию, которую хотите выполнить:" << endl;
	cout << "1 - Вставить элемент по номеру" << endl;
	cout << "2 - Удалить элемент по номеру" << endl;
	cout << "3 - Вывести размер списка" << endl;
	cout << "4 - Очистить все значения списка" << endl;
	cout << "5 - Вывести все элементы списка" << endl;
	cout << "6 - Вывести элемент по номеру" << endl;
	cout << "7 - Присвоение элементу предустановенных значений" << endl;
	cout << "8 - Выход" << endl;
	cout << endl;
	int x; x = entering();
	if (x == 1)
	{
		cout << "Введите значение поля списка и индекс через Enter" << endl;
		string a, b, c;
		getline(cin, a); getline(cin, b); getline(cin, c);
		vector<string> lst{ a, b, c };
		int i; i = entering();
		if (i > Lst.GetSize()) cout << "Элемента с данным номером нет" << endl;
		else {
			Lst.insert(lst, i - 1);
			write_in_file(Lst);
		}
	}
	else if (x == 2)
	{
		cout << "Введите номер по которому вы хотите удалить элемент" << endl;
		int i; i = entering(); //cin.ignore();
		if (i > Lst.GetSize()) cout << "Элемента с данным индексом нет" << endl;
		else {
			Lst.removeAt(i - 1);
			cout << "Элемент удален" << endl;
			write_in_file(Lst);
		}

	}
	else if (x == 3) cout << Lst.GetSize() << endl;

	else if (x == 4) { Lst.clear(); write_in_file(Lst); }

	else if (x == 5)
	{
		if (Lst.GetSize() == 0) cout << "СПИСОК ПУСТ" << endl;
		for (int i = 0; i < Lst.GetSize(); i++)
		{
			int j = 0;
			if (!Lst[i][j].empty()) {
				cout << i + 1 << ") ";
				for (j; j < 3; j++)
				{
					cout << Lst[i][j] << "\t";
				}
				cout << endl;
			}
			else continue;
		}
	}
	else if (x == 6)
	{
		cout << "Введите номер элемента: "<< endl;
		int i; i = entering();
		//cin.ignore();
		if (i > Lst.GetSize()) { cout << "Элемента с данным индексом нет" << endl; }
		else
		{
			for (int j = 0; j < 3; j++) {
				cout << Lst[i - 1][j] << "\t";
			}
			cout << "\n";
		}
	}

	else if (x == 7)
	{
		cout << "Введите номер элемента: " << endl;
		int i; i = entering();
		//cin.ignore();
		vector<string> lst{ "Ценная бумага", "0000", "00000000"};
		if (i > Lst.GetSize()) { cout << "Элемента с данным индексом нет" << endl; }
		else
		{
			Lst.insert(lst, i);
			Lst.removeAt(i - 1);
			write_in_file(Lst);
			cout << "\n";
		}
	}
	else if (x == 8)
	{
		exit(0);
	}
	else
	{
		cout << "Вы ввели неверное значение" << endl;
	}

	choose(Lst);
}

vector<string> splitString(string str, char splitter)
{
	vector<string> result;
	string current = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == splitter) {
			if (current != "") {
				result.push_back(current);
				current = "";
			}
			continue;
		}
		current += str[i];
	}
	if (current.size() != 0)
		result.push_back(current);
	return result;
}

void load_list(List<vector<string>>& Lst)
{
	ifstream vv;
	vv.open("vv.txt");
	string a;
	while (getline(vv, a))
	{
		vector<string> vrem;
		vrem = splitString(a, ';');
		Lst.push_back(vrem);
	}
	vv.close();
}

void write_in_file(List<vector<string>>& Lst)
{
	ofstream vv;
	vv.open("vv.txt");
	for (int i = 0; i < Lst.GetSize(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			vv << Lst[i][j] << ";";
		}
		vv << endl;
	}
	vv.close();
}

int main()
{
	setlocale(LC_ALL, "ru");
	List<vector<string>> lst;
	load_list(lst);
	choose(lst);
	return 0;
}

