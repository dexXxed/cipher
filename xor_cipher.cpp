#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Не были введены обязательные параметры!\n"
               "Запустите программу с ними!");
        return 1;
    }

    int i = 0, j = 0, c_char;
    unsigned char buffer[2048];
    char msg[2048], *key = argv[1];
    scanf("%[^\t\n]", (char *) &msg);

    for(;i < strlen(msg); i++, j++) {
        if(j >= strlen(key))
            j = 0;
        c_char = msg[i] ^ key[j];
        /* Это гарантия того, что зашифрованные буквы будут представлять собой удобочитаемые буквы,
         * а не некоторые специальные символы.
         * Фактические буквы начинаются с кода 32 в ASCII.
         */
        if(c_char < 32)
            c_char += 32;
        buffer[i] = c_char;
    }
    buffer[i] = '\0';
    printf("Сообщения: %s\nКлюч: %s\n", msg, key);
    printf("Зашифрованное сообщение: %s\n", buffer);
    return 0;
}
