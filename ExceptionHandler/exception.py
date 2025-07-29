class DivisionByZeroError(Exception):
    """Custom exception for division by zero"""
    def __init__(self, message="Division by zero is not allowed"):
        self.message = message
        super().__init__(self.message)

def divide(a, b):
    if b == 0:
        raise DivisionByZeroError(f"Cannot divide {a} by zero")
    return a / b

def read_file(filename):
    try:
        with open(filename, 'r') as file:
            content = file.read()
        return content
    except FileNotFoundError:
        raise FileNotFoundError(f"File '{filename}' not found")
    except PermissionError:
        raise PermissionError(f"Permission denied to read '{filename}'")

def demonstrate_multiple_exceptions():
    try:
        # This might raise ValueError
        number = int("abc")
        
        # This might raise IndexError
        my_list = [1, 2, 3]
        print(my_list[5])
        
    except ValueError as e:
        print(f"Value error: {e}")
    except IndexError as e:
        print(f"Index error: {e}")
    except Exception as e:
        print(f"Unexpected error: {e}")
    else:
        print("No exceptions occurred")
    finally:
        print("Finally block always executes")

def main():
    # Division example with exception handling
    print("Division Examples:")
    
    try:
        result = divide(10, 2)
        print(f"10 / 2 = {result}")
        
        result = divide(10, 0)  # This will raise an exception
        print(f"10 / 0 = {result}")
        
    except DivisionByZeroError as e:
        print(f"Error: {e}")
    except Exception as e:
        print(f"Unexpected error: {e}")
    
    # File operation with exception handling
    print("\nFile Operation Example:")
    try:
        content = read_file("nonexistent.txt")
        print(content)
    except (FileNotFoundError, PermissionError) as e:
        print(f"File error: {e}")
    
    # Multiple exception types
    print("\nMultiple Exception Example:")
    demonstrate_multiple_exceptions()

if __name__ == "__main__":
    main()