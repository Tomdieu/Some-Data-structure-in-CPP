#include<iostream>

using namespace std;

template <class T>
class Stack
{
	int current,max;
	T *arr;
public:
	Stack(int m):current(0),max(m),arr(new T[m]){}
	~Stack(){delete arr;}
	T pop()
	{
		if (current == 0)
		{
			abort();
		}
		else
		{
			return arr[--current];
		}
	}
	void push(int x)
	{
		if(current == max)
		{
			abort();
		}
		else
		{
			arr[current++] = x;
		}
	}
	//std::ostream &o
	void print()
	{
		std::cout<<"[";
		for(int i=current-1;i>=0;i--)
		{
			if(i==0)
				std::cout<<arr[i]<<"";
			else
				std::cout<<arr[i]<<" ,";
		}
		std::cout<<"]\n";
	}
	bool isEmpty()
	{
		if(current == 0)
			return true;
		return false;
	}
};


void reset(int &a)
{
	a = 0;
}
void bug(int &a)
{
	a = 42;
}

int main(int argc, char const *argv[])
{
	Stack<int> st(3);
	st.print();
	std::cout<<st.isEmpty()<<std::endl;
	st.push(3);
	st.push(2);
	st.push(1);
	st.print();
	st.pop();
	int x =3;
	st.print();
	st.push(5);
	std::cout<<"x = "<<x<<"\n";
	reset(x);
	std::cout<<"x = "<<x<<"\n";
	bug(x);
	std::cout<<"x = "<<x<<"\n";
	return 0;
}