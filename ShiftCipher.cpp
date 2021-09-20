/*****
Nama        : Putri Ainur Fitri
NPM         : 140810190052
Kelas       : B
Deskripsi   : Program Shift Chiper
*****/

#include <iostream>
#include <string.h>

using namespace std;

string encrypt(string plaintext, int key) {
   char x;
   string result="";
   for(int i = 0; i < plaintext.length() ; i++) {
      x = plaintext[i];
      // enkripsi untuk lowercase
      if(x >= 'a' && x <= 'z') {
         x += key; 
         if(x > 'z') {
            x = x - 'z' + 'a' - 1;
         }
         result += x;
      }
      // enkripsi untuk uppercase
      else if(x >= 'A' && x <= 'Z') {
         x += key;
         if(x > 'Z') {
            x = x - 'Z' + 'A' - 1;
         }
         result += x;
      }
      else if(x == ' ') {
         result += ' ';
      }
   }
   // print hasil enkripsi (ciphertext)
   return result;
}

string decrypt(string plaintext, int key) {
   char x;
   string result="";
   for(int i = 0; i < plaintext.length(); i++) {
      x = plaintext[i];
      // enkripsi untuk lowercase
      if(x >= 'a' && x <= 'z') {
         x -= key; 
         if(x < 'a') {
            x = x + 'z' - 'a' + 1;
         }
         result += x;
      }
      // enkripsi untuk uppercase
      else if(x >= 'A' && x <= 'Z') {
         x -= key;
         if(x < 'A') {
            x = x + 'Z' - 'A' + 1;
         }
         result += x;
      }
      else if(x == ' ') {
         result += ' ';
      }
   }
   // print hasil enkripsi (ciphertext)
   return result;
}

int main() {
   string teks;
   int key;
   char konfirmasi;
   cout << "============================================" << endl;
   cout << "==========[ PROGRAM SHIFT CIPHER ]==========" << endl;
   cout << "============================================" << endl;
   do {
      cout << "Tekan enter"<< endl;
      cin.ignore();
      cout << "Masukkan teks yang ingin dienkripsi : "; getline(cin, teks);
      cout << "Masukkan kunci : "; cin >> key;
      cout << "--------------------------------------------" << endl;
      string ciphertext = encrypt(teks, key);
      cout << "Hasil Enkripsi : "; cout << ciphertext << endl;
      cout << "Hasil Dekripsi : "; cout << decrypt(ciphertext, key) << endl;
      cout << "--------------------------------------------" << endl;
      cout << "Apakah Anda ingin mengulang program? (Y/N) : "; cin >> konfirmasi; cout << endl;
   } while(konfirmasi == 'Y' || konfirmasi == 'y');
}
