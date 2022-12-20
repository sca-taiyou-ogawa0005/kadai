#include <iostream>
#include <string>

using namespace std;

class Player {
public:
  // Playerクラスのコンストラクタで引数にstringのポインタを渡す
  Player(const string &name = " ");
  // playerの名前を取得するメンバ関数
  string GetName() const;
  //次のPlayer* m_pNextの値を取得するメンバ関数
  Player *GetNext() const;
  //次のPlayer* m_pNextの値を用意するメンバ関数
  void SetNext(Player *next);

private:
  // playerの名前
  string m_Name;
  // 次のプレイヤ
  Player *m_pNext;
};
// playerコンストラクタでprivateのメンバ変数を初期化
Player::Player(const string &name)
    : m_Name(name),
      //ヌルポインタ
      m_pNext(0) {}
// playerの名前を取得するメンバ関数
string Player::GetName() const { return m_Name; }
//次のPlayer* m_pNextの値を取得するメンバ関数

Player *Player::GetNext() const { return m_pNext; }
//次のPlayer* m_pNextの値を用意するメンバ関数
void Player::SetNext(Player *next) { m_pNext = next; }

class Lobby {
  // Lobbyクラスのフレンド関数でプレイヤリストの名前を出力
  friend ostream &operator<<(ostream &os, const Lobby &aLobby);

public:
  // コンストラクタ
  Lobby();
  // デストラクタ
  ~Lobby();
  // LobbyにPlayerを入出するメンバ関数
  void AddPlayer();
  // Lobbyをplayerが離れるメンバ関数
  void RemovePlayer();
  // playerがロビーにいたとしてもいない状態に戻す関数
  void Clear();

private:
  // Lobbyのリストを指すメンバ変数
  Player *m_pHead;
};
//コンストラクタでm_pHeadメンバ変数の初期化
Lobby::Lobby()
    : //ヌルポインタ
      m_pHead(0) {}
//デストラクタでplayerがロビーにいたとしてもロビーをきれいにしない場合を考えている
Lobby::~Lobby() { Clear(); }

void Lobby::AddPlayer() {
  //新しいプレイヤノードを作成
  cout << "Please enter a name of the new player: ";
  // playerの名前入力
  string name;
  cin >> name;
  //================

  //先ほど入力したnameをPlayerクラスの動的メモリとして作成
  Player *pNewPlayer = new Player(name);

  //リストは空の状態だと、新しいプレイヤがリストの最初の項目
  // if list is empty, make head of list this new player
  if (m_pHead == 0) {
    m_pHead = pNewPlayer;
  }
  //　リストの最終項目に追加する
  // otherwise find the end of the list and add the player there
  else {
    //ここでpIterのリストの要素が空ではないので
    //リストの要素は今はもともとほうのm_pHeadを代入
    Player *pIter = m_pHead;
    while (pIter->GetNext() != 0) //pIterのリストが空じゃなければ
    {
      pIter = pIter->GetNext(); //m_pHeadを取得する
    }
    pIter->SetNext(pNewPlayer); // pIterのリストに入れる
  }
}

void Lobby::RemovePlayer() {
  // m_pHeadのリストに誰もいなかったら
  if (m_pHead == 0) {
    //ロビーに誰もいないので削除することができない
    cout << "The game lobby is empty.	No one to remove!\n";
  } else {
    //ロビーにだれかいたらm_pHeadの更新
    Player *pTemp = m_pHead;
    m_pHead = m_pHead->GetNext();
    delete pTemp; //交換用に用意したpTempを消す
  }
}
// playerがロビーにいたとしても空の状態に戻す関数
void Lobby::Clear() {
  while (m_pHead != 0) {
    RemovePlayer();
  }
}

ostream &operator<<(ostream &os, const Lobby &aLobby) {
  Player *pIter = aLobby.m_pHead;
  //現在のゲームロビーにいるプレイヤリスト：
  os << "\nHere's who's in the game lobby:\n";
  if (pIter == 0) {
    //ゲームロビーには誰もいない
    os << "The lobby is empty.\n";
  } else {
    while (pIter != 0) {
      //ロビーにいるプレイヤリストを出力
      os << pIter->GetName() << endl;
      //出力したものを取得する
      pIter = pIter->GetNext();
    }
  }

  return os;
}

int main() {
  // Lobbyクラスのインスタンス
  Lobby myLobby;
  // playerの選択
  int choice;

  do {
    cout << myLobby;
    //ゲームロビー
    cout << "\nGAME LOBBY\n";
    //プログラムを終了
    cout << "0 - Exit the program\n";
    //ゲームロビーにプレイヤを追加
    cout << "1 - Add a player to the lobby\n";
    //ゲームロビーからプレイヤを削除
    cout << "2 - Remove a player from the lobby\n";
    //ゲームロビーをクリアする
    cout << "3 - Clear the lobby\n";
    //選択を入力
    cout << endl << "Enter a choice: ";
    cin >> choice;

    switch (choice) {
    //さようなら
    case 0:
      cout << "Good-bye\n";
      break;
    case 1:
      myLobby.AddPlayer();
      break;
    case 2:
      myLobby.RemovePlayer();
      break;
    case 3:
      myLobby.Clear();
      break;
      //不正入力をしました
    default:
      cout << "That was not a valid choice\n";
    }
  } while (choice != 0);//選択肢が0を選ばれなかったら

  return 0;
}