from casino_view import *
import casino_view as c

def get_items(x):
     match x :
        case 0:
             return "❓"
        case 1: 
            return "🎈" 
        case 2:
            return "🍇"
        case 3:
            return "🍋"
        case 4:
            return "🍕"
        case 5:
            return "🌼"

def playGame():
    bet = input("rise your bet : ")
    while(not bet.isdigit()):
        unvalid_input()
        bet = input("rise your bet : ")
    bet = float(bet)
    if(bet > c.balance):
        print("Not Enough money Mate!"
              "Go increse your balance\n")
        wait(3)
        return
    game_starting()
    clear()
    print_decoration()
    items = [0 , 0 , 0]
    tm = time.time()
    clear()
    wait(0.5)
    while(time.time() - tm < 3):
        item1 = random.randint(1 , 5)
        print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"
             f"     {get_items(item1)} | ❓ | ❓    \n"
              "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n")
        wait(0.1)
        clear()
    item1 = get_items(random.randint(1 , 5))

    tm = time.time()
    while(time.time() - tm < 3):
            item2 = random.randint(1 , 5)
            print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"
                 f"     {item1} | {get_items(item2)} | ❓    \n"
                  "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n")
            wait(0.1)
            clear()
    item2 = get_items(random.randint(1 , 5))

    tm = time.time()
    while(time.time() - tm < 3):
            item3 = random.randint(1 , 5)
            print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"
                 f"     {item1} | {item2} | {get_items(item3)}    \n"
                  "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n")
            wait(0.1)
            clear()
    item3 = get_items(random.randint(1 , 5))

    tm = time.time()
    while(time.time() - tm < 5):
        print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"
            f"     {item1} | {item2} | {item3}    \n"
            "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n")
        wait(0.3)
        clear()
        wait(0.2)
    if(item1 == item2 and item1 == item3):
        print("Congrats! your money has been doubled")
        c.balance += (bet * 2)
    else:
        print("you lost :(")
        c.balance -= bet
    wait(5)
def RunMenu():
    clear()
    print_Menu()
    n = input()
    match n:
        case "1":
            clear()
            playGame()
        case "2":
            clear()
            print_balance()
            wait(2)
        case "3":
            clear()
            amount = print_increament()
            while(not amount.isdigit()):
                unvalid_input()
                amount = print_increament()
            amount = float(amount)
            c.balance += amount
            print_succesfull_increase(amount)
            wait(2)
        case "4":
            c.Exit = True
            return
        case _:
            clear()
            print("bruh WTF!")
            wait(2)
            clear()