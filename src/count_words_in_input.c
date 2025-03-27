// count number of words in input sentence (ends with '.')
#include <stdio.h>
#include <stdbool.h>

bool not_word_char(char c){
    return (c == ' ' || c == '.');
}

int main(){
    char c;
    int n_words = 0;
    bool is_in_word = false;
    
    while (true){
        c = getchar();
        if (c == '.'){
            if (is_in_word){
                n_words++;
            }
            break;
        } else if (!is_in_word && !not_word_char(c)){
            is_in_word = true;
        } else if (is_in_word && not_word_char(c)){
            is_in_word = false;
            n_words++;
        } 
    }
    printf("End of sentence detected, number of words: %d\n", n_words);
    return 0;
}
