#include <iostream>
#include <random>
#include <time.h>
using namespace std;
int main() 
{
  int chose;
  int random;
  bool death = false;
  int count = 0;
  
  
  cin >> chose;
  while(1)
    {
        int r = rand() % 1;
        cout << "右:0   左1";
        cout << "どっちに進む?\n";
        cout << r << endl;
        if(count << 5)
        {//last
            if(chose == r)
            {
                cout << "魔王に勝った\n";
            }
            else if(chose != r)
            {
                cout << "敵に負けた\n";
                death = true;
                break;
            }
            else
            {
                cout << "入力ミス。もう一度入力してください\n";
            }
        }
        if(chose == r)
        {
            cout << "アイテムゲット\n";
            count ++;
            cout << "次へ進む\n";
        }
        else if(chose != r)
        {
            cout << "敵に負けた\n";
            death = true;
            break;
        }
        else
        {
            cout << "入力ミス。もう一度入力してください\n";
        }
    
    
        if(death)
        {
            cout << "gameover\n";
        }
        else 
        {
            cout << "gameclear\n";
        }
    }
}