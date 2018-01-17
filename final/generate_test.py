"""generate test.txt"""
from random import choice
from string import ascii_letters

def main():
    """generate test.txt"""
    with open('./test.txt', "w") as fp:
        for i in range(50000):
            fp.write(choice(ascii_letters))

if __name__ == '__main__':
    main()
