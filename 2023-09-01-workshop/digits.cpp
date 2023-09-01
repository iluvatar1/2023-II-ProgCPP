#include <iostream>
#include <string>
/*
./a.out 123
0 1 2 3
./a.out 2048
2 0 4 8
./a.out 3065
3 0 6 5
./a.out 10
0 0 1 0
./a.out 12345
Number has more than 4 digits. Ignoring
./a.out -1
Negative number. Ignoring
./a.out 0
0 0 0 0
*/
void printDigit(int num);

int main(int argc, char **argv)
{
    int num = std::stoi(argv [1]);
    //necesito escribir los digitos de un numero de 4 cifras.
    printDigit(num);
    return 0;
}

void printDigit(int num){ // 8765
  if (0 <= num and num <= 9999){
    int remainder = num;
    for(int div = 1000; div >= 1; div = div/10) {
      std::cout << remainder/div << " ";
      remainder = remainder%div;
    }
    std::cout << "\n";
  } else if (num < 0){
    std::cout << "Negative number. Ignoring\n";
  } else { // numeros mayores a 9999
    std::cout << "Number has more than 4 digits. Ignoring\n";
  }
}
