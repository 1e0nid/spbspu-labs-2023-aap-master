#include "lavran.hpp"
#include <limits>
#include <iostream>

int likhachev::readSequence(char *array)
{
  char *reserveArray;
  char *input = array;
  int max_size = 10;
  int size = 0;
  char c = ' ';
  std::cin >> std::noskipws;
  
  while (std::cin >> c && c != '\n')
  {
    input[size] = c;
    size++;

    if (size == max_size)
    {
      if (input == array) // Lavran TODO: Заменить логику
      {
        reserveArray = new char[max_size];
        if (!reserveArray) {
          delete[] reserveArray;
          throw std::logic_error("Error: not enough space for array\n");
        }

        copyCharArray(array, reserveArray, size);
        input = reserveArray;
        delete[] array;
      }
      else if (input == reserveArray)
      {
        array = new char[max_size];
        if (!array) {
          delete[] reserveArray;
          throw std::logic_error("Error: not enough space for array\n");
        }

        copyCharArray(reserveArray, array, size);
        input = array;
        delete[] reserveArray;
      }

      max_size *= 2;
    }
    
  }
// Lavran TODO: Заменить логику, убрать дублирование кода
  if (input == array) 
  {
    reserveArray = new char[size];
    if (!reserveArray) {
      delete[] reserveArray;
      throw std::logic_error("Error: not enough space for array\n");
    }

    copyCharArray(array, reserveArray, size);
    delete[] array;
  }

  array = new char[size];
  if (!array) {
    delete[] reserveArray;
    throw std::logic_error("Error: not enough space for array\n");
  }
  copyCharArray(reserveArray, array, size);
  delete[] reserveArray;
  std::cin >> std::noskipws;

  return size;
}

int likhachev::copyCharArray(char *copyFrom, char *copyTo, int size)
{
  for (int i = 0; i < size; i++)
  {
    copyTo[i] = copyFrom[i];
  }
}

void likhachev::outLine(char *array, int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << array[i];
  }
}

bool likhachev::strDoesHasSame(char *array1, int size1, char *array2, int size2)
{
  bool haseSame = false;

  int i = 0;
  int j = 0;
  while (i < size1 && !haseSame) {
    while (j < size2 && !haseSame) {
      if (array1[i] == array2[j]) {
        haseSame == true;
      }
    }
  }

  return haseSame;
}

int likhachev::strRemoveDigits(char *array, int size)
{
  char *reserveArray = new char[size];
  copyCharArray(array, reserveArray, size);

  int counter = 0;
  for (int i = 0; i < size; i++) {
    if (!charIsDigit(array[i])) {
      reserveArray[counter] = array[i];
    }
  }

  delete[] array;
  array = new char[counter];
  copyCharArray(reserveArray, array, counter);

  return counter;
}

bool likhachev::charIsDigit(char chr)
{
  if (chr == '0') {
    return true;
  }
  if (chr == '1') {
    return true;
  }
  if (chr == '2') {
    return true;
  }
  if (chr == '3') {
    return true;
  }
  if (chr == '4') {
    return true;
  }
  if (chr == '5') {
    return true;
  }
  if (chr == '6') {
    return true;
  }
  if (chr == '7') {
    return true;
  }
  if (chr == '8') {
    return true;
  }
  if (chr == '9') {
    return true;
  }

  return false;
}
