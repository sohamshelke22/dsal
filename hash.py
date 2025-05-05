SIZE = 10

class ChainingHash:
    def __init__(self):
        self.table = []
        for _ in range(SIZE):
            self.table.append([]) 

    def char_to_ascii_sum(self, key):
        total = 0
        for ch in key:
            total += ord(ch)  
        return total

    def hash_func(self, key):
        return self.char_to_ascii_sum(key) % SIZE

    def insert(self, name, phone):
        idx = self.hash_func(name)
        self.table[idx].append((name, phone)) 

    def search(self, name):
        idx = self.hash_func(name)
        comparisons = 0
        for entry in self.table[idx]:
            comparisons += 1
            if entry[0] == name:
                return True, comparisons
        return False, comparisons


class LinearProbingHash:
    def __init__(self):
        self.table = [None] * SIZE
        self.occupied = [False] * SIZE

    def char_to_ascii_sum(self, key):
        total = 0
        for ch in key:
            total += ord(ch)
        return total

    def hash_func(self, key):
        return self.char_to_ascii_sum(key) % SIZE

    def insert(self, name, phone):
        idx = self.hash_func(name)
        start = idx
        while self.occupied[idx]:
            idx = (idx + 1) % SIZE
            if idx == start:
                print("Hash table full!")
                return
        self.table[idx] = (name, phone)
        self.occupied[idx] = True

    def search(self, name):
        idx = self.hash_func(name)
        start = idx
        comparisons = 0
        while self.occupied[idx]:
            comparisons += 1
            if self.table[idx][0] == name:
                return True, comparisons
            idx = (idx + 1) % SIZE
            if idx == start:
                break
        return False, comparisons

# ------------------ Main ------------------
def main():
    chain_hash = ChainingHash()
    probe_hash = LinearProbingHash()

    while True:
        print("\n--- Telephone Book ---")
        print("1. Insert Contact")
        print("2. Search Contact")
        print("3. Exit")
        choice = input("Enter choice: ")

        if choice == '1':
            name = input("Enter Name: ")
            phone = input("Enter Phone: ")
            chain_hash.insert(name, phone)
            probe_hash.insert(name, phone)
            print("Inserted in both tables.")

        elif choice == '2':
            name = input("Enter Name to Search: ")
            found1, c1 = chain_hash.search(name)
            found2, c2 = probe_hash.search(name)
            print(f"Chaining: {'Found' if found1 else 'Not Found'}, Comparisons: {c1}")
            print(f"Probing: {'Found' if found2 else 'Not Found'}, Comparisons: {c2}")

        elif choice == '3':
            print("Exiting...")
            break

        else:
            print("Invalid choice.")

if __name__ == "__main__":
    main()
