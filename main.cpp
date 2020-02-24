#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct TBook
{
    string title,
            author;
};
void create(char[]);
void output(char[]);

int main()
{
    setlocale(LC_ALL, ".866");
    char a[] = "file.txt";
    create(a);
    output(a);


}

void create(char a[])
{
    int n;
    TBook b;
    cout << "Input n "; cin >> n;
    cin.ignore();
    ofstream file(a, ios::binary);
    for (int i = 0; i < n; i++)
    {
        cout << "Input title "; getline(cin, b.title);
        cout << "Input author "; getline(cin, b.author);
        file.write((char*)&b, sizeof(TBook));
    }
    file.close();

}

void output(char a[])
{
    TBook c;
    ifstream fil(a, ios::binary);
    while (!fil.eof())
    {
        fil.read((char*)&c, sizeof(TBook));
        if (!fil.eof())
            cout << c.title << "  " << c.author << endl;

    }
    fil.close();
}