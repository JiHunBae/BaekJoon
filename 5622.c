#include <stdio.h>

#define ARRAY_MAX_SIZE 91

int main() {
    char word[16] = {0};
    int second[ARRAY_MAX_SIZE] = {0};
    int index, value = 0;

    scanf("%s", word);

    for (index = 65; index <= 90; ++index) {
        if (index >= 65 && index < 68) // A ~ C
            second[index] = 3;
        else if (index < 71) // D ~ F
            second[index] = 4;
        else if (index < 74) // G ~ I
            second[index] = 5;
        else if (index < 77) // J ~ L
            second[index] = 6;
        else if (index < 80) // M ~ O
            second[index] = 7;
        else if (index < 84) // P ~ S
            second[index] = 8;
        else if (index < 87) // T ~ V
            second[index] = 9;
        else // W ~ Z
            second[index] = 10;
    }

    for (index = 0; index < sizeof(word) && word[index] != '\0'; ++index) {
        value += second[word[index]];
    }

    printf("%d", value);

    return 0;
}