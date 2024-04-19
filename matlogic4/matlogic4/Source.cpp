#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstring>
#include <stdexcept>

using namespace std;

int failure() {
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nОшибка ввода. Повторите ввод.\n" << endl;
	}
	return a;
}

bool is_correct(string str)
{
	int start = 0;
	int end = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			start++;
			int j = i + 1;
			while (str[j] == ' ')
				j++;
			if (str[j] == '-' || str[j] == ')')
				return false;
		}
		if (str[i] == ')')
		{
			end++;
			if (start < end)
				return false;
		}
		if (str[i] == 'j')
		{
			int j = i + 1;
			while (str[j] == ' ')
				j++;
			if (str[j] != '(')
				return false;
		}
		if (str[i] == 'x' || str[i] == 'y')
		{
			int j = i + 1;
			while (str[j] == ' ')
				j++;
			if (str[j] == 'x' || str[j] == 'y')
				return false;
		}
		if (str[i] == '-')
		{
			int j = i + 1;
			while (str[j] == ' ')
				j++;
			if (str[j] == '(' || str[j] == ')' || str[j] == '-' || str[j] == '/0')
				return false;
		}
	}
	if (start == end)
		return true;
	return false;
}

string entering(int n)
{
	string str;
	while (true)
	{
		cin >> str;
		if (n == 2 && str.find_first_not_of("()1234567890 -xyj") == string::npos && is_correct(str))
			break;
		else if (n == 1 && str.find_first_not_of("()1234567890 -xj") == string::npos && is_correct(str))
			break;
		else
			cout << "Некорректный ввод\n";
	}
	return str;
}

vector<string> split(string s, string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}

bool iscorrect(vector<string> main, vector<string> sec)
{
	bool flag;
	for (int i = 0; i < sec.size(); i++)
	{
		flag = false;
		for (int j = 0; j < main.size(); j++)
		{
			if (sec[i] == main[j])
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
			return false;
	}
	return true;
}

string entering2(int k)
{
	string str;
	string s;
	vector<string> chek, chek2;
	for (int i = 0; i < k; i++)
	{
		s += to_string(i);
		s += ' ';
	}
	s.erase(s.length() - 1, 1);
	chek = split(s, " ");
	while (true)
	{
		/*cin >> str;*/
		cin.ignore();
		getline(cin, str);
		chek2 = split(str, " ");
		if (!str.empty() && str.find_first_not_of(s) == string::npos && iscorrect(chek, chek2))
			break;
		else
			cout << "Некорректный ввод\n";
	}
	return str;
}

int** forarr(int n, int k)
{
	int** arr = new int*[(int)pow(k, n)];
	for (int i = 0; i < (int)pow(k, n); i++)
	{
		arr[i] = new int[n + 1];
		for (int j = 0; j < n + 1; j++)
			arr[i][j] = 0;
	}
	return arr;
}

int func_first_type(int x)
{
	if (x == 3)
		return 1;
	return 0;
}

int diff_module_k(int x, int y, int k)
{
	if (x >= y)
		return x - y;
	return x - y + k;
}
	 
struct Expression 
{
	Expression(string token) : token(token) {}
	Expression(string token, Expression a) : token(token), args{ a } {}
	Expression(string token, Expression a, Expression b) : token(token), args{ a, b } {}

	string token;
	vector<Expression> args;
};

class Parser 
{
public:
	explicit Parser(const char* input) : input(input) {}
	Expression parse();
private:
	string parse_token();
	Expression parse_simple_expression();
	Expression parse_binary_expression(int min_priority);

	const char* input;
};

string Parser::parse_token() 
{
	while (isspace(*input)) ++input;

	if (isdigit(*input)) 
	{
		string number;
		while (isdigit(*input)) number.push_back(*input++);
		return number;
	}

	static const string tokens[] =
	{"-", "(", ")" , "j"};
	for (auto& t : tokens) 
	{
		if (strncmp(input, t.c_str(), t.size()) == 0) 
		{
			input += t.size();
			return t;
		}
	}

	return "";
}

Expression Parser::parse_simple_expression() 
{
	auto token = parse_token();
	if (token.empty()) throw runtime_error("Invalid input");

	if (token == "(") 
	{
		auto result = parse();
		if (parse_token() != ")") throw runtime_error("Expected ')'");
		return result;
	}

	if (isdigit(token[0]))
		return Expression(token);

	return Expression(token, parse_simple_expression());
}

int get_priority(const string& binary_op) {
	if (binary_op == "-") return 1;
	if (binary_op == "j") return 2;

	return 0;
}

Expression Parser::parse_binary_expression(int min_priority) {
	auto left_expr = parse_simple_expression();

	for (;;) 
	{
		auto op = parse_token();
		auto priority = get_priority(op);
		if (priority <= min_priority) {
			input -= op.size();
			return left_expr;
		}

		auto right_expr = parse_binary_expression(priority);
		left_expr = Expression(op, left_expr, right_expr);
	}
}

Expression Parser::parse() {
	return parse_binary_expression(0);
}

int eval(const Expression& e, int k) {
	switch (e.args.size()) {
	case 2: {
		auto a = eval(e.args[0], k);
		auto b = eval(e.args[1], k);
		if (e.token == "-") return diff_module_k(a, b, k);
		throw runtime_error("Unknown binary operator");
	}

	case 1: {
		auto a = eval(e.args[0], k);
		if (e.token == "j") return func_first_type(a);
		throw runtime_error("Unknown unary operator");
	}

	case 0:
		return (int)strtod(e.token.c_str(), nullptr);
	}

	throw runtime_error("Unknown expression type");
}

void SDNF(int k, int n, int** arr)
{
	cout << endl;
	string str = "";
	for (int i = 0; i < pow(k, n); i++)
	{
		if (arr[i][n] == 0)
			continue;
		else if (n == 2)
		{
			str += to_string(arr[i][n]);
			str += " & I_";
			str += to_string(arr[i][0]);
			str += "(x) & I_";
			str += to_string(arr[i][1]);
			str += "(y) v ";
		}
		else if (n == 1)
		{
			str += to_string(arr[i][n]);
			str += " & I_";
			str += to_string(arr[i][0]);
			str += "(x) v ";
		}
	}
	if (!str.empty())
	{
		str.erase(str.length() - 2, 1);
		cout << "Аналог СДНФ:\n";
		cout << str << endl;
	}
	else
		cout << "Аналог СДНФ пуст\n";
}

bool Plenty(int n, int k, int** arr)
{
	cout << "Введите множество через пробел:\n";
	string str = entering2(k);
	
	if (n == 2)
	{
		for (int i = 0; i < (int)pow(k, n); i++)
		{
			if (str.find(to_string(arr[i][0])) != string::npos && str.find(to_string(arr[i][1])) != string::npos)
			{
				if (str.find(to_string(arr[i][2])) == string::npos)
					return false;
			}
		}
		return true;
	}
	else if (n == 1)
	{
		for (int i = 0; i < (int)pow(k, n); i++)
		{
			if (str.find(to_string(arr[i][0])) != string::npos)
			{
				if (str.find(to_string(arr[i][1])) == string::npos)
					return false;
			}
		}
		return true;
	}
}

void displaying(int n, int k, int** arr)
{
	int i = 0;
	if (n == 2)
	{
		cout << " x | y | f(x,y) \n";
		cout << "___|___|_______\n";
		for (int x = 0; x < pow(k, n); x++)
			cout << " " << arr[x][0] << " | " << arr[x][1] << " | " << arr[x][2] << endl;
	}
	if (n == 1)
	{
		cout << " x | f(x,y) \n";
		cout << "___|_______\n";
		for (int x = 0; x < pow(k, n); x++)
			cout << " " << arr[x][0] << " | " << arr[x][1] << endl;
	}
	SDNF(k, n, arr);
	if (Plenty(n, k, arr))
		cout << "Сохраняет\n";
	else
		cout << "Не сохраняет\n";
}

void job(int n, int k, string str, int** arr)
{
	int i = 0;
	if (n == 2)
	{
		for (int x = 0; x < k; x++)
		{
			for (int y = 0; y < k; y++)
			{
				string copy = "";
				arr[i][0] = x;
				arr[i][1] = y;
				for (int v = 0; str[v] != '\0'; v++)
				{
					if (str[v] == 'x')
						copy += to_string(x);
					else if (str[v] == 'y')
						copy += to_string(y);
					else
						copy += str[v];
				}
				Parser parsed(copy.c_str());
				arr[i][2] = eval(parsed.parse(), k);
				i++;
			}
		}
	}
	else if (n == 1)
	{
		for (int x = 0; x < k; x++)
		{
			string copy = "";
			arr[i][0] = x;
			for (int v = 0; str[v] != '\0'; v++)
			{
				if (str[v] == 'x')
					copy += to_string(x);
				else
					copy += str[v];
			}
			Parser parsed(copy.c_str());
			arr[i][1] = eval(parsed.parse(), k);
			i++;
		}
	}
	displaying(n, k, arr);
}

void menu()
{
	int g = 4211;
	int n = 23;
	int k;
	int** arr;
	string str;
	cout << "щукин а.а., 4211, в списке 23-й\nвариант:\n";
	cout << "унарная операция:" << (g + n - 1) % 6 + 1 << " j_s(x) - s = n / 7 = 3\n";
	cout << "унарная операция:" << (g + n - 1) % 7 + 1 << " x - y\n";
	cout << "унарная операция:" << (g + n - 1) % 3 + 1 << " аналог сднф\n";
	cout << "введите число n:\n";
	while (true)
	{
		n = failure();
		if (n == 1 || n == 2)
			break;
	}
	cout << "введите сичло k:\n";
	k = failure();
	cout << "введите функцию, сохраняя приорететность скобками:\n";
	str = entering(n);
	arr = forarr(n, k);
	job(n, k, str, arr);
	

}

int main()
{
	setlocale(0, "");
	menu();
	return 0;
}