#include <stdio.h>
#include <string.h>

void check_array_init(short* array, int array_length);

int main() {
    int number_of_words; // 단어의 개수
    int word_count; // 문자 바복을 위한 횟수를 체크하는 변수
    int index; // string의 Index
    char string[101] = { 0 }; // 문자열
    short alphabet_check[123] = { 0 };
    int string_length;
    int group_word_count = 0;

    scanf("%d", &number_of_words);
    gets(string); // 개행 제거
    for(word_count = 0; word_count < number_of_words; ++word_count) {
        gets(string);
        string_length = strlen(string);
        check_array_init(alphabet_check, 123); // 체크 배열 초기화

        for(index = 0; index < string_length; ++index) {
            if(alphabet_check[string[index]] == 0) { // 한 번도 안나온 알파벳인 경우
                alphabet_check[string[index]] = 1;


                if(string[index] != string[index + 1]) // 한 번 나오고 이어지지 않는 경우
                    alphabet_check[string[index]] = 2;
            } else if(alphabet_check[string[index]] == 1) { // 나온적이 있는 알파벳인 경우
                if(string[index] != string[index + 1]) // 연속된 알파벳의 끝
                    alphabet_check[string[index]] = 2;
            } else if(alphabet_check[string[index]] == 2) {
                break;
            }

            if(index + 1 == string_length)
                ++group_word_count;
        }
    }

    printf("%d", group_word_count);
}

void check_array_init(short *array, int array_length) {
    int index;
    for(index = 0; index < array_length; ++index) {
        array[index] = 0;
    }
}