

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class Cake
{
	protected: 
		int height;
		int weight;
	protected:
		int pricePerKilogram;
	public:
		Cake();
	
	public: Cake(int h, int w,int p)
	{
		height=h;
		weight=w;
		pricePerKilogram=p;
	}
	virtual void afisare()
   {
	   cout<<"Height: "<<this->height<<endl;
	   cout<<"Weight: "<<this->weight<<endl;
   }
	public:virtual void price()=0;
		
};
class ChocolateCake : public Cake
{
	private: 	char *cream;
	
	public:ChocolateCake(int h, int w,int p,char *cream):Cake(h,w,p)
	{
		this->cream=new char[strlen(cream)+1];
		strcpy(this->cream,cream);
	}
	void afisare()
	{
		cout<<"ChocolateCake"<<endl;
		Cake::afisare();
		cout<<"Cream"<<this->cream<<endl;
	}
	void price()
	{
		int a = weight * pricePerKilogram;
		cout<<"Price="<<a<<endl;
	}
	
};
class VanillaCake : public Cake
{
	private: 	char *cream;
				int frosting;
				
	public:VanillaCake(int h, int w,int p,int f,char *cream):Cake(h,w,p)
	{
		this->cream=new char[strlen(cream)+1];
		strcpy(this->cream,cream);
		this->frosting=f;	
	}
	void afisare()
	{
		cout<<"VanillaCake"<<endl;
		Cake::afisare();
		cout<<"Crem: "<<this->cream<<endl;
		cout<<"Frosting: "<<this->frosting<<endl;
	}
	void price()
	{
		int a=(this->weight+this->frosting)*pricePerKilogram;
		cout<<"Price="<<a<<endl;
	}
};
int main()
{
	char f[100];
	cin>>f;
	Cake *c1 = new VanillaCake(1,1,1,1,f);
	Cake *c2 = new VanillaCake(2,2,2,2,f);
	Cake *c3 = new VanillaCake(3,3,3,3,f);
	Cake *c4 = new VanillaCake(4,4,4,4,f);
	Cake *c5 = new VanillaCake(5,5,5,5,f);
	char w[100];
	cin>>w;
	Cake *c6 = new ChocolateCake(6,6,6,w);
	Cake *c7 = new ChocolateCake(7,7,7,w);
	Cake *c8 = new ChocolateCake(8,8,8,w);
	Cake *c9 = new ChocolateCake(9,9,9,w);
	Cake *c10 = new ChocolateCake(10,10,10,w);
	c1->price();
	c1->afisare();
	
	c2->afisare();
	c2->price();
	c3->afisare();
	c3->price();
	c4->afisare();
	c4->price();
	c5->afisare();
	c5->price();
	c6->afisare();
	c6->price();
	c7->afisare();
	c7->price();
	c8->afisare();
	c8->price();
	c9->afisare();
	c9->price();
	c10->afisare();
	c10->price();
	
	
	return 0;
	
}
