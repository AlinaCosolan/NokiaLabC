#include <iostream>
#include<memory> 

using namespace std;
template<class Temp> class MyClass
{
    private:
        Temp elem;
    public:
        MyClass(Temp elem )
        {
            this->elem=elem;
        }
        Temp getElem()
        {
            return this->elem;
        }
        void setElem(Temp elem)
        {
            this->elem=elem;
        }
        ~MyClass(){}
};


int main()
{
    shared_ptr<MyClass<int>> s_ptr;
    s_ptr = make_shared<MyClass<int>>(73);
    cout<<"Shared-pointer:"<<endl;
    cout<< "Valoare = " << s_ptr.get()->getElem() << endl;
    
    s_ptr.get()->setElem(2);
    cout<< "Valoare = " << s_ptr.get()->getElem() << endl;
    
 
    //cout<<"Unique-pointer:"<<endl;
    //unique_ptr<MyClass<int>> u_ptr;
    //u_ptr = make_unique<MyClass<int>>(100);
    //cout<< "Valoare = " << u_ptr.get()->getElem() << endl;
    
    return 0;
}
