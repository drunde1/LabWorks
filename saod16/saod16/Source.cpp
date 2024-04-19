#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<string> split(string s, string delimiter) 
{
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

void ReadInput(int count)
{
    for (int i = 0; i < count; i++)
    {
        string str = "";
        while (str == "")
        {
            getline(cin, str);
        }
        vector<string> numbers = split(str, " ");
        int first = stoi(numbers[0]);
        int second = stoi(numbers[1]);
        cout << first + second << endl;
    }
}

int main()
{
    int count;
    cin >> count;
    ReadInput(count);
}

