table_lp = {}
table_ch = {}
totl_lp = 0
totl_ch = 0

def create(b):
    for i in range(b):
        table_lp[i] = None
        table_ch[i] = []

def linsert(key, b):
    global totl_lp
    hash = key % b
    if table_lp[hash] == None:
        table_lp[hash] = key
        totl_lp += 1
    else:
        for i in range(b):
            new_hash = (hash + i) % b
            totl_lp += 1
            if table_lp[new_hash] == None:
                table_lp[new_hash] = key
                break

def lsearch(key, b):
    hash = key % b
    for i in range(b):
        new_hash = (hash + i) % b
        if table_lp[new_hash] == key:
            print("Key:", key, "found at", new_hash, "(LP)")
            return
        if table_lp[new_hash] == None:
            break
    print("Key:", key, "not found. (LP)")

def chinsert(key, b):
    global totl_ch
    hash = key % b
    table_ch[hash].append(key)
    totl_ch += len(table_ch[hash])  # Each insert assumed to scan the whole chain

def chsearch(key, b):
    hash = key % b
    comparisons = 0
    for val in table_ch[hash]:
        comparisons += 1
        if val == key:
            print(f"Key: {key} found at index {hash} (CH) after {comparisons} comparisons")
            return
    print(f"Key: {key} not found. (CH)")

def printtables(b):
    print("\nLinear Probing Table:")
    for i in range(b):
        print(table_lp[i], end=" | ")
    print("\n\nChaining Table:")
    for i in range(b):
        print(f"{i}: {table_ch[i]}")
    print()

def avg_comparisons():
    print("Average comparisons for Linear Probing: ", totl_lp / b)
    print("Average comparisons for Chaining: ", totl_ch / b)

# Main Menu
b = int(input("Enter table size: "))
create(b)

while True:
    print("\nMenu:")
    print("1-Insert LP, 2-Search LP, 3-Insert CH, 4-Search CH")
    print("5-Print Tables, 6-Average Comparisons, 0-Exit")
    ch = int(input("Enter choice: "))

    if ch == 1:
        if totl_lp == b:
            print("Table Full for Linear Probing.")
        else:
            key = int(input("Enter key to insert (LP): "))
            linsert(key, b)

    elif ch == 2:
        key = int(input("Enter key to search (LP): "))
        lsearch(key, b)

    elif ch == 3:
        key = int(input("Enter key to insert (CH): "))
        chinsert(key, b)

    elif ch == 4:
        key = int(input("Enter key to search (CH): "))
        chsearch(key, b)

    elif ch == 5:
        printtables(b)

    elif ch == 6:
        avg_comparisons()

    elif ch == 0:
        print("Exiting...")
        break

    else:
        print("Invalid choice. Try again.")
