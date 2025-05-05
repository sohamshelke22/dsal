"""
To create ADT that implements the "set" concept.
a. Add (new Element) -Place a value into the set
b. Remove (element) Remove the value
c. Contains (element) Return true if element is in
 collection
d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection
e. Intersection of two sets
f. Union of two sets
g. Difference between two sets
h. Subset
"""
# Set is represented as a list with no duplicates
def add(s, element):
    if not contains(s, element):
        s += [element]
    return s

def remove(s, element):
    new_set = []
    found = False
    for i in s:
        if i != element:
            new_set += [i]
        else:
            found = True
    if not found:
        print(f"Element {element} not found.")
    return new_set

def contains(s, element):
    for i in s:
        if i == element:
            return True
    return False

def size(s):
    count = 0
    for _ in s:
        count += 1
    return count

def iterator(s):
    for i in s:
        yield i

def intersection(s1, s2):
    result = []
    for i in s1:
        if contains(s2, i):
            result = add(result, i)
    return result

def union(s1, s2):
    result = []
    for i in s1:
        result = add(result, i)
    for i in s2:
        result = add(result, i)
    return result

def difference(s1, s2):
    result = []
    for i in s1:
        if not contains(s2, i):
            result = add(result, i)
    return result

def is_subset(s1, s2):
    for i in s1:
        if not contains(s2, i):
            return False
    return True

A = []
B = []

# Adding elements
A = add(A, 1)
A = add(A, 2)
A = add(A, 3)

B = add(B, 2)
B = add(B, 3)
B = add(B, 4)

print("Set A:", A)
print("Set B:", B)

print("Union:", union(A, B))
print("Intersection:", intersection(A, B))
print("Difference A - B:", difference(A, B))
print("Is A subset of B?", is_subset(A, B))
print("Is [2,3] subset of A?", is_subset([2, 3], A))
print("Size of A:", size(A))

print("Iterator A:")
for x in iterator(A):
    print(x)
