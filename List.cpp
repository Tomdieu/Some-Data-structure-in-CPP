#include<iostream>

#define len(a) sizeof(a)/sizeof(*a)

using namespace std;


template <class Li>

class List
{
private:
	int top,max;
	Li *array;
	Li *tmp;
	bool flexible = false;	

public:
	List():top(-1)
	{
		flexible = true;
	}
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
		if(pos >= max)
		{
			cout<<"Impossible to add "<<x<<" at position = "<<pos<<" out of range"<<endl;
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

	//This function is use to increase the size of the List
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
		for(int i=0;i<=top;i++)
		{
			if(x == array[i])
			{
				return (i); 
			}
		}
		return -1;

	}
	int count(Li x)
	{
		int n = 0;
		int i;
		bool found;
		for(i = 0;i<=top;i++)
		{
			if(x == array[i])
			{
				n += 1;
				found = true;
				//cout<<n<<endl;
			}
		}
		if(found)
			return n;
		return -1;
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


	void swap(Li &a,Li &b)
	{
		Li t;
		t = a;
		a = b;
		b = t;
	}

	List reverse()
	{
		Li *tmp = new Li[max];
		List<Li> var(max);
		int j= top;
		int i=0;

		while(i<=top and j>=0)
		{
			tmp[i] = array[j];
			var.append(tmp[i]);
			j--;
			i++;
		}

		array = tmp;
		return var;
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
		if(x<0 or x>max)
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
		
		static List<Li> Tmp(l);

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

	/*void operator = (List other)

	{
		cout<<"Has enter = with lenght = "<<other.top<<endl;

		//static List<Li> tmp(other.top);

		array = other.array;
		top = other.top;
		max = other.max;
		
		
		tmp.array = other.array;
		tmp.top = other.top;

		return tmp;

	}*/

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


int main(int argc, char const *argv[])
{
	List<double> li(3);
	li.append(12.4);
	li.append(3);
	li.display();
	li.insert(45,0);
	li.display();
	cout<<"Lenght = "<<li.lenght()<<endl;
	cout<<"Max = "<<li.Max()<<endl;

	li.pop();
	li.display();
	li.reverse();
	li.display();
	li.insert(50,2);
	li.display();

	li.pop();

	List<double> p;//p(li.Max());

	p.display();

	li(0,1);



	return 0;
}
/*
	List<double> l1(3);
	l1.append(1);
	l1.append(2);
	l1.append(3);
	double t[]={40,1,-1,15,6};
	List<double> l2(len(t));
	for(int i=0;i<len(t);i++)
	{
		l2.append(t[i]);
	}
	l2.display();
	l2.pop(-3);
	l2.display();
	l2.pop(-1);
	l2.display();
	l2.sort();
	l2.display();
	l2(0,1);
	cout<<"Hey"<<endl;
	l2(0,1).display();

	(l1+li+l2).display();
	cout<<"N of "<<1<<" = "<<(l1+li+l2).count(1)<<endl;
	cout<<"-------------------------------\n";

	l2.display();
	l2.reverse();
	l2.display();

	cout<<"Index of "<<1<<" = "<<l2.indexOf(1)<<endl;
	l1.display();
	List<string> st(2);
	st.append("Hello World");
	st.display();


	//List<double> u(20);
	//u = (l1+li);
*/