#include <stdio.h>
#include <string.h>

int main() {
    char input_string[101] = { 0 };
    int index, string_length;
    int count = 0; // 크로아티아 알파벳의 개수
    gets(input_string);

    for(index = 0, string_length = strlen(input_string); index < string_length; ) {
        if(input_string[index] == 'c') {
            if(input_string[index + 1] == '=' || input_string[index + 1] == '-') {
                ++count;
                index += 2;
            } else
                ++index;
        } else if(input_string[index] == 'd') {
            if(input_string[index + 1] == 'z') {
                if(input_string[index + 2] == '=') {
                    count += 2;
                    index += 3;
                } else
                    ++index;
            } else if(input_string[index + 1] == '-') {
                ++count;
                index += 2;
            } else
                ++index;
        } else if(input_string[index] == 'l') {
            if(input_string[index + 1] == 'j') {
                ++count;
                index += 2;
            } else
                ++index;
        } else if(input_string[index] == 'n') {
            if(input_string[index + 1] == 'j') {
                ++count;
                index += 2;
            } else
                ++index;
        } else if(input_string[index] == 's') {
            if(input_string[index + 1] == '=') {
                ++count;
                index += 2;
            } else
                ++index;
        } else if(input_string[index] = 'z') {
            if(input_string[index + 1] == '=') {
                ++count;
                index += 2;
            } else
                ++index;
        } else {
            ++index;
        }
    }

    printf("%d", string_length - count);
    return 0;
}