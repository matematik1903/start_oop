#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <class T>
class String
{
protected:
T a;
public:
String(){ cout << "";  }
String(T a1){ a = a1; }
String(const String < T > & p){ a = p.a; }
~String(){};

String<T> operator +(const String<T>& s)
{
a = a + s.a;
return *this;
}

String<T>& operator =(const String<T>& s)
{
a = s.a;
return *this;
}

friend istream& operator>>(istream& s, String<T>& b)
{
s >> b.a;
return s;
}


friend ostream& operator<<(ostream& s,const String<T>& b)
{
s << b.a;
return s;
}
};

template <class TYPE>
class Text
{
private:
TYPE* text;
int n;

public:
	Text()
	  {
	   n = 1;
	   text = new TYPE[1];
	   cin >> text[0];
	  }

	Text(const Text< TYPE >& s)
	  {
	   n = s.n;
	   text = new TYPE[n];
	   for (int i = 0; i < n; i++)
		{
			text[i] = s.text[i];
		}
	  }

	Text(int k)
	  {
	   n = k;
	   text = new TYPE[n];
	   for (int i = 0; i < n; i++)
		 {
			cin >> text[i];
		 }
	  }

	~Text()
	  {
	   delete[] text;
	  }


  Text<TYPE>& operator =(const Text<TYPE>& s)
   {
	delete[] text;

	n = s.n;
	text = new TYPE[n];
	for (int i = 0; i < n; i++)
	 {
		text[i] = s.text[i];
	 }
	return *this;
   }


  Text<TYPE> operator +(const Text<TYPE>& b)
  {
   Text<TYPE> s;
   delete[]s.text;

   s.n = n + b.n;
   s.text = new TYPE[s.n];

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


	  friend istream& operator >>(istream& s, Text<TYPE>& a)
	   {
		 delete[]a.text;

		 cout << "n: ";
		 s >> a.n;
		 a.text = new TYPE[a.n];

		 for(int i = 0; i < a.n; i++)
		  {
			   cout << "string: " << i << " : ";
			   s >> a.text[i];
		  }
		 return s;
	   }


	  friend ostream& operator <<(ostream& s, const Text<TYPE>& a)
	   {
		 for (int i = 0; i < a.n; i++)
		  {
			   s << a.text[i] << " ";
		  }
		 return s;
	   }
};

int main()
{
String <int> a;
cin >> a;

String <int> b;
cin >> b;

a + b;
cout << a;
cout << endl;

a = b;
cout << a;
cout << endl;

Text<int> A;
Text<int> B;

cin >> A;
cout << A << endl;

cin >> B;
cout << B << endl;
cout << A + B << endl;


Text<String<int> > A1;
Text<String<int> > B1;


cin >> A1;
cout << A1 << endl;

cin >> B1;
cout << B1 << endl;
A1 = B1 ;
cout << A1 << endl;
system("pause");
return 0;
}





