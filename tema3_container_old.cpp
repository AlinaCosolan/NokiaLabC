#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

class Container
{	
	public: Container();
//	virtual: ~Container();
	
	private: int integer;
	
	public : void set(int integer)
	{
		this->integer = integer;
	}
	public : int get()
	{
		return this->integer;
	}
	
};
bool is5(int i)
{
    return (i==5);
}
bool is10(int i)
{
    return (i==10);
}
int main()
{
    /*Container *a1 ;
    a1->set(2);
    cout<<a1->get();
    
     Container *a2 ;
    a2->set(2);
    cout<<a2->get();
    
     Container *a3 ;
    a3->set(2);
    cout<<a3->get();
    
     Container *a4 ;
    a4->set(2);
    cout<<a4->get();*/

	vector<int> a = {2,4,5,6,7,8,9,10};
	int i;
	vector<int>::iterator it1 = find_if (a.begin(),a.end(),is5);
    cout<<*it1<<endl;
    
	for(i=0;i<a.size();i++)
      cout<<a[i]<<" ";
    cout<<endl;
    
	a.erase(remove_if(a.begin(),a.end(),is10));
	
	for(i=0;i<a.size();i++)
      cout<<a[i]<<" ";
    cout<<endl;
}

