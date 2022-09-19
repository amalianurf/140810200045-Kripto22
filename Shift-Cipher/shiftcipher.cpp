/*
 * Nama     : Amalia Nur Fitri
 * NPM      : 140810200045
 * Kelas    : A
 * Tanggal  : 20 September 2022
 * Program  : Shift Cipher
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

void menu();
void encryption(std::string, int);
void decryption(std::string, int);
void ignoreLine();
void errorMessage(std::string);

int main() {
  char yesNo;

  do {
    yesNo = ' ';

    std::cout << "\n====== Shift Cipher ======\n" << std::endl;
    menu();

    while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
      std::cout << "\nMulai lagi (Y/N)\t: ";
      std::cin >> yesNo;
      std::cin.ignore();
    }
  } while(toupper(yesNo) == 'Y');

  return 0;
}

void menu() {
  std::string text;
  int key;

  std::cout << "Text\t: ";
  getline(std::cin, text);

  std::cout << "Key\t: ";
  std::cin >> key;
  key = key%26;

  int operation;
  std::cout << "\n==========================" << std::endl;
  std::cout << "1. Enkripsi\n";
  std::cout << "2. Dekripsi\n";
  std::cout << "Pilih operasi\t: ";
  std::cin >> operation;

  if(operation==1){
    encryption(text, key);
  } else if(operation==2){
    decryption(text, key);
  } else{
    errorMessage("Invalid operation, please try again");
  }
}

void encryption(std::string text, int key) {
  std::cout << "\n------Enkripsi------\n";
  std::cout << "Text\t: " << text << '\n';
  std::cout << "Key\t: " << key << "\n\n";

  std::string hasil = "";

  for (int i=0; i<text.length(); i++) {
    // jika input text terdapat spasi
    if (text[i]==' ') {
      hasil += ' ';
      continue;
    }
    // jika input text terdapat huruf kapital
    if (isupper(text[i]))
      hasil += char(int(text[i]+key-65)%26+65);
    // jika input text terdapat huruf non kapital
    else
      hasil += char(int(text[i]+key-97)%26+97);
  }

  std::cout << "Cipher Code\t: " << hasil << '\n';
}

void decryption(std::string text, int key) {
  std::cout << "\n------Dekripsi------\n";
  std::cout << "Text\t: " << text << '\n';
  std::cout << "Key\t: " << key << "\n\n";

  std::string hasil = "";

  for (int i=0; i<text.length(); i++) {
    // jika input text terdapat spasi
    if (text[i]==' ') {
      hasil += ' ';
      continue;
    }

    // jika input text terdapat huruf kapital
    if (isupper(text[i]))
      hasil += char(int(text[i]+(26-key)-65)%26+65);
    // jika input text terdapat huruf non kapital
    else
      hasil += char(int(text[i]+(26-key)-97)%26+97);
  }

  std::cout << "Plain Text\t: " << hasil << '\n';
}

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void errorMessage(std::string s) {
  std::cout << "\n//ERROR\n";
  std::cout << s.c_str() << '\n';
}