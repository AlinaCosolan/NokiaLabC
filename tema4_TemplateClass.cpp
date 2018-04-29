/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
template <class Arg, class... Args>
void sum (Arg arg, Args... args)
{
    cout<<"Maximul dintre:"<<arg<<" ";
    Arg max = arg;
    
    for(auto it :{args...})
    {
        cout<<it<<" ";
        if(max<it)
        max=it;
    }
    cout<<"este "<<max<<endl;
}
int main()
{
    sum(2,3,5,6,19,56,2,1,3);
    return 0;
}

