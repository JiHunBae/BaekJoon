#include <stdio.h>

#define STRING_MAX_LENGTH 1000001
#define COUNT_ARRAY_SIZE 91
void convert_to_uppercase(char *str, int str_size);
void count_alphabet(char *str, int str_size, int *count);
void find_most_alphabet(char *str, int *count, int count_start, int count_end);
int main() {
    char str[STRING_MAX_LENGTH] = { 0 };
    int count[COUNT_ARRAY_SIZE] = { 0 };

    scanf("%s", str);
    convert_to_uppercase(str, STRING_MAX_LENGTH);
    count_alphabet(str, STRING_MAX_LENGTH, count);
    find_most_alphabet(str, count, 65, 90);

    return 0;
}

void convert_to_uppercase(char *str, int str_size) {
    int index;

    for(index = 0; index < str_size && str[index] != '\0'; ++index) {
        if(str[index] >= 'a' && str[index] <= 'z') {
            // 소문자인 경우 대문자로 문자 변환
            // 소문자 ASCII 값은 (97~122), 대문자 ASCII 값은 (65~90) 이므로 소문자에서 대문자로 변환 시 -32 필요
            str[index] -= 32;
        }
    }
}

void count_alphabet(char *str, int str_size, int *count) {
    int index;
    for(index = 0; index < str_size; ++index) {
        count[str[index]] += 1;
    }
}

void find_most_alphabet(char *str, int *count, int count_start, int count_end) {
    int index, max_value, max_index, only_one_alphabet;
    max_value = 0;
    only_one_alphabet = 1;
    for(index = count_start; index <= count_end; ++index) {
        if(count[index] > max_value) {
            max_value = count[index];
            max_index = index;
            only_one_alphabet = 1;
        }
        else if(count[index] == max_value) {
            only_one_alphabet = 0;
        }
    }

    if(only_one_alphabet) {
        printf("%c", max_index);
    }
    else
        printf("?");
}