#include <thread>
#include <vector>
#include <condition_variable>
#include <mutex>
#include <iostream>
using namespace std;

class Manager
{
  std::thread theMaster;
  std::condition_variable cv;
  std::mutex mu;

  
 

  public:
    Manager(Manager& ma){
 
  }
  Manager(){

  }

};

 Manager manager()
 {
      static Manager m;
      return m;
}