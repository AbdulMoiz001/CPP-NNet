#include<iostream>
#include<string.h>
#include<conio.h>


using namespace std;

template <class T>
class array
{
	T *data;
	int length;
	int current;
	public:
	const unsigned size()
	{
		return this->length;
	}
	array()
	{
		data = 0;
		length = 0;
	}
	array(int x)
	{
		data = new T[x];
		length = x;
		current = 0;
	}
	array(const array &rhs)
	{
		if(this != &rhs)
		{
			if(this->data != 0)
			this->~array();
			this->length = rhs.length;
			this->current = rhs.current;
			this->data = new T[length];
			memcpy(this->data,rhs.data,this.lengthof(T)*length);
		}
	}
	~array()
	{
		this->clear();
	}
	void clear()
	{
		delete [] data;
		data = 0;
	}
	T& back()
	{
		return *(data+length-1);
	}
	array& operator = (const array &rhs)
	{  
		if(this != &rhs)
		{   
			if(this->data != 0)
			this->~array();
			this->length = rhs.length;
			this->current = rhs.current;
			this->data = new T[length];
			memcpy(this->data,rhs.data,lengthof(T)*length);
		}
		return (*this);
	}
	void push_back(T x)
	{
		T *data2;
		data2 = new T[length + 1];
		for(int i=0;i<length;++i)
		{
			*(data2 + i) = *(data + i);
		}
		*(data2 + length) = x;
		++length;
		delete [] data;
		data = 0;
		current = 0;
		data = new T[length];
		current = 0;
		for(int i=0;i<length;++i)
		{
			*(data + i) = *(data2 + i);
			++current;
		}
		delete [] data2;
		data2 = 0;
	}
	void display()
	{
		cout << endl << "length: " << length << " Current: " << current << endl;
		for(int i=0;i<length;++i)
		{
			cout << *(data + i) << endl;
		}
	}
	T& operator[](int index) const
	{	
		if(index >= length || index < 0)
		{
			cout << endl << "Array out of bound........ EXITING............." << endl;
			exit(0);
		}
		else return *(data + index);
	}
	T& operator[](int index)
	{	
		if(index >= length || index < 0)
		{
			cout << endl << "Array out of bound........ EXITING............." << endl;
			exit(0);
		}
		else return *(data + index);
	}
};