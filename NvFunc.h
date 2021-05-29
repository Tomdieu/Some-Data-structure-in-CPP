#ifndef Navi

#define Navi

#include <iostream>
#include<string>

using namespace std;

//Implementation of List

template <class Li>

class List
{
private:
	int top,max;
	Li *array;
	Li *tmp;	

public:
	List(int size):max(size),array(new Li[size]),top(-1)
	{
		if(size<=0)
		{
			cerr<<"Invalid Size,Size Must Be >0 but size < 0 Was Found in List("<<size<<")"<<endl;
			abort();
		}
	
	};

	~List()
	{
		if(top > 0)
			delete array;
	};

	void append(Li x)
	{
		if(isFull())
		{
			cout<<"The List Is Full"<<endl;
		}
		else
		{
			if(isEmpty())
			{
				top = 0;
				array[top] = x; 
			}
			else
			{
				top += 1;
				array[top] = x;
			}
		}
	}

	void insert(Li x,int pos)
	{
		if(pos > max)
		{
			cout<<"Impossible to add "<<x<<" "<<pos<<"out of range"<<endl;
		}
		else
		{
			max = max+1;
			tmp = array;
			array = new Li[max];
			array = tmp;
			top = top+1;
			for(int i=max-1; i >= 0; i--)
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

	void display()
	{
		if(isEmpty())
		{
			cout<<"The List is Empty"<<endl;
		}
		else
		{
			cout<<"[";
			int i;
			for(i = 0; i <=top ; i++)
			{
				if(i == top)
					cout<<array[i];
				else
					cout<<array[i]<<" ,";
			}
			cout<<"]"<<endl;
		}
	}

	int lenght(){
		return ((top-0)+1);
	}
	Li pop()
	{
		if(isEmpty())
		{
			cerr<<"The List Is Empty Can Be Pop"<<endl;
			abort;	
		}
		Li d = array[top];
		top -= 1;
		return d;
	}
	Li pop(int index)
	{
		//At This Part if you Want to pop with a -ve index
		//it add top to the negative value and remove that value
		//fore axample
		/*let t =[7,6,5,4,3,2,1]
		*	if we want to get t[-1] it would be 1
		*	since len(t) = 7 and index of 1 = 6
		*	so t[-1] = t[len(t) + -1] 
		*/ 
		Li d;
		if(index<0 and (top + index)>0)
		{
			for(int i=0;i<=top;i++)
			{
				if(i == (top + index + 1))
				{
					d = array[i];
					for(int j = i;j<top;j++)
					{
						array[j] = array[j+1];
					}
				}
			}
			top -= 1;
		}
		else if(index>=0)
		{
			for(int i=0;i<=top;i++)
			{
				if(i == index)
				{
					d = array[i];
					for(int j = i;j<top;j++)
					{
						array[j] = array[j+1];
					}
				}
			}
			top -= 1;
		}	
		else
		{
			cerr<<"Are You Insane?\n";
			abort;
		}
		return d;
	}

	bool isEmpty()
	{
		if(top == -1)
			return true;
		return false;
	}
	bool isFull()
	{
		if(top == max)
			return true;
		return false;
	}
	void expand(int size)
	{
		if(size > max)
		{
			max = size;
			tmp = array;
			array = new Li(max);
			array = tmp;

		}
		else
		{
			cout<<"Can't Shrink List!";
		}
	}

	int indexOf(Li x)
	{
		return 0;
	}
	int count(Li x)
	{
		int n = 0;
		int i;
		for(i = 0;i<=top;i++){
			if(x = array[i])
			{
				n += 1;
			}
		}
		return n;
	}

	int size()
	{
		return max;
	}

	Li Max()
	{
		Li m = array[0];
		for(int i=1 ;i<=top;i++)
		{
			if(m < array[i])
			{
				m = array[i];
			}
		}
		return m;
	}

	Li Min()
	{
		Li m = array[0];
		for(int i=1 ;i<=top;i++)
		{
			if(m > array[i])
			{
				m = array[i];
			}
		}
		return m;
	}

	void sort()
	{
		//here i will used insertion sort since it is very easy and less code for it
		Li key;
		int i,j;
		for(i = 1 ;i <= top;i++)
		{
			key = array[i];
			j = i -1;
			while(j >= 0 and key <array[j])
			{
				array[j+1] = array[j];
				j-=1;
			}
			array[j+1] = key;
		}
	}

	Li &operator [](int x)
	{
		if(x<0 or x>=max)
		{
			cout<<"Are You Insane?\n";
			abort;
		}
		else
		{
			return array[x];
		}
	}

	//This My Function Can Be Used To Slices The List
	List operator ()(int begin,int end)
	{
		List<Li> Tmp(end-begin+1);
		if(begin >= 0 and end > 0)
		{
			cout<<"[";
			for(int i = begin; i <= end ;i++)
			{
				Tmp.append(array[i]);
				if(i == end)
					cout<<array[i];
				else
					cout<<array[i]<<", ";
			}
			cout<<"]";
			cout<<endl;
		}
		else
		{
			cout<<"Are You Insane?"<<endl;
		}
		

		return Tmp;
	}

	List operator +(List &other)
	{
		int l;

		l = max + other.size();
		//cout <<"After Combining The lenght = "<<l<<endl;
		
		List<Li> Tmp(l);

		for(int i=0;i<=top;i++)
		{
			Tmp.append(array[i]);
		}
		for(int i=0;i<=other.top;i++)
		{
			Tmp.append(other.array[i]);
		}

		return Tmp;
	}

	void operator = (List &other)
	{
		cout<<"Has enter ="<<endl;
		array = other.array;
		top = other.top;
		max = other.max;
		//return List(other.max,other.array,other.top);
	}

	bool operator == (List &other)
	{
		Li t1;
		int i=0;
		while(i<=top)
		{
			if(array[i] == other.array[i])
			{

			}
			else
			{
				return false;
			}
			i += 1;
		}
		return true;
	}

};


//Implementation of Stack

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

	T operator [](int x)
	{
		if(x<0 or x>current)
		{
			cerr<<"Could Not Access Stack["<<x<<"]"<<endl;
			abort;
		}
		
		return arr[x];	
	} 
};


//Implementation of Queue

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
		if(i<0 or i>max)
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



// Implementation of swapping
/*
* To used This Swapping Function
* This is The Syntax :
* swap<data_type>(variable1,variable2)
*
*	for example
*		int a,b;
*		a = 5;
*		b = 9;
*		swap<int>(a,b)
*/
template <typename li>
void swap(li &a,li &b)
{
	li t;
	t = a;
	a = b;
	b = t;
}

//Implementation of Bubble Sort
template <typename S>
void BubbleSort(S arr[],int size)
{
	int i,j;
	S tmp;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap<S>(arr[j],arr[j+1]);
			}
		}
	}	
}

//Implemation of Selection Sort

template <typename S>
void SelectionSort(S arr[],int size)
{
	int i,j,min;
	for(i = 0; i < size; i++)
	{	
		min = i;
		for(j = i+1; j < size; j++)
		{
			cout<<"arr["<<i<<"]="<<arr[min]<<"arr["<<j<<"]="<<arr[j]<<"\n";
			if(arr[j] < arr[min])
			{
				min = j;
				cout<<"Min = "<<arr[min]<<"\n";
			}
		}
		cout<<"swap\n";
		swap<S>(arr[min],arr[i]);
	}
}

//Implementation of Insertion Sort

template <typename S>
void InsertSort(S arr[],int size)
{
	int i,j;
	S key;
	for(i=1;i<size;i++)
	{	
		key = arr[i];
		j = i-1;
		while(j>=0 and key<arr[j])
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}



#endif