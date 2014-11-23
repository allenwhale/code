#include <iostream>
using namespace std;
#ifndef __SMMH_ALLEN_
 #define __SMMH_ALLEN_
const int _MAX_SMMH_LEN=5000000;
template <class T>
class SMMH
{
private:
	int _len,MAX_SMMH_LEN;
	T *_d;
public:
	SMMH(int k=_MAX_SMMH_LEN)
	{
		MAX_SMMH_LEN=k;
		_len=1;
		_d=new T[MAX_SMMH_LEN+5];
	}
	inline int size()const
	{
		return _len-1;
	}
	inline bool empty()const
	{
		return this->size()==0;
	}
	inline T min()const
	{
		return this->_d[2];
	}
	inline T max()const
	{
		if(this->_len==2)return this->_d[2];
		return this->_d[3];
	}
	inline int push(T data)
	{
		if(this->size()+1>this->MAX_SMMH_LEN)return -1;
		int ptr=++this->_len;
		int grand,maxparent,minparent;
		while(true)
		{
			if(ptr&1&&data<this->_d[ptr^1])
			{
				this->_d[ptr]=this->_d[ptr^1];
				ptr^=1;
			}
			grand=ptr>>2;
			minparent=(grand<<1);
			maxparent=(grand<<1)|1;
			if(grand==0)break;
			if(data<_d[minparent])
			{
				this->_d[ptr]=this->_d[minparent];
				ptr=minparent;
			}
			else if(_d[maxparent]<data)
			{
				this->_d[ptr]=this->_d[maxparent];
				ptr=maxparent;
			}
			else break;
		}
		this->_d[ptr]=data;
		return 1;
	}
	inline int pop_min()
	{
		if(this->size()<1)return -1;
		if(this->size()==1)
		{
			--this->_len;
			return 1;
		}
		int ptr=2,minchild;
		T data=this->_d[this->_len--];
		while(true)
		{
			if((ptr&1)==0&&(ptr|1)<=this->size()&&this->_d[ptr|1]<data)
				swap(data,this->_d[(ptr|1)]);
			minchild=ptr<<1;
			if(minchild>this->_len)break;
			if((ptr+1)<<1<=this->_len&&this->_d[(ptr+1)<<1]<this->_d[minchild])
				minchild=(ptr+1)<<1;
			if(this->_d[minchild]<data)
			{
				this->_d[ptr]=this->_d[minchild];
				ptr=minchild;
			}
			else break;
		}
		this->_d[ptr]=data;
		return 1;
	}
	inline int pop_max()
	{
		if(this->size()<1)return -1;
		if(this->size()==1)
		{
			--this->_len;
			return 1;
		}
		int ptr=3,maxchild;
		T data=this->_d[this->_len--];
		while(true)
		{
			if(data<this->_d[ptr^1])
				swap(data,this->_d[ptr^1]);
			maxchild=((ptr|1)<<1)|1;
			if(maxchild>this->_len)break;
			if(((ptr<<1)|1)<=this->_len&&this->_d[maxchild]<this->_d[((ptr<<1)|1)])
				maxchild=(ptr<<1)|1;
			if(data<this->_d[maxchild])
			{
				this->_d[ptr]=this->_d[maxchild];
				ptr=maxchild;
			}
			else break;
		}
		this->_d[ptr]=data;
		return 1;
	}
	inline void print()
	{
		for(int i=2;i<=this->_len;i++)
			printf("%d ",this->_d[i]);
		puts("");
	}
};
#endif

