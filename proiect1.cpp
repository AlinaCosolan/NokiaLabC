#include <iostream>
#include <vector>
#include <memory>
#include <list>
using namespace std;
struct SM
{
 	std::string IpRangeStart;
 	std::string IpRangeStop;
 	int clients;
};
template <class T> class StateMachine
{
    private:
       std::vector<SM> container_;
    public : void addInVector(SM sm)
    {
        container_.push_back(sm);
    }
    public: void print()
    {
        for(SM sm : container_) 
            cout<<sm.IpRangeStart<<" "<<sm.IpRangeStop<<" "<<sm.clients<<endl;
    }
    public: void ChangeNrClients(string IpRangeStart, string IpRangeStop,int change)
    {
        for(int i=0;i<container_.size();i++)
    	{
    	    if(IpRangeStop == container_[i].IpRangeStop && IpRangeStart == container_[i].IpRangeStart)
    	    {
    	        if(change==1)//increment
    	        {
    	            container_[i].clients=container_[i].clients+1;
    	        }
    	        else
    	           container_[i].clients=container_[i].clients-1;
    	    }
    	}
	}
};

template<class T> using SMPtr_ = std::shared_ptr< StateMachine<T>> ;
template<class T> using SMCPtr_= std::shared_ptr< const StateMachine<T>>;
 
template <class T,class U, class Z>
class Watcher
{
    public:
  	    list< SMPtr_<T> > stateMachinesPtr_;
  	    U message_; 
  	    Z relevance_;
  	    
    public:
  	Watcher(U message_,Z relevance_ )
  	{
  	    this.message_=message_;
  	    this.relevance_=relevance_;
  	}
  	void getMessage()
  	{
  	    return this.message_;
  	}
  	void getRelevance()
  	{
  	    return this.relevance_;
  	}
  	void setRelevance(Z relevance)
  	{
  	     this.relevance_=relevance;
  	}
  	void setMessage(Z Message)
  	{
  	     this.message_=Message;
  	}
  	
};

template <class T,class U, class Z> using watcherPtr_ = std::shared_ptr< Watcher<T,U,Z> > ;
template <class T,class U, class Z> using watcherCPtr_=std::shared_ptr< const Watcher<T,U,Z> > ;

template <class T,class U, class Z> 
class Notifier
{
    private:
        vector<watcherCPtr_<T,U,Z>> subscribers_;
};

template <class T,class U, class Z> using notifierPtr_ = std::shared_ptr<Notifier<T,U,Z>> ;
template <class T,class U, class Z> using notifierCPtr_= std::shared_ptr<const Notifier<T,U,Z>> ; 

int main()
{
    SM sm;
    sm.IpRangeStart="100.10";
    sm.IpRangeStop="100.20";
    sm.clients=20;
    
    SM sm1;
    sm1.IpRangeStart="100.21";
    sm1.IpRangeStop="100.30";
    sm1.clients=2;
    
    StateMachine<int> statemachine;
    statemachine.addInVector(sm);
    statemachine.addInVector(sm1);
    statemachine.print();
    
    cout<<endl;
    statemachine.ChangeNrClients("100.10","100.20",1);
    statemachine.ChangeNrClients("100.21","100.30",0);
    statemachine.print();
    
    return 0;
}
