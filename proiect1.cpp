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
            cout<<sm.IpRangeStart<<" "<<sm.IpRangeStop<<" "<<sm.clients;
    }
};

template<class T> std::shared_ptr< StateMachine<T> > SMPtr_;
template<class T> std::shared_ptr< const StateMachine<T> > SMCPtr_;
 
template <class T,class U, class Z>
class Watcher
{
    public:
  	    list< shared_ptr< StateMachine<T> > > stateMachinesPtr_;
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
template <class T,class U, class Z>std::shared_ptr< Watcher<T,U,Z> > watcherPtr_;
template <class T,class U, class Z>std::shared_ptr< const Watcher<T,U,Z> > watcherCPtr_;

template <class T,class U, class Z> 
class Notifier
{
    private:
        vector<shared_ptr< const Watcher<T,U,Z> >> subscribers_;
};

template <class T,class U, class Z> std::shared_ptr<Notifier<T,U,Z>> notifierPtr_;
template <class T,class U, class Z> std::shared_ptr<const Notifier<T,U,Z>> notifierCPtr_; 

int main()
{
    struct SM sm;
    sm.IpRangeStart="100.10";
    sm.IpRangeStop="100.20";
    sm.clients=20;
    StateMachine<int> statemachine;
    statemachine.addInVector(sm);
    statemachine.print();
    return 0;
}

