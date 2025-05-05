class Node:
    def __init__(self, keyword, meaning):
        self.keyword = keyword
        self.meaning = meaning
        self.left = None
        self.right = None

class Dictionary:
    def __init__(self):
        self.root = None

    def insert(self, node, keyword, meaning):
        if node is None:
            return Node(keyword, meaning)
        if keyword < node.keyword:
            node.left = self.insert(node.left, keyword, meaning)
        elif keyword > node.keyword:
            node.right = self.insert(node.right, keyword, meaning)
        else:
            node.meaning = meaning  # Update meaning if keyword exists
        return node

    def add_keyword(self, keyword, meaning):
        self.root = self.insert(self.root, keyword, meaning)
        print("Keyword added successfully!")

    def find(self, node, keyword, comparisons):
        if node is None:
            comparisons[0] += 1
            return None
        comparisons[0] += 1
        if keyword == node.keyword:
            return node
        elif keyword < node.keyword:
            return self.find(node.left, keyword, comparisons)
        else:
            return self.find(node.right, keyword, comparisons)

    def find_keyword(self, keyword):
        comparisons = [0]
        result = self.find(self.root, keyword, comparisons)
        if result:
            print(f"Keyword found: {result.keyword} : {result.meaning}")
        else:
            print("Keyword not found!")
        print(f"Number of comparisons: {comparisons[0]}")

    def delete(self, node, keyword):
        if node is None:
            return None
        if keyword < node.keyword:
            node.left = self.delete(node.left, keyword)
        elif keyword > node.keyword:
            node.right = self.delete(node.right, keyword)
        else:
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left

            temp = self.min_value_node(node.right)
            node.keyword = temp.keyword
            node.meaning = temp.meaning
            node.right = self.delete(node.right, temp.keyword)
        return node

    def delete_keyword(self, keyword):
        self.root = self.delete(self.root, keyword)
        print("Keyword deleted successfully!")

    def min_value_node(self, node):
        current = node
        while current.left:
            current = current.left
        return current

    def update_keyword(self, keyword, meaning):
        comparisons = [0]
        node = self.find(self.root, keyword, comparisons)
        if node:
            node.meaning = meaning
            print("Keyword updated successfully!")
        else:
            print("Keyword not found!")

    def display_ascending(self, node):
        if node is None:
            return
        self.display_ascending(node.left)
        print(f"{node.keyword} : {node.meaning}")
        self.display_ascending(node.right)

    def display_descending(self, node):
        if node is None:
            return
        self.display_descending(node.right)
        print(f"{node.keyword} : {node.meaning}")
        self.display_descending(node.left)

    def show_ascending(self):
        if not self.root:
            print("Dictionary is empty!")
        else:
            print("Dictionary in ascending order:")
            self.display_ascending(self.root)

    def show_descending(self):
        if not self.root:
            print("Dictionary is empty!")
        else:
            print("Dictionary in descending order:")
            self.display_descending(self.root)

def menu():
    d = Dictionary()
    while True:
        print("\nDictionary Menu:")
        print("1. Add Keyword")
        print("2. Delete Keyword")
        print("3. Update Keyword")
        print("4. Display Ascending")
        print("5. Display Descending")
        print("6. Find Keyword")
        print("7. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            key = input("Enter keyword: ")
            meaning = input("Enter meaning: ")
            d.add_keyword(key, meaning)
        elif choice == '2':
            key = input("Enter keyword to delete: ")
            d.delete_keyword(key)
        elif choice == '3':
            key = input("Enter keyword to update: ")
            meaning = input("Enter new meaning: ")
            d.update_keyword(key, meaning)
        elif choice == '4':
            d.show_ascending()
        elif choice == '5':
            d.show_descending()
        elif choice == '6':
            key = input("Enter keyword to find: ")
            d.find_keyword(key)
        elif choice == '7':
            print("Exiting program...")
            break
        else:
            print("Invalid choice! Please try again.")

if __name__ == "__main__":
    menu()
