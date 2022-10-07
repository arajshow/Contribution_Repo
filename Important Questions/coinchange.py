# Python implementation of Coin Change problem


def count(coins, n, sum):

    table = [0 for k in range(sum+1)]
    table[0] = 1

    for i in range(0, n):
        for j in range(coins[i], sum+1):
            table[j] += table[j-coins[i]]

    return table[sum]


if(__name__ == "__main__"):
    coins = list(map(int, input("Enter the coin values : ").split()))
    n = len(coins)
    sum = int(input("Enter the sum : "))
    x = count(coins, n, sum)
    print(f"Number of ways to make sum={sum} is {x}.")
