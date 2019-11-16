#include <stdio.h>

int sequences[2001];
int dp[2001][2001];
int isPallindrome(int start, int end);

int main() {
    int sequence_length;

    int number_of_questions;
    int count, a;
    int first, second, mid;
    int left, right;
    scanf("%d", &sequence_length);
    for (count = 1; count <= sequence_length; ++count) {
        scanf("%d", &sequences[count]);
        for(a = 1; a <= sequence_length; ++a)
            dp[count][a] = -1;
    }

    scanf("%d", &number_of_questions);
    for (count = 0; count < number_of_questions; ++count) {
        scanf("%d %d", &first, &second);
        printf("%d\n", isPallindrome(first, second));
    }
}

int isPallindrome(int start, int end) {
    if(dp[start][end] != -1) {
        return dp[start][end];
    }

    if(start == end) {
        dp[start][end] = 1;
        return dp[start][end];
    }

    if(start == end - 1) {
        if(sequences[start] == sequences[end])
            dp[start][end] = 1;
        else
            dp[start][end] = 0;

        return dp[start][end];
    }

    if(sequences[start] == sequences[end])
        dp[start][end] = isPallindrome(start + 1, end - 1);
    else
        dp[start][end] = 0;

    return dp[start][end];
}