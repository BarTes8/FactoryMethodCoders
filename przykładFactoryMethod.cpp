#include <iostream>

class NinjaTool {
 public:
  virtual ~NinjaTool() {}
  virtual std::string Atack() const = 0;
  void repair() {}
  void clearWeapon() {}
};

class Katana : public NinjaTool {
 public:
  std::string Atack() const override {
    return "Cut";
  }
};

class Kunai : public NinjaTool {
 public:
  std::string Atack() const override {
    return "Throw";
  }
};

class CreatorNinjaTools {
 public:
  virtual ~CreatorNinjaTools(){};
  virtual NinjaTool* MakeNinjaTool() const = 0;

  std::string ShowWepon() const {
    NinjaTool* tool = this->MakeNinjaTool();
    std::string result = tool->Atack() + " his enemy.";
    delete tool;
    return result;
  }
};

class CreateKatana : public CreatorNinjaTools {
 public:
  NinjaTool* MakeNinjaTool() const override {
    return new Katana();
  }
};

class CreateKunai : public CreatorNinjaTools {
 public:
  NinjaTool* MakeNinjaTool() const override {
    return new Kunai();
  }
};

void ClientCode(int lengthToTarget) {
  CreatorNinjaTools* tool;

  if(lengthToTarget < 50){
    tool = new CreateKatana();
  }
  if(lengthToTarget >= 50){
    tool = new CreateKunai();
  }

  std::cout << "Ninja is tracking her target and "
            << tool -> ShowWepon() << std::endl;
  
  delete tool;
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
