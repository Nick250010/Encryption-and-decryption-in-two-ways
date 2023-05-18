#include <iostream>
#include <string>

using namespace std;

string decrypt2(string message, int shift) {
    string result = "";
    for (int i = 0; i < message.length(); i++) {
        char c = message[i];
        // Если символ является буквой английского алфавита, то дешифруем его
        if (isalpha(c)) {
            c = toupper(c); // Приводим символ к верхнему регистру
            c = ((c - 65 - shift + 26) % 26) + 65; // Применяем алгоритм дешифрования Цезаря
        }
        result += c;
    }
    return result;
}

string decrypt(string encrypted, string keyword) {
    string decrypted = "";
    int keyIndex = 0;
    for (int i = 0; i < encrypted.length(); i++) {
        char c = encrypted[i];
        if (c >= 'a' && c <= 'z') {
            c = ((c - 'a') - (keyword[keyIndex] - 'a') + 26) % 26 + 'a';
            keyIndex = (keyIndex + 1) % keyword.length();
        }
        else if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A') - (keyword[keyIndex] - 'a') + 26) % 26 + 'A';
            keyIndex = (keyIndex + 1) % keyword.length();
        }
        decrypted += c;
    }
    return decrypted;
}


// Функция для шифрования сообщения
string encrypt2(string message, int shift) {
    string result = "";
    for (int i = 0; i < message.length(); i++) {
        char c = message[i];
        // Если символ является буквой английского алфавита, то шифруем его
        if (isalpha(c)) {
            c = toupper(c); // Приводим символ к верхнему регистру
            c = ((c - 65 + shift) % 26) + 65; // Применяем алгоритм шифрования Цезаря
        }
        result += c;
    }
    return result;
}

string encrypt(string message, string keyword) {
    string encrypted = "";
    int keyIndex = 0;
    for (int i = 0; i < message.length(); i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = ((c - 'a') + (keyword[keyIndex] - 'a')) % 26 + 'a';
            keyIndex = (keyIndex + 1) % keyword.length();
        }
        else if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A') + (keyword[keyIndex] - 'a')) % 26 + 'A';
            keyIndex = (keyIndex + 1) % keyword.length();
        }
        encrypted += c;
    }
    return encrypted;
}

int main() {
    int shift, t;
    cout << "выберите 1 если надо дешифровать. выберите 2 если надо зашифравать";
    cin >> t;
    string message;
    cout << "введите сообщение";
    cin >> message;
    string keyword;
    cout << "введите кодовое слово";
    cin >> keyword;
    cout << "введите отступ";
    cin >> shift;



    if (t == 2) {
        string encrypted = encrypt(message, keyword);
        cout << encrypted << endl;

        string encrypted_message = encrypt2(encrypted, shift);
        cout << "Зашифрованное сообщение: " << encrypted_message << endl;
    }
    else if (t == 1) {
        string decrypted_message = decrypt2(message, shift);
        cout << "Расшифрованное сообщение: " << decrypted_message << endl;

        string decrypted = decrypt(decrypted_message, keyword);
        cout << decrypted << endl;
    }
    return 0;
}
