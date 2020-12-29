#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string txt);
int count_words(string txt);
int count_sentences(string txt);
int calculate_grade(float letters, float words, float sentences);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = calculate_grade(letters, words, sentences);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string txt)
{
    int letters = 0;
    for (int i = 0; i < strlen(txt); i++)
    {
        if (isalpha(txt[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string txt)
{
    int words = 1;
    for (int i = 0; i < strlen(txt); i++)
    {
        if (isspace(txt[i]))
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string txt)
{
    int sentences = 0;
    // Simplified sentence boundary detection for the purpose of this exercise!
    for (int i = 0; i < strlen(txt); i++)
    {
        if (txt[i] == '.' || txt[i] == '!' || txt[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

int calculate_grade(float letters, float words, float sentences)
{
    // average number of letters per 100 words
    float average_letters = letters * 100 / words;
    // average number of sentences per 100 words
    float average_sentences = sentences * 100 / words;

    // Coleman-Liau index
    float index = 0.0588 * average_letters - 0.296 * average_sentences - 15.8;
    int grade = round(index);
    return grade;
}
