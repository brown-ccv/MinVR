#include <map>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "Cxml.h"
#include "element.h"
#include "MinVRDataIndex.h"

int main() {
  MinVRDataIndex *index = new MinVRDataIndex;

  int a = 4;
  int b = 6;
  double f = 3.1415926;
  double g = 2.71828;

  index->addValueInt(std::string("henry"), a);
  index->addValueInt(std::string("ralph"), b);

  index->addValueDouble(std::string("george"), f);
  index->addValueDouble(std::string("mary"), g);

  index->addValue(std::string("<flora type=\"int\">3274</flora><morton type=\"float\">34.5</morton>"));

  std::string input = "";

  while(true) {
    std::cout << "Give a name: ";
    getline(std::cin, input);
    std::cout << "You entered:->" << input << "<-" << std::endl;

    MinVRDatumPtr p = index->getValue(input);

    if (p->getType() == MVRINT) {
      std::cout << "which gives->" << (p.intVal()->getValue()) << std::endl;
    } else {
      std::cout << "which gives->" << (p.doubleVal()->getValue()) << std::endl;
    }
    std::cout << "description: " << index->getDescription(input) << std::endl;
    std::cout << "serialization: " << index->serialize(input) << std::endl;
  }

}