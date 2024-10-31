print("Water Jug Problem")
# Initial values for the jugs
x = int(input("Enter the initial amount in Jug1 (x): "))
y = int(input("Enter the initial amount in Jug2 (y): "))
while True:
    print("Rules:")
    print("1. Fill Jug1 to its capacity (4 liters)")
    print("2. Fill Jug2 to its capacity (3 liters)")
    print("5. Empty Jug1")
    print("6. Empty Jug2")
    print("7. Pour water from Jug2 to Jug1 until Jug1 is full or Jug2 is empty")
    print("8. Pour water from Jug1 to Jug2 until Jug2 is full or Jug1 is empty")
    print("9. Pour all water from Jug2 into Jug1")
    print("10. Pour all water from Jug1 into Jug2")

    r = int(input("Enter the rule number (1-10): "))

    if r == 1:
        if x < 4:  # Fill Jug1 to its capacity (4 liters)
            x = 4
    elif r == 2:
        if y < 3:  # Fill Jug2 to its capacity (3 liters)
            y = 3
    elif r == 5:
        if x > 0:  # Empty Jug1
            x = 0


    elif r == 6:
        if y > 0:  # Empty Jug2
            y = 0
    elif r == 7:
        if x + y >= 4 and y > 0:
            # Pour water from Jug2 to Jug1 until Jug1 is full or Jug2 is empty
            x, y = min(4, x + y), max(0, y - (4 - x))
    elif r == 8:
        if x + y >= 3 and x > 0:
            # Pour water from Jug1 to Jug2 until Jug2 is full or Jug1 is empty
            x, y = max(0, x - (3 - y)), min(3, x + y)
    elif r == 9:
        if x + y <= 4 and y > 0:  # Pour all water from Jug2 into Jug1
            x, y = x + y, 0
    elif r == 10:
        if x + y <= 3 and x > 0:  # Pour all water from Jug1 into Jug2
            x, y = 0, x + y
    else:
        print("Invalid rule number. Please try again.")

    # Display the current state of both jugs
    print("x =", x)
    print("y =", y)

    # Check if the goal state (2 liters in Jug1) is reached
    if x == 2 and y == 0:
        print("The result is a Goal State")
        break
