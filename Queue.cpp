#include<iostream>

using namespace std;

template <class Qu>
class Queue
{
	int top,rear,max;
	Qu *array;
	
public:
	Queue(int size):top(-1),rear(-1),max(size-1),array(new Qu[size]){}
	~Queue(){delete array;}
	void enqueue(Qu x)
	{
		if(isFull())
		{
			cout<<"The Queue is Full!"<<endl;
		}
		else
		{
			if(isEmpty())
			{
				top = 0;
				rear = 0;
				array[top] = x;
			}
			else
			{
				//top += 1;
				array[++top] = x;
			}
		}
	}

	Qu dequeue()
	{
		if(isEmpty())
		{
			cout<<"The Queue is isEmpty"<<endl;
		}
		else
		{
			return array[rear++];
		}
	}

	bool isEmpty()
	{
		if(top == -1 and rear == -1)
			return true;
		return false;
	}
	bool isFull()
	{
		if(top == max)
		{
			return true;
		}
		return false;
	}
	void print()
	{
		if(isEmpty())
		{
			return;
		}
		std::cout<<"[";
		for(int i=top;i>=rear;i--)
		{
			if(i==0)
				std::cout<<array[i]<<"";
			else
				std::cout<<array[i]<<" ,";
		}
		std::cout<<"]\n";
	}
	Qu &operator [](int i)
	{
		if(i<0 or i>top)
		{
			cout<<"Are You Insane?";
		}
		else
		{
			return array[i];
		}
	}
	void insert(int x,int pos)
	{
		if(pos > max)
		{
			cout<<"Impossible to add "<<x<<" "<<pos<<"out of range"<<endl;
		}
		else
		{
			max = max+1;
			Qu *tmp = array;
			array = new Qu[max];
			array = tmp;
			top = max-1;
			for(int i=max-1; i >= rear; i--)
			{
				if(i == pos)
				{
					array[i] = x;
					break;
				}
				else
				{
					array[i] = array[i-1];
				}
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	Queue<int> qu(10);
	
	qu.enqueue(12);
	qu.enqueue(13);
	qu.enqueue(14);
	qu.enqueue(15);
	qu.enqueue(16);
	qu.enqueue(17);
	qu.enqueue(18);
	qu.enqueue(19);
	qu.enqueue(20);
	qu.print();
	qu.insert(99,0);
	qu.insert(1000,5);
	qu.print();

	return 0;
}