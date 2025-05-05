table = {}
tableq = {}
totl = 0
totq = 0

def create(b):
    for i in range(b):
        table[i] = None
        tableq[i] = None

def linsert(key, b):
    global totl
    hash = key % b
    if table[hash] == None:
        table[hash] = key
        totl+=1
    else:
        for i in range(b):
            new_hash = (hash + i) % b
            totl+=1
            if table[new_hash] == None:
                table[new_hash] = key
                break

# def qinsert(key, b):
#     global totq
#     hash = key % b
#     if tableq[hash] == None:
#         tableq[hash] = key
#     else:
#         for i in range(int((b - 1) / 2)):
#             new_hash = (hash + i*i) % b
#             if tableq[new_hash] == None:
#                 tableq[new_hash] = key
#                 totq += 1
#                 break

def lsearch(key, b):
    hash = key % b
    for i in range(b):
        new_hash = (hash + i) % b
        if table[new_hash] == key:
            print("Key:", key, "found at", new_hash)
            return
        if table[new_hash] == None:
            break
    print("Key:", key, "not found.")

# def qsearch(key, b):
#     hash = key % b
#     for i in range(int((b - 1) / 2)):
#         new_hash = (hash + i*i) % b
#         if tableq[new_hash] == key:
#             print("Key:", key, "found at", new_hash)
#             return
#         if tableq[new_hash] == None:
#             break
#     print("Key:", key, "not found.")

def printtable(b):
    print("Linearly Probed Table:")
    for i in range(b):
        print(table[i], end=" | ")
    print()

def avg_comparisons():
    print("Average comparisons for Linear Probing: ", totl/b)

b = int(input("Enter table size: "))
create(b)

while True:
    print("\nMenu: 1-Insert LP, 2-Search LP, 3-Print Table, 4-Average Comparisons, 0-Exit")
    ch = int(input("Enter choice: "))

    if ch == 1:
        if totl == b:
            print("Table Full for Linear Probing.")
        else:
            key = int(input("Enter key to insert (LP): "))
            linsert(key, b)

    elif ch == 2:
        key = int(input("Enter key to search (LP): "))
        lsearch(key, b)

    elif ch == 3:
        printtable(b)

    elif ch == 4:
        avg_comparisons()

    elif ch == 0:
        print("Exiting...")
        break

    else:
        print("Invalid choice. Try again.")

