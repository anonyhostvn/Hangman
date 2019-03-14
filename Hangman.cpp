#include<bits/stdc++.h>
// #include <windows.h>
#include <time.h>
#include "utils.h"
#include "graphic.h"

using namespace std ;


vector<string> listWord ;

void readFile () {
    ifstream input("Oxford-3000.txt") ;
    string str ;
    while (getline(input , str)) listWord.push_back(str) ;
}

void gameLoop (const string ans) {
    int leng = ans.length() , level = 6 , numTrue = 0 ;
    bool alphabet[26] ;
    bool isGuessed[leng] ;
    memset(isGuessed , 0 , sizeof(isGuessed)) ;
    memset(alphabet , 0 , sizeof(alphabet)) ;

    while (true) {
        cout << figure[level] << endl ;
        for (int i = 0 ; i < leng ; i ++) cout << ((isGuessed[i]) ? ans[i] : '_' ) << endl;
        for (int i = 0 ; i < 26 ; i ++) if (!alphabet[i]) cout << (char) (i + (int) 'a') << " " ; cout << endl ;
        char c ;
        while (true) {
            c = getchar() ;
            if (!alphabet[(int) c - (int) 'a']) break ;
            cout << "Please type another character ! " << endl ;
        }

        bool have = false ;
        for (int i = 0 ; i < leng ; i ++) if (ans[i] == c) isGuessed[i] = true , have = true , numTrue ++ ;
        if (! have) level -- ;
        if (numTrue == leng) {
            cout << "You're win !" << endl ;
            return ;
        }
        if (level == 0) {
            cout << "You're Lose =( " << endl ;

            return ;
        }
    }
}

void process () {

    string ans = getARandomWord(listWord) ;

    gameLoop (ans) ;
}

int main () {
    srand(time(NULL)) ;
    readFile() ;
    process() ;
    return 0 ;
}
