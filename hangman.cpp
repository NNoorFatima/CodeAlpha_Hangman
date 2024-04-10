#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

string word_dic[] = { "cat","dog","elephant","frog","goat","firefly","butterfly",
                      "pakistan","india","england","dubai","oman","syria","palestine",
                      "bread","butter","jam","toast","fruit","biscuit","chips"};

//creating all the hangman functions in this file
void hint(int ran)
{
    if(ran>=0 && ran<=6)
    {
        cout << "it is a animal" << endl;
    }
    else if (ran > 6 && ran <= 13)
    {
        cout << "it is a country" << endl;
    }
    else
    {   
        cout << "it is food. YUMM" << endl;

    }
}
void mk_hangman(int count)                  //deciding which hangman figure to display 
{
    switch (count)
    {
    case 0:                             //when user has entered no wrong letters; at the beginning of program
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 1:                         //when user has entered 1 wrong letter
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  0   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 2:                         //when user has entered 2 wrong letters
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  0   |" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 3:                         //when user has entered 3 wrong letters
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  0   |" << endl;
        cout << " /|   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 4:                         //when user has entered 4 wrong letters
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  0   |" << endl;
        cout << " /|\\  |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 5:                        //when user has entered 5 wrong letters 
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  0   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " /    |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 6:                     //when user has entered 6 wrong letters
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  0   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " / \\  |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        cout << "Sorry you lost, better luck next time loser!!" << endl;
        break;
    }

}
int check_letter(char ch, string word)//returns the position of this character if present
{
    for(int i=0 ;i<word.length();i++)
    {
        if (word[i] == ch)
            return i;
    }
    return -1;
}
void display(char* user,int n)
{
    for(int i=0 ;i<n ;i++)
    {
        if (user[i] == ' ')
            cout << "- ";
        else
            cout << user[i] << " ";
    
    }
            
     

}
bool CheckWinner(char* user, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (user[i] == ' ')
            return 0;
    }
    return 1;

}
int main()
{
    bool hint_ = 1;
    int size = sizeof(word_dic) / sizeof(word_dic[0]);//shows how many words are there
    srand(time(0));
    int random = rand() % size;
    int word_length = word_dic[random].length();
    char* user_guess = new char[word_length];
    for (int i = 0; i < word_length; i++)
        user_guess[i] = ' ';
    //display_dashes(word_length);
    cout << "The length of the word is " << word_length << endl;
    for (int i = 0; i < word_length; i++)
    {
        cout << "_ ";
    }
    cout << endl;
    char choice;
    int tries = -1;
    for(;tries<6;)
    {
        cout << "\nenter a letter you think is present in this word or if you want hint PRESS 1 ";
        cin >> choice;
        if (choice == '1'&& hint_==1)
        {
            hint_ = 0;
            hint(random);
        }
        else if (choice == '1' && hint_ == 0)
        {
            cout << "you used your hint before" << endl;
        }
        while (choice < 97 || choice>123)
        {
            
            //cout << "enter a valid letter" << endl;
            cout << "\nenter a valid letter you think is present in this word ";
            cin >> choice;
        }
        int pos=check_letter(choice,word_dic[random]);
        if (pos!=-1)
        {
            user_guess[pos] = choice;
        }
        else
        {
            tries++;
            mk_hangman(tries);
        }
        display(user_guess, word_length);
        bool Winner = CheckWinner(user_guess, word_length);
        if (Winner)
        {
            cout << "\nYOU WIN\n";
            break;
        }
    
    }


}
