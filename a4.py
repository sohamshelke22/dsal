# --- Set Operations Using Lists ---

def add(s, element):
    if element not in s:
        s.append(element)

def remove(s, element):
    if element in s:
        s.remove(element)
    else:
        print("Element " + str(element) + " not found in set.")

def contains(s, element):
    return element in s

def size(s):
    return len(s)

def iterator(s):
    for elem in s:
        print(elem, end=" ")
    print()

def intersection(s1, s2):
    result = []
    for elem in s1:
        if elem in s2:
            result.append(elem)
    return result


def union(s1, s2):
    result = s1.copy()
    for elem in s2:
        if elem not in result:
            result.append(elem)
    return result

def difference(s1, s2):
    result = []
    for elem in s1:
        if elem not in s2:
            result.append(elem)
    return result


def is_subset(s1, s2):
    for elem in s1:
        if elem not in s2:
            return False
    return True

# --- Run the program directly ---

set_a = []
set_b = []

while True:
    print("\n--- Set Operations Menu ---")
    print("1. Add to Set A")
    print("2. Add to Set B")
    print("3. Remove from Set A")
    print("4. Remove from Set B")
    print("5. Contains (Set A)")
    print("6. Size of Set A and B")
    print("7. Display Set A")
    print("8. Display Set B")
    print("9. Intersection (A ∩ B)")
    print("10. Union (A ∪ B)")
    print("11. Difference (A - B)")
    print("12. Is A Subset of B?")
    print("13. Exit")

    choice = input("Enter your choice (1-13): ")

    if choice == "1":
        val = input("Enter element to add to Set A: ")
        add(set_a, val)
    elif choice == "2":
        val = input("Enter element to add to Set B: ")
        add(set_b, val)
    elif choice == "3":
        val = input("Enter element to remove from Set A: ")
        remove(set_a, val)
    elif choice == "4":
        val = input("Enter element to remove from Set B: ")
        remove(set_b, val)
    elif choice == "5":
        val = input("Check if element exists in Set A: ")
        if contains(set_a, val):
            print("Exists.")
        else:
            print("Does not exist.")
    elif choice == "6":
        print("Size of Set A: " + str(size(set_a)))
        print("Size of Set B: " + str(size(set_b)))
    elif choice == "7":
        print("Set A elements:")
        iterator(set_a)
    elif choice == "8":
        print("Set B elements:")
        iterator(set_b)
    elif choice == "9":
        print("Intersection (A ∩ B): " + str(intersection(set_a, set_b)))
    elif choice == "10":
        print("Union (A ∪ B): " + str(union(set_a, set_b)))
    elif choice == "11":
        print("Difference (A - B): " + str(difference(set_a, set_b)))
    elif choice == "12":
        if is_subset(set_a, set_b):
            print("Set A is a subset of Set B")
        else:
            print("Set A is NOT a subset of Set B")
    elif choice == "13":
        print("Exiting program.")
        break
    else:
        print("Invalid choice. Please enter a number from 1 to 13.")
