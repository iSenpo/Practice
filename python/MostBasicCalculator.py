op = input("Eter your operation : ")
if(op != "+" and op != '-' and op != '*' and op != '/') :
    print("Invalid Operation !")
else :
    n1 = int(input("Enter first Number : "))
    n2 = int(input("Enter second Number : "))
    if(op == '+') : 
        print(f"the Sum is : {n1 + n2}")
    elif(op == '-') :
        print(f"the Minuz is : {n1 - n2}")
    elif(op == '*') :
        print(f"the Product is : {n1 * n2}")
    else :
        if(n2 == 0) : 
            print("Error! cant devide by zero")
        else :
            print(f"the Division is : {n1 / n2}")

