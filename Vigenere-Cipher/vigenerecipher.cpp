/*
 * Nama     : Amalia Nur Fitri
 * NPM      : 140810200045
 * Kelas    : A
 * Tanggal  : 05 Oktober 2022
 * Program  : Vigenere Cipher
*/

#include <iostream>
#include <limits>

void menu();
void encryption(std::string, std::string, std::string);
void decryption(std::string, std::string, std::string);
int mod(int, int);
void ignoreLine();
void errorMessage(std::string);

int main() {
    char yesNo;

    do {
        yesNo = ' ';

        std::cout << "\n====== Vigenere Cipher ======\n" << std::endl;
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
    std::string text, key, extKey;
    std::cout << "Pesan\t\t: ";
    getline(std::cin, text);

    std::cout << "Kunci\t\t: ";
    std::cin >> key;

    for(int i=0; i<text.length(); i++){
        int j;
        extKey.push_back(key[j++]);
        if(j==key.length()){
            j=0;
        }
    }

    int operation;
    std::cout << "\n==========================" << std::endl;
    std::cout << "1. Enkripsi\n";
    std::cout << "2. Dekripsi\n";
    std::cout << "Pilih operasi\t: ";
    std::cin >> operation;

    if(operation==1){
        encryption(text, key, extKey);
    } else if(operation==2){
        decryption(text, key, extKey);
    } else{
        errorMessage("Invalid operation, please try again");
    }
}

void encryption(std::string text, std::string key, std::string extKey) {
    std::cout << "\n------Enkripsi------\n";

    std::cout << "Pesan\t\t: " << text << std::endl;
    std::cout << "Kunci\t\t: " << key << std::endl;

    std::string encryp="";

    for (int i=0; i<text.length(); i++) {
    // jika input text terdapat spasi
    if (text[i]==' ') {
        encryp += ' ';
        continue;
    }

    if (isupper(text[i]))
        encryp += char(mod(int((text[i]-65)+(extKey[i]-65)), 26)+65);
    else
        encryp += char(mod(int((text[i]-97)+(extKey[i]-97)), 26)+97);
    }

    std::cout << "Ciphertext\t: " << encryp << std::endl;
}

void decryption(std::string text, std::string key, std::string extKey) {
    std::cout << "\n------Dekripsi------\n";

    std::cout << "Pesan\t\t: " << text << std::endl;
    std::cout << "Kunci\t\t: " << key << std::endl;

    std::string decryp="";

    for (int i=0; i<text.length(); i++) {
    if (text[i]==' ') {
        decryp += ' ';
        continue;
    }

    if (isupper(text[i]))
        decryp += char(mod(int((text[i]-65)-(extKey[i]-65)), 26)+65);
    else
        decryp += char(mod(int((text[i]-97)-(extKey[i]-97)), 26)+97);
    }

    std::cout << "Plaintext\t: " << decryp << std::endl;
}

int mod(int a, int b) { return (a%b+b)%b;};

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void errorMessage(std::string s) {
  std::cout << "\n//ERROR\n";
  std::cout << s.c_str() << '\n';
}