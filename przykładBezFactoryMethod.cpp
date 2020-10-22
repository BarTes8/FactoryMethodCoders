#include <iostream>

class Katana {
 public:
  std::string Atack() const{
    return "Cut";
  }
  void repair() {}
  void cleanWepon() {}
};

class Kunai {
 public:
  std::string Atack() const{
    return "Throw";
  }
  void repair() {}
  void cleanWepon() {}
};

void ClientCode(int lengthToTarget) {

  if(lengthToTarget < 50){
    Katana* tool = new Katana;
    std::cout << "Ninja is tracking her target and "
            << tool -> Atack() << "his enemy" << std::endl;
    delete tool;
  }
  if(lengthToTarget >= 50){
    Kunai* tool = new Kunai;
    std::cout << "Ninja is tracking her target and "
            << tool -> Atack()<< "his enemy" << std::endl;
    delete tool;
  }

}

int main() {
  int lengthToTarget;

  std::cout << std::endl;

  std::cout << "Ninja sees a close target. ";
  lengthToTarget = 10;
  ClientCode(lengthToTarget);
  
  std::cout << std::endl;

  std::cout << "Ninja sees a distant target. ";
  lengthToTarget = 100;
  ClientCode(lengthToTarget);
  
  std::cout << std::endl;
}