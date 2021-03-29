#include <iostream>
#include "random.h"

int main(int argc, char** argv)
{
  RNG random_response = random();

  std::cout << "Number: " << random_response.random_number << std::endl;
  std::cout << "Error: " << random_response.error << std::endl;

  return EXIT_SUCCESS;
}