import time
import random
import os
Name = ""
Exit = False
balance = 0.00
def clear():
    os.system('cls')
def wait(n):
    time.sleep(n)

def print_welcome():
    Name = input("enter your name : ")
    print(f"~ ~ ~ Welcome to Casino {Name} ~ ~ ~ \n")
    time.sleep(2)
    clear()

def print_decoration():
    print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
def print_succesfull_increase(a):
    print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
    print(f"Succecfully add {a} to your balance.")
    print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")

# - - - - - - - - - - - - - - - - - - - - - - -
def print_Menu():
    print("~ ~ ~ select an option ~ ~ ~\n"
            "1.roll the wheel\n"
            "2.show balance\n"
            "3.increase balance\n"
            "4.exit\n"
            "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
def print_increament():
    print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
    n = input("how much you want to increament? ")
    print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
    return n
def unvalid_input():
    print("Not a valid input. use floating point numbers!\n")
def game_starting():
    print("Game starting!")
    wait(1)
    clear()
    wait(0.5)
    print("           3           \n"
          "     ❓ | ❓ | ❓    ")
    wait(1)
    clear()
    print("           2           \n"
          "     ❓ | ❓ | ❓    ")
    wait(1)
    clear()
    print("           1           \n"
          "     ❓ | ❓ | ❓    ")
    wait(1)
    clear()
# - - - - - - - - - - - - - - - - - - - - - - - 
def print_balance():
    print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
    print(f"your balance is : ${balance}")
    print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
# - - - - - - - - - - - - - - - - - - - - - - -
def print_GoodBye():
    print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
    print("WE HOPE YOU ENJOYED YOUR TIME HERE")
    print("GOOD BYE AND GOOD LUCK!")
    print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
def rooling():
    print()
