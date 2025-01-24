#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class bank
{
private:
   int money;
   string username, password;

public:
   void makeaccount();
   void balance();
   void withdraw();
   void deposit();
   void changepassword();
};
void bank::makeaccount()
{
   int money;
   string username, password;
   ofstream input;
   input.open("user.txt");
   cout << "\n Enter your name(without space) :";
   cin >> username;
   input << username;
   cout << " Username created : " << username;
   cout << "\n \n Enter password : ";
   cin >> password;
   cout << " Password created : " << password;
   input << "\n"
         << password;
   cout << "\n \n Enter ammount of money : $";
   cin >> money;
   cout << " Money added : $" << money;
   input << "\n"
         << money;
   input << "\n0";
   input.close();
   cout << "\n Your Account created successfully";
}
void bank::balance()
{
   string str, chk_password;
   int money;
   ifstream output;
   output.open("user.txt");
   getline(output, username);
   getline(output, password);
   getline(output, str);
   money = stoi(str);
   output.close();
   cout << "\nVerify your password first : ";
   cin >> chk_password;
   if (chk_password == password)
   {
      cout << "The balance in your account is : $" << money << "\n";
   }
   else
   {
      cout << "\nPassword entered is incorrect\n";
   }
}
void bank::withdraw()
{
   string str, inhnd, chk_password;
   int money, inhand_money;
   int with;
   ifstream output;
   output.open("user.txt");
   getline(output, username);
   getline(output, password);
   getline(output, str);
   getline(output, inhnd);
   money = stoi(str);
   inhand_money = stoi(inhnd);
   output.close();
   cout << "\nVerify your password first : ";
   cin >> chk_password;
   if (chk_password == password)
   {
      cout << "\n Enter ammount to be withdrawn :$";
      cin >> with;
      if (with > money)
      {
         cout << "\nCan't withdraw ammount more than ammount in your balance \nYour current balance is :$" << money;
      }
      else
      {
         int newwm = money - with; // newwm=new with money
         cout << " The balance in your account is : $" << newwm << endl;
         inhand_money += with;
         ofstream input;
         input.open("user.txt", ios::out);
         input << username;
         input << "\n"
               << password;
         input << "\n"
               << newwm;
         input << "\n"
               << inhand_money;
         input.close();
         cout << "\n Ammount withdrawn successfully";
      }
   }
   else
   {
      cout << "\nPassword entered is incorrect\n";
   }
}
void bank::deposit()
{
   int money, deposit, inhnd_money;
   string str, inhnd, chk_password;
   ifstream output;
   output.open("user.txt");
   getline(output, username);
   getline(output, password);
   getline(output, str);
   getline(output, inhnd);
   money = stoi(str);
   inhnd_money = stoi(inhnd);
   output.close();
   cout << "\nVerify your password first : ";
   cin >> chk_password;
   if (chk_password == password)
   {
      cout << "\n Your current balance is : $" << money;
      cout << "\n Enter the ammount you want to deposit in your account : $";
      cin >> deposit;
      if (deposit > inhnd_money)
      {
         cout << "\n Error! Sorry but have only $" << inhnd_money << " in your hand";
      }
      else
      {
         int new_inhnd_money = inhnd_money - deposit;
         int newdpm = deposit + money; // newdpm= new deposit money
         cout << "\n Money deposited in your account : $" << deposit;
         cout << "\n Your updated bank balance is : $" << newdpm;
         ofstream input;
         input.open("user.txt", ios::out);
         input << username;
         input << "\n"
               << password;
         input << "\n"
               << newdpm;
         input << "\n"
               << new_inhnd_money;
         input.close();
         cout << "\n Ammount deposited successfully";
      }
   }
   else
   {
      cout << "\nPassword entered is incorrect\n";
   }
}
void bank::changepassword()
{
   // to modify the username and password
   int money, inhnd_money;
   string password, str, inhnd, chk_password, new_password;
   ifstream output;
   output.open("user.txt");
   getline(output, username);
   getline(output, password);
   getline(output, str);
   getline(output, inhnd);
   money = stoi(str);
   inhnd_money = stoi(inhnd);
   output.close();
   cout << "\nVerify your password first : ";
   cin >> chk_password;
   if (chk_password == password)
   {
      cout << "\n The Password is correct!";
      ofstream input;
      input.open("user.txt", ios::out);
      input << username;
      cout << "\nEnter new password : ";
      cin >> new_password;
      input << "\n"
            << new_password;
      input << "\n"
            << money;
      input << "\n"
            << inhnd_money;
      password = new_password;
      input.close();
      cout << "\n Password changed successfully";
   }
   else
   {
      cout << "\nPassword entered is incorrect\n";
   }
}
class Casino : private bank
{
public:
   void roulette(int opt);
   void slots();
   void spin_the_wheel();
};
void Casino::roulette(int opt) // ROULETTE
{
   int money, inhnd_money, new_bet, new_inhnd_money, choice, bet;
   string password, str, inhnd, chk_password, new_password, username;
   ifstream output;
   output.open("user.txt");
   getline(output, username);
   getline(output, password);
   getline(output, str);
   getline(output, inhnd);
   money = stoi(str);
   inhnd_money = stoi(inhnd);
   output.close();
   srand(time(0));
   int roulette_ball = rand() % 37;
   int roulette_color = rand() % 2;
   switch (opt)
   {
   case 1:
      cout << "You have choosen to bet on (colors)";
      cout << "\n Enter the color you want to bet on (1 for red and 2 for black)"; // COLOR
      cout << "\n-->";
      cin >> choice;
      choice -= 1;
      cout << "\n Enter the amount of bet here:";
      cout << "\n-->";
      cin >> bet;
      if (bet > inhnd_money)
      {
         cout << "\n Insufficient amount in hand. You only have $" << inhnd_money << " in your hand";
      }
      else
      {
         if (choice <= 1)
         {
            if (choice == roulette_color)
            {
               if (choice == 1 && roulette_color == 1)
               {
                  cout << "\n The ball landed on Black " << roulette_ball;
                  cout << "\n you won!!";
                  new_bet = bet * 2;
                  new_inhnd_money = inhnd_money + new_bet;
                  ofstream input;
                  input.open("user.txt", ios::out);
                  input << username;
                  input << "\n"
                        << password;
                  input << "\n"
                        << money;
                  input << "\n"
                        << new_inhnd_money;
                  input.close();
               }
               if (choice == 0 && roulette_color == 0)
               {
                  cout << "\n The ball landed on Red " << roulette_ball;
                  cout << "\n you won!!";
                  new_bet = bet * 2;
                  new_inhnd_money = inhnd_money + new_bet;
                  ofstream input;
                  input.open("user.txt", ios::out);
                  input << username;
                  input << "\n"
                        << password;
                  input << "\n"
                        << money;
                  input << "\n"
                        << new_inhnd_money;
                  input.close();
               }
            }
            else
            {
               if (roulette_color == 1)
               {
                  cout << "\n The ball landed on Black " << roulette_ball;
                  cout << "\n you lost :(";
                  new_inhnd_money = inhnd_money - bet;
                  ofstream input;
                  input.open("user.txt", ios::out);
                  input << username;
                  input << "\n"
                        << password;
                  input << "\n"
                        << money;
                  input << "\n"
                        << new_inhnd_money;
                  input.close();
               }
               if (roulette_color == 0)
               {
                  cout << "\n The ball landed on Red " << roulette_ball;
                  cout << "\n you lost :(";
                  new_inhnd_money = inhnd_money - bet;
                  ofstream input;
                  input.open("user.txt", ios::out);
                  input << username;
                  input << "\n"
                        << password;
                  input << "\n"
                        << money;
                  input << "\n"
                        << new_inhnd_money;
                  input.close();
               }
            }
         }
         else
         {
            cout << "\n Invalid value entered :/";
         }
         break;
      }
   case 2:
      cout << "\nYou have choosen to bet on (SETS)";
      cout << "\nThere are 3 sets (1-12) (13-24) (25-36) enter 1,2,3 respectively: "; // SETS
      cout << "\n-->";
      cin >> choice;
      choice -= 1;
      cout << "\n Enter the amount of bet here: $";
      cin >> bet;
      if (bet > inhnd_money)
      {
         cout << "\n Insufficient amount in hand. You only have $" << inhnd_money << " in your hand";
      }
      else
      {
         if (choice == 0 && roulette_ball < 13)
         {
            if (roulette_color == 1)
            {
               cout << "\n The ball landed on Black " << roulette_ball;
               cout << "\n You won!";
            }
            else
            {
               cout << "\n The ball landed on Red " << roulette_ball;
               cout << "\n You won!";
            }
            new_bet = bet * 3;
            new_inhnd_money = inhnd_money + new_bet;
            ofstream input;
            input.open("user.txt", ios::out);
            input << username;
            input << "\n"
                  << password;
            input << "\n"
                  << money;
            input << "\n"
                  << new_inhnd_money;
            input.close();
         }
         if (choice == 1 && roulette_ball > 13 && roulette_ball < 25)
         {
            if (roulette_color == 1)
            {
               cout << "\n The ball landed on Black " << roulette_ball;
               cout << "\n You won!";
            }
            else
            {
               cout << "\n The ball landed on Red " << roulette_ball;
               cout << "\n You won!";
            }
            new_bet = bet * 3;
            new_inhnd_money = inhnd_money + new_bet;
            ofstream input;
            input.open("user.txt", ios::out);
            input << username;
            input << "\n"
                  << password;
            input << "\n"
                  << money;
            input << "\n"
                  << new_inhnd_money;
            input.close();
         }
         if (choice == 2 && roulette_ball > 24 && roulette_ball < 37)
         {
            if (roulette_color == 1)
            {
               cout << "\n The ball landed on Black " << roulette_ball;
               cout << "\n You won!";
            }
            else
            {
               cout << "\n The ball landed on Red " << roulette_ball;
               cout << "\n You won!";
            }
            new_bet = bet * 3;
            new_inhnd_money = inhnd_money + new_bet;
            ofstream input;
            input.open("user.txt", ios::out);
            input << username;
            input << "\n"
                  << password;
            input << "\n"
                  << money;
            input << "\n"
                  << new_inhnd_money;
            input.close();
         }
         else
         {
            if (roulette_color == 1)
            {
               cout << "\n The ball landed on Black " << roulette_ball;
               cout << "\n You lost :(";
            }
            else
            {
               cout << "\n The ball landed on Red " << roulette_ball;
               cout << "\n You lost :(";
            }
            new_inhnd_money = inhnd_money - bet;
            ofstream input;
            input.open("user.txt", ios::out);
            input << username;
            input << "\n"
                  << password;
            input << "\n"
                  << money;
            input << "\n"
                  << new_inhnd_money;
            input.close();
         }
      }
      break;
   default:
      cout << "\n Invalid valure entered recheck your value" << endl;
      break;
   }
}
void Casino::slots()
{
   int money, inhnd_money, new_bet, new_inhnd_money, bet;
   string password, str, inhnd, username;
   ifstream output;
   output.open("user.txt");
   getline(output, username);
   getline(output, password);
   getline(output, str);
   getline(output, inhnd);
   money = stoi(str);
   inhnd_money = stoi(inhnd);
   output.close();
   srand(time(0));
   int slots1 = rand() % 9;
   int slots2 = rand() % 9;
   int slots3 = rand() % 9;
   cout << "\n You choose to play SLOTS";
   cout << "\n Enter the amount of bet here:";
   cout << "\n-->";
   cin >> bet;
   if (bet > inhnd_money)
   {
      cout << "\n Insufficient amount in hand. You only have $" << inhnd_money << " in your hand";
   }
   else
   {
      cout << "\n ___________ ";
      cout << "\n|*         *|";
      cout << "\n|*         *|";
      cout << "\n|*||" << slots1 << "|" << slots2 << "|" << slots3 << "||*|";
      cout << "\n|*         *|";
      cout << "\n|* _______ *|";
      cout << "\n|* |_____| *|";
      cout << "\n|*         *|";
      cout << "\n| _________ |";
      if (slots1 == 7 && slots2 == 7 && slots3 == 7)
      {
         new_bet = bet * 10;
         cout << "\n You won the 10x megaprize $" << new_bet;
         new_inhnd_money = inhnd_money + new_bet;
         ofstream input;
         input.open("user.txt", ios::out);
         input << username;
         input << "\n"
               << password;
         input << "\n"
               << money;
         input << "\n"
               << new_inhnd_money;
         input.close();
      }
      if (slots1 == slots2 && slots1 == slots3)
      {
         new_bet = bet * 3;
         cout << "\n You won $" << new_bet;
         new_inhnd_money = inhnd_money + new_bet;
         ofstream input;
         input.open("user.txt", ios::out);
         input << username;
         input << "\n"
               << password;
         input << "\n"
               << money;
         input << "\n"
               << new_inhnd_money;
         input.close();
      }
      if (slots1 == slots2)
      {
         new_bet = bet * 2;
         cout << "\n You won $" << new_bet;
         new_inhnd_money = inhnd_money + new_bet;
         ofstream input;
         input.open("user.txt", ios::out);
         input << username;
         input << "\n"
               << password;
         input << "\n"
               << money;
         input << "\n"
               << new_inhnd_money;
         input.close();
      }
      if (slots2 == slots3)
      {
         new_bet = bet * 2;
         cout << "\n You won $" << new_bet;
         new_inhnd_money = inhnd_money + new_bet;
         ofstream input;
         input.open("user.txt", ios::out);
         input << username;
         input << "\n"
               << password;
         input << "\n"
               << money;
         input << "\n"
               << new_inhnd_money;
         input.close();
      }
      if (slots3 == slots1)
      {
         new_bet = bet * 2;
         cout << "\n You won $" << new_bet;
         new_inhnd_money = inhnd_money + new_bet;
         ofstream input;
         input.open("user.txt", ios::out);
         input << username;
         input << "\n"
               << password;
         input << "\n"
               << money;
         input << "\n"
               << new_inhnd_money;
         input.close();
      }
      else
      {
         cout << "\n You lost $" << bet;
         new_inhnd_money = inhnd_money - bet;
         ofstream input;
         input.open("user.txt", ios::out);
         input << username;
         input << "\n"
               << password;
         input << "\n"
               << money;
         input << "\n"
               << new_inhnd_money;
         input.close();
      }
   }
}
void Casino::spin_the_wheel()
{ // 0,0,0,0,1,2,3,5,7,10
   int money, inhnd_money, new_bet, new_inhnd_money, bet;
   string password, str, inhnd, username;
   ifstream output;
   output.open("user.txt");
   getline(output, username);
   getline(output, password);
   getline(output, str);
   getline(output, inhnd);
   money = stoi(str);
   inhnd_money = stoi(inhnd);
   output.close();
   srand(time(0));
   int spin_the_wheel = rand() % 10;
   cout << "\n You choose SPIN THE WHEEL game";
   cout << "\n *PRIZES*";
   cout << "\n |     0x     |     1x     |     2x     |     3x     |     0x     |";
   cout << "\n";
   cout << "\n |     0x     |     5x     |     0x     |     7x     |     10     x|";
   cout << "\n Enter the amount of bet here: $";
   cin >> bet;
   if (bet > inhnd_money)
   {
      cout << "\n Insufficient amount in hand. You only have $" << inhnd_money << " in your hand";
   }
   else
   {
      if (spin_the_wheel <= 4)
      {
         cout << "You lost $" << bet;
         new_inhnd_money = inhnd_money - bet;
         ofstream input;
         input.open("user.txt", ios::out);
         input << username;
         input << "\n"
               << password;
         input << "\n"
               << money;
         input << "\n"
               << new_inhnd_money;
         input.close();
      }
      else
      {
         if (spin_the_wheel == 1)
         {
            cout << "\nYou lost nothing and got your $" << bet << "back";
         }
         if (spin_the_wheel == 2)
         {
            new_bet = bet * 2;
            cout << "\nYou won 2x the amount and got $" << new_bet;
            new_inhnd_money = inhnd_money + new_bet;
            ofstream input;
            input.open("user.txt", ios::out);
            input << username;
            input << "\n"
                  << password;
            input << "\n"
                  << money;
            input << "\n"
                  << new_inhnd_money;
            input.close();
         }
         if (spin_the_wheel == 3)
         {
            new_bet = bet * 3;
            cout << "\nohhh!! You won 3x the amount and got $" << new_bet;
            new_inhnd_money = inhnd_money + new_bet;
            ofstream input;
            input.open("user.txt", ios::out);
            input << username;
            input << "\n"
                  << password;
            input << "\n"
                  << money;
            input << "\n"
                  << new_inhnd_money;
            input.close();
         }
         if (spin_the_wheel == 5)
         {
            new_bet = bet * 5;
            cout << "\nWow! You won 5x the amount and got $" << new_bet;
            new_inhnd_money = inhnd_money + new_bet;
            ofstream input;
            input.open("user.txt", ios::out);
            input << username;
            input << "\n"
                  << password;
            input << "\n"
                  << money;
            input << "\n"
                  << new_inhnd_money;
            input.close();
         }
         if (spin_the_wheel == 7)
         {
            new_bet = bet * 7;
            cout << "\nWohoo!! You won 7x the amount and got $" << new_bet;
            new_inhnd_money = inhnd_money + new_bet;
            ofstream input;
            input.open("user.txt", ios::out);
            input << username;
            input << "\n"
                  << password;
            input << "\n"
                  << money;
            input << "\n"
                  << new_inhnd_money;
            input.close();
         }
         if (spin_the_wheel == 10)
         {
            new_bet = bet * 10;
            cout << "\nAmazing!! You won the megaprize that is 10x the amount and got $" << new_bet;
            new_inhnd_money = inhnd_money + new_bet;
            ofstream input;
            input.open("user.txt", ios::out);
            input << username;
            input << "\n"
                  << password;
            input << "\n"
                  << money;
            input << "\n"
                  << new_inhnd_money;
            input.close();
         }
      }
   }
}

// The main function starts from here
int main()
{
   int bnk, a, opt;
   char choice;
   bank user;
   Casino same_user;
   char value;

top:
   cout << "\n\n Welcome to our project!! Enter where you want to go (*PRESS (b) FOR BANK AND (c) FOR CASINO*) :";
   cin >> choice;
   switch (choice)
   {
   case 'b':
   bank:
      cout << "\t\t\t\t\t\tWELCOME TO THE BANK";
      cout << "\n******************************************************************************************************************************";
      cout << "\n|Enter your choice from below                                                                                                |";
      cout << "\n|(1)-Make an Account                                                                                                         |";
      cout << "\n|(2)-Check Account Balance                                                                                                   |";
      cout << "\n|(3)-Withdraw Money                                                                                                          |";
      cout << "\n|(4)-Deposit Money                                                                                                           |";
      cout << "\n|(5)-Change password of your account                                                                                         |";
      cout << "\n|(6)-Exit                                                                                                                    |";
      cout << "\n******************************************************************************************************************************";
      cout << "\n-->";
      cin >> bnk;
      switch (bnk)
      {
      case 1:
         cout << "You have choosen to (Make an account)";
         user.makeaccount();
         break;
      case 2:
         cout << "You have choosen to (Check your balance)\n";
         user.balance();
         break;
      case 3:
         cout << "You have choosen to (Withdraw ammount from your account)";
         user.withdraw();
         break;
      case 4:
         cout << "You have choosen to (Deposit an ammount to your account)";
         user.deposit();
         break;
      case 5:
         cout << "You have choosen to (Change password of your account)";
         user.changepassword();
         break;
      case 6:
         cout << "\nYou have choosen to (exit)";
         goto bottom;
         break;
      default:
         cout << "Enter a valid value ";
         break;
      }
      cout << "\nDo you want to reuse our service? (enter y or n ):";
      cout << "\n-->";
      cin >> value;
      if (value == 'y' || value == 'Y')
      {
         goto bank;
      }
      else
      {
      bottom:
         cout << "\nThanks for using our service";
         goto top;
      }
      cout << "\nThanks for using our service";
      break;
   case 'c':
   casino:
      cout << "\t\t\t\t\t\tWELCOME TO THE CASINO";
      cout << "\n******************************************************************************************************************************";
      cout << "\n|Enter your choice from below                                                                                                |";
      cout << "\n|(1)-ROULETTE                                                                                                                |";
      cout << "\n|(2)-SLOTS                                                                                                                   |";
      cout << "\n|(3)-SPIN THE WHEEL                                                                                                          |";
      cout << "\n|(4)-EXIT                                                                                                                    |";
      cout << "\n******************************************************************************************************************************";
      cout << "\n-->";
      cin >> opt;
      switch (opt)
      {
      case 1:
         cout << "You have choosen to play (ROULETTE)";
         cout << "\n Enter value for which value you want to bet on (PRESS 1 FOR COLORS OR 2 FOR SETS) :";
         cin >> a;
         same_user.roulette(a);
         break;
      case 2:
         cout << "You have choosen to play (SLOTS)\n";
         same_user.slots();
         break;
      case 3:
         cout << "You have choosen to play (SPIN THE WHEEL)";
         same_user.spin_the_wheel();
         break;
      case 4:
         cout << "\nYou have choosen to (EXIT THE GAME)";
         goto down;
         break;
      default:
         cout << "Enter a valid value! ";
         break;
      }
      cout << "\nDo you want to reuse our game? (enter y or n ):";
      cout << "\n-->";
      cin >> value;
      if (value == 'y' || value == 'Y')
      {
         goto casino;
      }
      else
      {
      down:
         cout << "\nThanks for using our game";
         goto top;
      }
      break;
   default:
      cout << "\n Thank you so much!!! for your time." << endl;
      break;
   }
}