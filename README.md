
# Project details ⚙️
This project is a total backend project made using the c++ language, and it stores the data, i.e. username, password, balance and inhand money in a `user.txt` file, so to test any bugs and errors, you can directly write in that specific file whatever you want to try . Using the random and ctime functions the random numbers are generated, which are used for roulette, sets and spin the wheel.



## Casino with bank management
Here the project includes a casino and its own bank where the user can deposit or credit their money in the bank or can use it in a casino.



## Main menu

- Bank  

- Casino




# 1) Bank 🏦

- The bank has several functions:
        
        1. Make account
        2. Withdraw amount
        3. Deposit amount
        4. Show balance
        5. Change password
## Make account
- Here, the user can make their own account where they can create their username, password and initial money.

## Withdraw amount
- Here, by verifying the password, the user can withdraw money from the account.

## Deposit amount
- By verifying the password, the user can deposit an amount into the account.

## Show balance 
- By verifying the correct password, the user can see the balance of his/her account.

## Change password 
- By verifying an old password, the user can change the password of his/her account to a new one.


# 2) Casino ♠
- The Casino has several games:
        
        1. Roulette
        2. Slots
        3. Spin the wheel
- After the result of the games listed above, the user can quickly deposit the money or take any amount from the bank.

## Roulette 💵
- The play has 2 choices, i.e. either to bet on colors (red or black) or to bet on sets:
        
| Set             | Numbers                                                                |
| ----------------- | ------------------------------------------------------------------ |
| 1st | 1-12 |
| 2nd | 13-24 |
| 3rd | 25-36|

- If a player bets on any of the sets and wins, he/she gets triple the bet amount
- If the player bets on a color and wins, then he/she gets double the bet amount. 

## Slots 🎰
- The slots consist of three arrays of numbers and if all the numbers are same, then the user wins a prize 
- When two of the numbers displayed are the same, the user wins double the bet amount.

eg- `|6|3|6|`
- When all the numbers displayed are same, the user wins triple the bet amount 

eg- `|6|3|6|`
- And when the number displayed is `|7|7|7|`, the player wins ten times the bet amount.


## Spin the wheel 🎁 
- There is an array of prizes which the player can win.
- The prize amount is random and is generated randomly.
- Prize in this project: 
        
        0x,0x,0x,0x,1x,2x,3x,5x,7x,10x


## Functionalities 🔧
     1) Users cannot bet if he/she doesn't have a sufficient amount of money. 
     2) Users cannot deposit any amount more than they have with them.  
     3) Users cannot withdraw any amount more than they have in their bank.



# Authors ✍🏼

Dev.Patel 
[@github](https://github.com/pateldev11305)  [@Linkedin](https://www.linkedin.com/in/dev-patel11/)

Happy coding!!🥰