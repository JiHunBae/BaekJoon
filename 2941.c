#include <stdio.h>
#include <string.h>

typedef enum {false, true} bool;
void input_new_string(char *store);
bool check_croatia_string_and_align(char *string, int *string_index);
int main() {
    int count = 0; // 크로아티아 알파벳의 개수
    int str_length; // 문자열 길이
    char input_string[500]; // 전체 문자열
    char string_temp[4] = {0}; // 부분 문자열

    input_new_string(input_string);
    str_length = strlen(input_string);
    int index, temp_string_index, init_index;

    for(index = 0, temp_string_index = 0; index < str_length; ++index) {
        string_temp[temp_string_index] = input_string[index];
        if(check_croatia_string_and_align(string_temp, &temp_string_index)) {
            ++count;
            if(strlen(string_temp)) {
                count += strlen(string_temp);
                for(init_index = 0; init_index < 4; ++init_index)
                    string_temp[init_index] = '\0';

                temp_string_index = 0;
            }
        }
        else
            ++temp_string_index;
    }

    if(strlen(string_temp))
        count += strlen(string_temp);

    printf("%d", count);
    return 0;
}

void input_new_string(char *store) {
    gets(store);
}

bool check_croatia_string_and_align(char *string, int *string_index) {
    char *first_croatia_string = "c=";
    char *second_croatia_string = "c-";
    char *third_croatia_string = "dz=";
    char *fourth_croatia_string = "d-";
    char *fifth_croatia_string = "lj";
    char *sixth_croatia_string = "nj";
    char *seventh_croatia_string = "s=";
    char *eighth_croatia_string = "z=";

    int string_length = strlen(string);
    int index;

    if(string_length == 1) {
        if(string[0] != 'c' && string[0] != 'd' && string[0] != 'l' && string[0] != 'n' && string[0] != 's' && string[0] != 'z') {
            string[0] = '\0';
            *string_index = 0;
            return true;
        } else
            return false;
    } else if(string_length == 2) {
        if(string[0] == 'c') {
            if(!strcmp(string, first_croatia_string) || !strcmp(string, second_croatia_string)) {
                for(index = 0; index < string_length; ++index) // 배열 초기화
                    string[index] = '\0';

                *string_index = 0; // Index 값 변경
                return true;
            } else {
                string[0] = string[1];
                string[1] = '\0';
                *string_index = 1;

                return true;
            }
        } else if(string[0] == 'd') {
            if(!strcmp(string, fourth_croatia_string)) {
                for(index = 0; index < string_length; ++index) // 배열 초기화
                    string[index] = '\0';

                *string_index = 0; // Index 값 변경
                return true;
            } else if(string[1] != 'z'){
                string[0] = string[1];
                string[1] = '\0';
                *string_index = 1;

                return true;
            }
        } else if(string[0] == 'l' || string[0] == 'n') {
            if(!strcmp(string, fifth_croatia_string) || !strcmp(string, sixth_croatia_string)) {
                for(index = 0; index < string_length; ++index) // 배열 초기화
                    string[index] = '\0';

                *string_index = 0; // Index 값 변경
                return true;
            } else {
                string[0] = string[1];
                string[1] = '\0';
                *string_index = 1;

                return true;
            }
        } else if(string[0] == 's') {
            if(!strcmp(string, seventh_croatia_string)) {
                for(index = 0; index < string_length; ++index) // 배열 초기화
                    string[index] = '\0';

                *string_index = 0; // Index 값 변경
                return true;
            } else {
                string[0] = string[1];
                string[1] = '\0';
                *string_index = 1;

                return true;
            }
        } else if(string[0] == 'z') {
            if(!strcmp(string, eighth_croatia_string)) {
                for(index = 0; index < string_length; ++index) // 배열 초기화
                    string[index] = '\0';

                *string_index = 0; // Index 값 변경
                return true;
            } else {
                string[0] = string[1];
                string[1] = '\0';
                *string_index = 1;

                return true;
            }
        }
    } else if(string_length == 3) {
        if(!strcmp(string, third_croatia_string)) {
            for(index = 0; index < string_length; ++index) // 배열 초기화
                string[index] = '\0';

            *string_index = 0; // Index 값 변경
            return true;
        }
    }

    return false;
}