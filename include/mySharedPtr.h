#ifndef MYSHAREDPTR_H
#define MYSHAREDPTR_H
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class mySharedPtr
{
public:
	//constructor
	mySharedPtr():ptr(new T()), count(new int(1)) {}
	explicit mySharedPtr(T *src) : ptr(src), count(new int(1)) {}
	explicit mySharedPtr(T value) : ptr(new T(value)), count(new int(1)) {}
	//copy constructor
	mySharedPtr(const mySharedPtr& rhs) : ptr(rhs.ptr), count(rhs.count)
	{
		++(*count);
	}
	mySharedPtr& operator=(const mySharedPtr& rhs)
	{
		++(*(rhs.count));
		if(--(*count) == 0)
		{
			delete ptr;
			delete count;
		}
		ptr = rhs.ptr;
		count = rhs.count;
		return *this;
	}
	~mySharedPtr()
	{
		if(--(*count) == 0)
		{
			delete ptr;
			delete count;
			cout << "deleted" << endl;
		}
		else
		{
			cout << "some pointer still refer to raw pointer" << endl;
		}
	}
	T* get() const { return ptr; }
	int use_count() const { return *count; }
	T operator*() { return *ptr; }
	T* operator->() { return ptr; }

protected:

private:
	T *ptr; //raw pointer
	int *count; //reference count
};

#endif // MYSHAREDPTR_H
