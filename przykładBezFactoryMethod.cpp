#include <iostream>

class Katana {
 public:
  std::string Atack() const{
    return "Cut";
  }
  void repair() {}
  void dropWepon() {}
};

void ClientCode(const Katana& katana) {
  std::cout << "Ninja is tracking her target and "
            << katana.Atack() <<" his enemy."<< std::endl;
}

int main() {
  std::cout << std::endl;

  std::cout << "Ninja takes out the katana\n";
  Katana* katana = new Katana;
  ClientCode(*katana);

  std::cout << std::endl;

  delete katana;
}