def file_operations():
    filename = "example.txt"
    data = "Hello, World!\nThis is a file write operation in Python.\nLine 3 of the file."
    
    try:
        # Write to file
        with open(filename, 'w') as file:
            file.write(data)
        print("Data written to file successfully.")
        
        # Read from file
        with open(filename, 'r') as file:
            content = file.read()
        
        print("\nReading from file:")
        print(content)
        
        # Alternative: Read line by line
        print("\nReading line by line:")
        with open(filename, 'r') as file:
            for line_num, line in enumerate(file, 1):
                print(f"Line {line_num}: {line.strip()}")
                
    except IOError as e:
        print(f"File operation error: {e}")
    
    finally:
        # Clean up
        try:
            import os
            os.remove(filename)
        except FileNotFoundError:
            pass

if __name__ == "__main__":
    file_operations()