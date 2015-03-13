#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>

using namespace std;

class Base{
	public:
		Base(){
			ptr = nullptr;
		}

		Base(char *s){
			ptr = new char[strlen(s) + 1];
			strcpy(ptr,s);
		}

		Base(const Base& b){
		}

		Base& operator = (const Base& b){
	/*	//Version 1 ----> 异常安全
			if(b == *this){
				return *this;
			}
			delete [] ptr;
			ptr = nullptr;
			ptr = new [strlen(b.ptr) + 1];//当new分配不成功时,ptr为空指针,会导致异常
			return * this;
		//Version 2
			if(b != *this){
				Base tmp(b);
				..
			}
			return *this;*/
		}

		virtual ~Base(){}
	private:
		char *ptr;
};

void print(initializer_list<string> li){
	for(auto l : li)
		cout<<l<<endl;
}


int main(){
	Base b;
	Base a(b);
	//cout<<(sizeof( Base))<<endl;
	//cout<<(sizeof( b))<<endl;
	//cout<<(sizeof(void*))<<endl;

	char arr[10]{'1','1','1','1','1','1','1','1','1','1'};
	cout<<sizeof(arr)<<endl;
	cout<<strlen(arr)<<endl;

	char* aptr = arr;
	cout<<sizeof(aptr)<<endl;
	typedef char (*ArrType)[10];
	ArrType ar = &arr;
	cout<<"haha:"<<sizeof(decltype(ar))<<endl;
	
	vector<int> v{1,2};
	//cout<<v.at(2)<<endl;

	string str;
	initializer_list<string> li{"a","b","c"};
	print(li);

}

