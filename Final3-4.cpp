
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class String
{
protected:
string a;
public:

String() { cout << "" << endl; }
String(string a1){ a = a1; }
String(const String& p){ a = p.a; }
~String(){};

String& operator =(const String& s)
{
a = s.a;
return *this;
}


String operator +(const String& s)
{
a = a + s.a;
return *this;
}

/*
friend String operator +(const String& u, const String& y);
{
 String r;
 r.a = u.a + y.a;
 return r;
}
*/

friend istream& operator>>(istream& s, String& b);
friend ostream& operator<<(ostream& s, const String& b);
};
ostream& operator <<(ostream& s, const String& b)
{
s << b.a;
return s;
}

istream& operator >>(istream& s, String& b)
{
s >> b.a;
return s;
}


class Text
{
private:
String* text;
int n;

public:
Text();
Text(const Text& s);
Text(int k);
~Text();

Text& operator =(const Text& s)
{
delete[] text;

n = s.n;
text = new String[n];
for (int i = 0; i < n; i++)
{
text[i] = s.text[i];
}
return *this;
}

/*friend Text operator +(const Text& a, const Text& b); */

/*
Text operator +(const Text& a, const Text& b)
{
 Text s;
 delete[] s.text;

  s.n = a.n + b.n;
  s.text = new String[s.n];

  for (int i = 0; i < a.n; i++)
  {
  s.text[i] = a.text[i];
  }
  for (int i = 0; i < b.n; i++)
  {
  s.text[i + a.n] = b.text[i];
  }
return s;
}
*/
Text operator +(const Text& b)
{
  Text s;
  delete[]s.text;

  s.n = n + b.n;
  s.text = new String[s.n];

  for (int i = 0; i < n; i++)
  {
  s.text[i] = text[i];
  }
  for (int i = 0; i < b.n; i++)
  {
  s.text[i + n] = b.text[i];
  }
return s;
  }


friend istream& operator >>(istream& s, Text& a);
friend ostream& operator <<(ostream& s, const Text& a);

};

ostream& operator<<(ostream& s, const Text& a)
{
  for (int i = 0; i < a.n; i++)
  {
  s << a.text[i] << " ";
  }
return s;
}

istream& operator >> (istream& s, Text& a)
{
delete[]a.text;

cout<<"n: ";
s >> a.n;
a.text = new String[a.n];

for(int i = 0; i < a.n; i++)
 {
 cout << "string: " << i << " : ";
 s >> a.text[i];
 }
return s;
}

Text::Text()
{
n = 1;
text = new String[1];
cin >> text[0];
system("cls");
}

Text::Text(const Text& s)
{
n = s.n;
text = new String[n];
for (int i = 0; i < n; i++)
{
text[i] = s.text[i];
}
}

Text::Text(int k)
{
n = k;
text = new String[n];
for (int i = 0; i < n; i++)
{
 cin >> text[i];
}
}

Text::~Text()
{
delete[] text;
}



int main()
{

String b;
String c;
String d;

cout << "String b :";
cin >> b;
cout << "String c :";
cin >> c;

d = c + b;
Text t;
cin >> t;
Text f;
cin >> f;
Text v;
v = t + f;

system("cls");
cout << "String: ";
cout << d << endl;

cout << "Text t: " << endl;
cout << t << endl;
cout << "Text f: " << endl;
cout << f << endl;
cout << "Text v = t + f: " << endl;
cout << v << endl;

cout << endl;

system("pause");
return 0;
}


