#include<iostream>

using namespace std;

template <typename St>

class Stack
{
	int top,lenght,max;
	St *tab;
	int zet,ztmp;
	bool flexible;
public:
	Stack()
	{
		flexible = true;
		lenght = 0;
		top=-1;
	}
	Stack(int size):top(-1),tab(new St[size]),max(size)
	{
		flexible = false;
	}
	~Stack()
	{
		delete tab;
	}
	void push(St x)
	{
		if(flexible)
		{
			//cout<<"Has Enter\n";
			if(isempty())
			{
				top = 1;
				tab = new St[top];
				tab[lenght] = x;
				top += 1;
				lenght += 1;
				zet = len() - 1;
				//cout<<"Has Enter 1 top "<<top<<" i "<<lenght<<"\n";
			}
			else
			{
				if(lenght >= 1)
				{
					St *tmp= new St[top];
					//cout<<"top = "<<top<<endl;
					tmp = tab;
					tab = new St[top];
					tab = tmp;
					tab[lenght] = x;
					top+=1;	
					//cout<<"Has Enter 1 top "<<top<<" i "<<lenght<<"\n";
					lenght+=1;
					zet = len() - 1;			
				}
			}
		}
		else
		{
			if(isfull())
			{
				cout<<"Stack Full"<<endl;
				abort;
			}
			tab[++top] = x;
			lenght+=1;
			zet = len() - 1;
		}
		
	}

	St pop()
	{
		St y;
		if(flexible)
		{
			if(isempty())
			{
				cout<<"The Stack is Empty!"<<endl;
				abort;
			}
			else
			{
				St d;
				d = tab[lenght-1];
				tab[lenght-1] = 0;
				lenght -= 1;
				zet = len() - 1;
				return d;
			}
		}		
		else
		{
			if(isempty())
			{
				cout<<"The Stack is Empty!"<<endl;
				abort;
			}
			else
			{
				St d;
				d = tab[lenght-1];
				lenght -= 1;
				tab[lenght] = 0;
				zet = len() - 1;
				return d;	
			}
		}
		return y;
	
	}

	bool isempty()
	{
		if(flexible)
		{
			if(lenght == 0)
				return true;
			return false;
		}
		else
		{
			if(top == -1)
				return true;
			return false;
		}
	}

	bool isfull()
	{
		if(!flexible)
		{
			if(top == max -1)
			{
				return true;
			}
			return false;
		}
		else
			return false;
	}

	void display()
	{
		std::cout<<"[";
		for(int j=lenght-1;j>=0;j--)
		{
			if(j==0)
				std::cout<<tab[j]<<"";
			else
				std::cout<<tab[j]<<" ,";
		}
		std::cout<<"]\n";
	}
	
	int len()
	{
		if(isempty())
		{
			return 0;
		}
		return lenght;
	}

	//This part i was just inspired by the next and hasNext method of Java from java.util.stack 
	St next()
	{
		if(flexible)
		{

			//cout<<"value of zet = "<<zet<<endl;
			//ui = zet;
			//zet -= 1;
			//cout<<" zet = "<<zet<<" "<<tab[ui]<<" ";
			return tab[zet--];
		}
		else
		{
			return tab[zet--];
		}
	}

	bool hasNext()
	{
		if(flexible)
		{
			if(zet >= 0)
			{
				return true;
			}
			else if(zet < 0)
				return false;
		}
		else
		{
			if(zet >= 0)
				return true;
			else if(zet < 0)
				return false;
		}
		return false;
	}
	St &operator [](int x)
	{
		if(flexible)
		{
			if(x<0 or x>=lenght)
			{
				cout<<"Are You Insane?\n";
				abort;
			}
			else
				return tab[x];
		}
		else
			if(x<0 or x>=max)
			{
				cout<<"Are You Insane?\n";
				abort;
			}
			return tab[lenght-1-x];
	}
};

/*class nova
{
	string name;
	int age;
public:
	nova():name(""),age(0)
	{

	}
	nova(string n,int a):name(n),age(a){}
	~nova();

	friend ostream& operator << (ostream& os,nova& f)
	{
		os<<f.name<<" "<<f.age<<endl;
		return os;
	}
};
*/

int main(int argc, char const *argv[])
{
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.push(7);
	st.push(8);
	st.push(9);
	st.push(10);
	st.push(11);
	st.push(12);
	st.push(13);
	st.push(14);
	st.push(15);

	st.display();

	cout<<"Size = "<<st.len()<<endl;

	Stack<char> s;
	s.push('A');
	s.push('B');
	s.push('C');
	s.push('D');
	s.push('E');
	s.push('F');
	s.push('G');
	s.display();

	s.pop();
	s.display();

	cout<<"Size = "<<s.len()<<endl;

	while(s.hasNext())
	{
		cout<<s.next()<<"\n";
	}

	/*while(! s.isempty())
	{
		s.pop();
		s.display();
	}*/
	cout<<"Lenght = "<<s.len()<<endl;

	Stack<int> b(4);
	b.push(1);
	b.push(2);
	b.push(3);
	b.push(4);
	cout<<"Dosplaying B using display\n";
	b.display();

	cout<<"Displaying using hasNext and next\n";
	while(b.hasNext())
	{
		cout<<b.next()<<" ";
	}

	cout<<"\n"<<b[0];

	return 0;
}