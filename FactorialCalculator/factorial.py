def factorial(n):
    if n <= 1:
        return 1
    return n * factorial(n - 1)

number = 5
result = factorial(number)
print(f"Factorial of {number} is {result}")