#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

class Player
{
private:
    string name;
    int hp;
    int hp_maximum;
    int bread;
    int emerald;
    /*
        已测试，正常。v0.1
    */

public:
    void Set(int hpt,int breadt,int emeraldt);
    void Test();
    bool Lose_Bread(int x);
    bool Lose_Emerald(int x);
    bool Lose_Hp(int x);
    void Gain_Bread(int x);
    void Gain_Emerald(int x);
    void Gain_Hp(int x);
};

class Event
{
private:
    string name;
    string description;
    int consumption;
    int reward;
    /*
        已测试，正常。v0.1
    */

public:
    void Set(string namet,string descriptiont,int consumptiont,int rewardt);
    void Test();
};

class Game_Mine
{
private:
    const int event_num=2;
    Player a;
    Event q[2];
    /*
        已测试，正常。v0.1
    */

public:
    void Init();
    void LoadingAnimation(int times=10,int style=1);
    void Explore();
}g;

int main()
{
    srand(time(NULL));
    g.Init();
    return 0;
}

void Player::Set(int hpt,int breadt,int emeraldt)
{
    this->hp=hpt;
    this->hp_maximum=20;
    this->bread=breadt;
    this->emerald=emeraldt;
}
void Player::Gain_Bread(int x)
{
    this->bread+=x;
}
void Player::Gain_Emerald(int x)
{
    this->emerald+x;
}
void Player::Gain_Hp(int x)
{
    this->hp=(this->hp+x>=this->hp_maximum)?this->hp_maximum:this->hp+x;
}
bool Player::Lose_Bread(int x)
{
    if(this->bread-x<0)return false;
    this->bread-=x;
    return true;
}
bool Player::Lose_Emerald(int x)
{
    if(this->emerald-x<0)return false;
    this->emerald-=x;
    return true;
}
bool Player::Lose_Hp(int x)
{
    if(this->hp-x<0)return false;
    this->hp-=x;
    return true;
}
void Player::Test()
{
    //cout<<this->hp_maximum<<endl;
    printf("hp: %d\nbread: %d\nemerald: %d\n",this->hp,this->bread,this->emerald);
}

void Event::Set(string namet,string descriptiont,int consumptiont,int rewardt)
{
    this->name=namet;
    this->description=descriptiont;
    this->consumption=consumptiont;
    this->reward=rewardt;
}
void Event::Test()
{
    cout<<"name: "<<this->name<<endl;
    cout<<"describe: "<<this->description<<endl;
    cout<<"consumption: "<<this->consumption<<endl;
    cout<<"reward: "<<this->reward<<endl;
}

void Game_Mine::Init()
{
    this->a.Set(20,5,5);
    //this->a.Test();

    this->q[1].Set("矿洞","危险",1,2);
    this->q[2].Set("村庄","交易中心",0,0);

    //this->q[1].Test();
    cout<<"**Mine version 0.11**\n";
    cout<<"作者 wmsx1\n";
    cout<<"按任意键继续___";
    char c=getch();
}
void Game_Mine::Explore()
{
    int event_id=(rand()%this->event_num)+1;
    //cout<<event_id;
    cout<<"你遇到了 "<<this->q[event_id]->name<<endl;
    cout<<"(探索消耗 "<<this->q[event_id]->bread<<" 个面包)"<<endl;
    cout<<"要探索吗?"<<endl<<"1/是"<<" "<<"0/否"<<endl;

}
void Game_Mine::LoadingAnimation(int times,int style)
{
    if(style==1)
    {
        cout<<"少女祈祷中..."<<endl;
        Sleep(1000);
        system("cls");
    }
    if(style==2)
    {
        int c=0;
        for(int i=1;i<=times;i++)
        {
            for(int j=1;j<=i-1;j++)cout<<" ";
            //printf("%c",(c)?'_':'几');
            if(c==0)
            {
                cout<<"几";
            }
            else cout<<"__";
            Sleep(200);
            system("cls");
            c^=1;
        }
    }
}
