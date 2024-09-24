import sys

# sys.stdin = open("input.txt", "r")


class Node:
    def __init__(self):
        self.children = [None] * 10
        self.end = False


def check(count):
    number_list = [list(map(int, input())) for _ in range(count)]
    phone_numbers = Node()

    for numbers in number_list:
        current = phone_numbers

        for number in numbers:
            if current.children[number] is None:
                current.children[number] = Node()

            current = current.children[number]
            if current.end:
                return False

        if any(current.children):
            return False
        current.end = True

    return True


t = int(input())

for _ in range(t):
    print("YES" if check(int(input())) else "NO")
