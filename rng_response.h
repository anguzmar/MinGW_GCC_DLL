#include <string>

/* Define response struct */
struct RNG{
  unsigned long long int random_number = 0;  // Default value
  std::string error = "No error, all good";
};