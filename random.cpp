#include <windows.h>
#include <bcrypt.h>
#include <stdio.h>
#include <string>
#include "random.h"

RNG ADDCALL random()
{
  NTSTATUS status;

  // Initialize response
  RNG response = {};

  // Provider parameters
  BCRYPT_ALG_HANDLE phAlgorithm;  // Pointer to variable that receives the handle
  LPCWSTR algorithm_requested = BCRYPT_RNG_ALGORITHM;
  LPCWSTR pszImplementation = NULL;  // Use default provider for the specified algorithm
  ULONG dwflags = 0;  // Flags that modify the behavior of the function 

  // RNG Parameters
  unsigned long long int* random_number_address_aux;

  unsigned long long int random_int;  // Use this variable to define the size of the random number. A bit scuffed
  PUCHAR random_number_address = (PUCHAR)&random_int;
  ULONG RNG_dwflags = 0;

  // Initialize the CNG (Cryptographic API: Next Generation)
  status = BCryptOpenAlgorithmProvider(&phAlgorithm, algorithm_requested, pszImplementation, dwflags);

  if(!BCRYPT_SUCCESS(status)){
    response.error = "Failed to open Algorithm Provider";
    return response;
  }

  status = BCryptGenRandom(phAlgorithm, random_number_address, sizeof(random_int), RNG_dwflags);
  if(!BCRYPT_SUCCESS(status)){
    response.error = "Failed to call BCryptGenRandom";
    return response;
  }

  random_number_address_aux = (unsigned long long int*)random_number_address;
  response.random_number = *random_number_address_aux;

  // Close the provider. Not necessary but I guess I'll do it
  status = BCryptCloseAlgorithmProvider(phAlgorithm, dwflags);
  if(!BCRYPT_SUCCESS(status)){
    response.error = "Failed to close Algorithm Provier";
    return response;
  }

  return response;
}