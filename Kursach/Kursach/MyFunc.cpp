#include "MainList.h"

int failure()
{
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\n������ �����. ��������� ����.\n" << endl;
	}
	return a;
}

string entering()
{
	string str;
	while (true)
	{
		do
		{
			getline(cin, str);
		} while (str.length() == 0);
		if (str.find_first_not_of("������������������������������������������������������������ ") == string::npos)
			break;
		else
			cout << "������������ ����\n";
	}
	return str;
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

void write_in_file(Departments* pointer, string way)
{
	vector<string> organization = pointer->To_String();
	vector<string> departments = splitString(organization[0], ':');
	vector<string> workers;
	ofstream vv;
	vv.open(way);
	if (vv.is_open())
	{
		vv << departments[0] << ":\n" << departments[1] << "\n";
		departments = splitString(departments[1], ';');
		for (int i = 1; i < organization.size(); i++)
		{
			workers = splitString(organization[i], ';');
			for (int j = 0; j < workers.size(); j++)
			{
				vv << departments[i - 1] << '-' << workers[j] << endl;
			}
		}
		vv.close();
	}
	else
		cout << "�� ������� ������� ����\n";
}

void From_file(Departments*& pointer, string way)
{
	ifstream readfile;
	readfile.open(way);
	if (readfile.is_open())
	{
		string name, str;
		getline(readfile, name);
		name.pop_back();
		getline(readfile, str);
		vector<string> departments = splitString(str, ';');
		pointer = new Departments(departments.size(), name);
		vector<string> workers;
		while (getline(readfile, str))
		{
			workers = splitString(str, '-');
			pointer->add_Worker(workers[0], workers[1], workers[2]);
		}
	}
	else
		cout << "�� ������� ������� ����\n";
}

void Job()
{
	Departments* Organization = nullptr;
	int comand;
	string name, surname, post;
	while (true)
	{
		cout << "1. �������� �����������\n";
		cout << "2. �������� �����\n";
		cout << "3. �������� ����������\n";
		cout << "4. �������������\n";
		cout << "5. ������� �����\n";
		cout << "6. ������� ����������\n";
		cout << "7. ����� �����������\n";
		cout << "8. �������� �����������\n";
		cout << "0. ��������� ������ ���������\n";
		comand = failure();
		cout << endl;
		switch (comand)
		{
		case 0:
			if (Organization != nullptr)
			{
				delete Organization;
				Organization = nullptr;
			}
			exit(0);
			break;
		case 1:
			if (Organization == nullptr)
			{
				cout << "1. �������� �������\n";
				cout << "2. ��������� � �����\n";
				comand = failure();
				cout << endl;
				switch (comand)
				{
				case 1:
					cout << "������� �������� �����������:\n";
					name = entering();
					cout << "������� ���������� �������:\n";
					comand = failure();
					Organization = new Departments(comand, name);
					break;
				case 2:
					cout << "������� ���� � ����� ��� ��� ��������:\n";
					cin >> name;
					From_file(Organization, name);
					break;
				default:
					break;
				}
			}
			else
				cout << "����������� ��� �������\n";
			break;
		case 2:
			if (Organization != nullptr)
			{
				cout << "������� �������� ������:\n";
				name = entering();;
				Organization->add_Department(name);
			}
			else
				cout << "����������� �� �������\n";
			break;
		case 3:
			if (Organization != nullptr)
			{
				cout << "������� �������� ������:\n";
				name = entering();;
				cout << "������� ������� ����������:\n";
				surname = entering();;
				cout << "������� ��������� ����������:\n";
				post = entering();;
				Organization->add_Worker(name, surname, post);
			}
			else
				cout << "����������� �� �������\n";
			break;
		case 4:
			if (Organization != nullptr)
			{
				cout << "1. ������������� �����������\n";
				cout << "2. ������������� �����\n";
				comand = failure();
				cout << endl;
				switch (comand)
				{
				case 1:
					Organization->Rename();
					break;
				case 2:
					cout << "������� �������� ������:\n";
					name = entering();;
					Organization->RenameDepartment(name);
					break;
				default:
					break;
				}
			}
			else
				cout << "����������� �� �������\n";
			break;
		case 5:
			if (Organization != nullptr)
			{
				cout << "������� �������� ������:\n";
				name = entering();;
				Organization->pop_Department(name);
			}
			else
				cout << "����������� �� �������\n";
			break;
		case 6:
			if (Organization != nullptr)
			{
				cout << "������� �������� ������:\n";
				name = entering();;
				cout << "������� ������� ����������:\n";
				surname = entering();;
				Organization->pop_Worker(name, surname);
			}
			else
				cout << "����������� �� �������\n\n";
			break;
		case 7:
			if (Organization != nullptr)
				Organization->print();
			else
				cout << "����������� �� �������\n\n";
			break;
		case 8:
			if (Organization != nullptr)
			{
				cout << "��������� � ����?\n1 - ��\n2 - ���\n";
				comand = failure();
				cout << endl;
				if (comand == 1)
				{
					cout << "������� ���� � ����� ��� ��� ��������:\n";
					cin >> name;
					write_in_file(Organization, name);
				}
				delete Organization;
				Organization = nullptr;
			}
			else
				cout << "����������� �� �������\n\n";
			break;
		default:
			break;
		}
	}
}