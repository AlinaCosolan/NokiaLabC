#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
vector< pair<int,int> >p;
void read(int nr_perechi)
{
	int first,second;
	for(int i =0 ; i<nr_perechi; i++)
		{
			cin>>first;
			cin>>second;
			p.push_back(pair<int, int> (first,second));
		}
}
void write(int nr_perechi)
{
	for(int i=0; i<nr_perechi; i++)
	{
		cout << "<"<< p[i].first << "," << p[i].second << ">"<< endl;
	}
}
bool sortare(const pair<int,int> &a , const pair<int,int> &b )
{
    return a.first<b.first;
}
void replace(int nr_perechi )
{
	for(int i=0; i<nr_perechi; i++)
	{
		if(p[i].second%2 ==0)
		{
		   	p[i].second=0;
		}
	}
}
int main()
{
	int nr_perechi,first,second;
		
	cout<<"Cate perechi?\n";
	cin>>nr_perechi;
	read(nr_perechi);
	cout<<"\nInital:\n";
	write(nr_perechi);
	
	sort(p.begin(), p.end());
	cout<<"\nDupa sortare\n";	
	write(nr_perechi);
	
	replace(nr_perechi);
	cout<<"\nDupa inlocuire\n";	
	write(nr_perechi);
	
}
