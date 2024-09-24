#include <iostream>
#include <string>
using namespace std;

int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string key = "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr";
    
    string message;
    
    // Get the secret message from the user
    cout << "Enter a secret message: ";
    getline(cin, message);

    // Encrypt the message
    for (char& c : message) {
        for (int i = 0; i < alphabet.size(); i++) {
            if (c == alphabet[i]) {
                c = key[i];
                break;
            }
        }
    }

    // Show the encrypted message
    cout << "Encrypted message: " << message << endl;

    // Decrypt the message back to original form
    for (char& c : message) {
        for (int i = 0; i < key.size(); i++) {
            if (c == key[i]) {
                c = alphabet[i];
                break;
            }
        }
    }

    // Show the decrypted message
    cout << "Decrypted message: " << message << endl;

    return 0;
}