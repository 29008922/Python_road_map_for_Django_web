#!/usr/bin/pytho3

today = input("Enter the day ")
bank_balance = int(input("Enter the balance? "))
if today == "Holiday":
    if bank_balance > 20000:
        print("Go for shopping")
    else:
        print("Watch Tv")
else:
    print("Its a normal working day")