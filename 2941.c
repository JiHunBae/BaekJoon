#include <stdio.h>
#include <string.h>

void input_new_string(char *stroe);

int main() {
    char *first_croatia_string = "c=";
    char *second_croatia_string = "c-";
    char *third_croatia_string = "dz=";
    char *fourth_croatia_string = "d-";
    char *fifth_croatia_string = "lj";
    char *sixth_croatia_string = "nj";
    char *seventh_croatia_string = "s=";
    char *ninth_croatia_string = "z=";

    int count = 0; // 크로아티아 알파벳의 개수
    int str_length; // 문자열 길이
    char input_string[101];
    char string_temp[4] = {0};

    input_new_string(input_string);
    str_length = strlen(input_string);

    int index, temp_string_index;

    for(index = 0, temp_string_index = 0; index < str_length; ++index) {
        string_temp[temp_string_index] = input_string[index];
        // 크로아티아 알파벳과 비교하는 함수 넣어야 함.
    }


    printf("%d", count);

    return 0;
}

void input_new_string(char *store) {
    scanf("%s", store);
}