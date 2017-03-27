#include <iostream> 
#include <string>
#include <cstring> 

 
	/*             ����� (2 �����: �����, ����� ����������� � �������� ���������)
/                   ������������: �� �������������, � ����������� �� ���������.
/                   ����������.
/                  ������� (��-��� �� ����):
/             1.      ���������� (���������) ������� � ������ �����, � ������ ����;
/             2.  +   �������� �������� �����;
/             3.  +   ��������� �������� �����;
/             4.  +   ���������� ����� � ������ ����;
/             5. (+-) ����� ����� � �����;
/             6.  +   �������� ������.

    */
 
 using namespace std;               
     
 class String
  {
 protected:
    string a;  
 public: 
    /*  Constructors  */
   
    String() 
    {
    cout << "Hello,world!!! " << endl;                 //  ����������� �� ������������ ��� class String
	}
	String (string a1)
	{
    a = a1;                                           //  ����������� � ���������� ��� class String
	}
    String(const String& p)  
    {
    a = p.a;                                          //  ����������� ��������� ��� class String
	}
    ~String()  
    {
    cout << "\n *************** \n";	              //   ���������� ��� class String
    } 
    
    void Text_Konstryktor();                          //   ������� ��� ������������ �� ������������ class String
    
    /*  Function  */
 
	void set();                      // Function ��� ����� ����� . �������� ������ > 1 
    void set1();                     // Function ��� ����� ����� . �������� ������ = 1 
    
    void get();                      // Function ��� �U�I� ����� � ����������� ����� ;
    void get1();                     // Function ��� �U�I� ����� ���������;  
	
    string Clean();                  //  Function ��� �������� �����; 
    
    string DispLay(){
    	return a;                    // Function  : �U�I� string a � class String
	}
	
	int Length(); 
	void Insert(string M, int p);
	
	void nika(){
		a = "FI-61 ";
	}
  };
     
  void String::Text_Konstryktor(){
   a = " I am Bogdan Rozhko :)"; 
  } 
  
    /*���� ����� */
    
void String::set()
{
	cout << "Sentence: " << endl; 
	getline(cin, a);
 }  
 
 void String::set1()
 {
 	cin.get();                       // �������� ������;
    cout<<  "SentencE: " << endl; 
	getline(cin, a);
 }
 
   /*�u�i� ����� */
   
 void String::get()
{
	cout << a << " " ; 
 }
     
void String::get1()
{
	cout << a <<  " " << endl; 
} 
 
 /*�������� �����*/
 
string String::Clean()
{
	a = "";
	return a;
}

int String::Length()
{
  return a.length();
}

void String::Insert(string M, int p)
{
 a.insert(p, M);
}

class Text
{
	private:
		int n;
		String* text
	public:
		/*Constructors*/

	Text(){
	 n = 1;                                      //  ����������� �� ������������ ��� �����  2
	 text = new String[n];
	 text[0].Text_Konstryktor();
	}

	Text(const Text& t){
	 n = t.n;
	 text = new String[n];
	 system("cls");
	 for ( int i = 0; i < n ; i++ ){            //  ����������� ��������� ��� ����� 2
		text[i] = t.text[i];
	 }
	}

	Text(int k){
		n = k;
		text = new String[n];
		for ( int i = 0; i < n ; i++ ){         //  ����������� � ���������� ��� ����� 2
		text[i].nika();
		}
	}

	~Text(){
		delete []text;                          //   ���������� ��� �����
	}


	/*�����Ͳ ����ֲ� . Function ��� ��������� ������ � ������ � ��� */

   void Masuv(int m);                        // Function ��� C�������� ������.
   void display();                           // Function ��� ��������� �� ����� ������.
   void Removal();                           // Function ��� ��������� �� ����� ������.

	/* ����ֲ� . Function ��� ����������� */

   void function_1(int Nstr, int nomer, string Rad);

   void function_2(int e);

   void function_3(int j);

   void function_4(int y);

   void function_5(string S);

   void function_6();
 };


   /* ���� ������ */

void Text::Masuv(int m)
{
   n = m;
   text = new String[n];

   for(int i = 0; i<n;i++ )
   {
	 if(i != 0)
	 {
	  cout << i << " ";
	  text[i].set();
	 }
	  if(i == 0)
	  {
	  cout << i << " ";
	  text[i].set1();
	  }
   }
}

  /* �u�i� ������ */

 void Text::display()
 {
   cout << "Text: \n";
   for(int i = 0; i < n; i++ )
   {
	text[i].get();
   }
 }
	/* ��������� ������*/
 void Text::Removal()
 {
  delete[]text;
 }

 /* ����ֲ� . Function ��� ����������� */

  //             ��������                 //

 void Text::function_2(int e)
 {
   for(int i = 0; i < n; i++ )
   {
	if(i == e)
	{                                            // �������� �������� ����� .
	text[i].Clean();
	}
   }
}

 void Text::function_6()
 {
   for(int i = 0; i < n; i++ )
   {                                             // �������� ������.
   text[i].Clean();
   }
 }

  //              ���������� (���������) ��������  //
void Text::function_3(int j)
{
	n = n - 1;                                  //��������� �������� �����;
	text1 = new String[n];
	for (int i = 0; i < n; i++)
	{
		if ( i < j)
		{
			text1[i]=text[i];
		} else
		{
			text1[i]=text[i+1];
		}
	}

	cout << "\n text1: " << endl;

	for (int i = 0; i < n; i++)
	{
		text1[i].get();
	}

	delete []text1;
}

void Text::function_4(int y)
{
  n = n + 1;                                     //���������� ����� � ������ ����;
  text1 = new String[n];

  for (int i = 0; i < n; i++ )
  {
   if(i < y)
	{
	 text1[i] = text[i];
	}
   if(i == y)
	{
	 text1[i].nika();
	}
   if(i > y)
	{
	 text1[i] = text[i-1];
	}
  }
  cout << "Text2: " << endl;
   for (int i = 0; i < n; i++ )
  {
	text1[i].get();
  }
}

void Text::function_1(int Nstr, int nomer, string Rad)
{                                                           // ��������� ������� � ������ �����, � ������ ����;
	for(int i = 0; i < n; i++)
 {
  if(i == Nstr)
  {
   if(nomer > text[i].Length())
   {
	cout << "Error :(" << endl;
   } else
   {
	text[i].Insert(Rad, nomer);
   }
  }
 }
}

int main()
{
	int p;
	int Elem;
	int Kilkist;
	int Elem_Masuva;
	string s;

	String cut;                                       // �������� ������ ������������

	cut.set();

	system("cls");

	cout << "constructor 1 - 3 (class string) zamov.: " << endl;

	String f;
	f.get();

	String f1("FI-61, Rozhko Bogdan, laba 2");        // �������� ������ ������������
	f1.get1();

	String f2(cut);                                   // �������� ������ ������������
	f2.get1();

	cut.Clean();

	cout << "\n\n ***************************** \n\n";

	cout << "Perevirka robotu: " << endl;
	cout << "string : ";
	cut.get();
	cout << endl;
	cout << "conctructors (cop): ";
	f2.get1();
	cout << endl;

	cout << "Objeck 1 class Text: " << endl;

	/*Text m;                                          // �������� ������ ������������
	m.function_6();
	m.Masuv(4);
	*/
	cout << "constructor 1 (class Text): " << endl;

	Text G1;
	G1.display();

	cout << "\n\n constructor 2 ... k-st elem: " << endl;
	cin >>  Kilkist;

	Text G2(Kilkist);
	G2.display();

	cout << "\n\n ****************************** \n\n";

	Text* tex;
	tex = new Text;

	cout << "\n\n ***************** \n\n";

	cout << "K-st elem. Masuva: ";
	cin >> Elem_Masuva;

	tex->Masuv(Elem_Masuva);

	system("cls");

	Text G3(*tex);

	tex->display();

	cout << "\n\n Menu: \n";

	cout << "1. Vstavka_Sumvola; \n";
	cout << "2. Chistka_String; \n";
	cout << "3. Vydalenia_Rechenia; \n";
	cout << "4. Vstavka_Stroky; \n";
	cout << "5. Poshuk_stroky \n";
	cout << "6. Chistka_testa; \n";

	cout <<"\n Kakoy pynkt: \n";

	cin>>p;

	system("cls");

	switch (p){
	case 1:
	 int Nomer_String;
	 int Nomer_sumvoka;

	   cout << "Nomer String: " << endl;
	   cin >> Nomer_String;
	   cout << "Nomer sumvola: " << endl;
	   cin >> Nomer_sumvoka;
	   cout << "Sumvol: " << endl;
	   cin.get();                       // �������� ������;
	   getline(cin, s);

	   tex->function_1(Nomer_String, Nomer_sumvoka, s);

	   tex->display();

	 break;
	case 2:
	int ochis;

	   cout << "Nomer String: " << endl;
	   cin >> ochis;

	   tex->function_2(ochis);

	   tex->display();

	  break;

	case 3:
		int stroka1;

	   cout << "Nomer String: " << endl;
	   cin >> stroka1;

	   tex->function_3(stroka1);

	  break;

	case 4:
	  int stroka2;

	   cout << "Nomer String: " << endl;
	   cin >> stroka2;

	   tex->function_4(stroka2);

	  break;

	case 5:
	   cout << "Rozrobka :) ....****...." << endl;
	  break;

	case 6:
	  tex->function_6();

	  tex->display();

	  break;

	default:
	   cout << "Wrong number! " << endl;
	}

	cout << endl;

	G3.display();

	delete tex;

	system("pause");
	return 0;
}   }


