#include <iostream>

class NinjaTool {
 public:
  virtual ~NinjaTool() {}
  virtual std::string Atack() const = 0;
  void repair() {}
  void dropWepon() {}
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

void ClientCode(const CreatorNinjaTools& tool) {
  std::cout << "Ninja is tracking her target and "
            << tool.ShowWepon() << std::endl;
}


int main() {
  std::cout << std::endl;

  std::cout << "Ninja takes out the katana\n";
  CreatorNinjaTools* katana = new CreateKatana();
  ClientCode(*katana);

  std::cout << std::endl;

  std::cout << "Ninja takes out the kunai\n";
  CreatorNinjaTools* kunai = new CreateKunai();
  ClientCode(*kunai);

  std::cout << std::endl;

  delete katana;
  delete kunai;
}
