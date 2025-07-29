class Student:
    def __init__(self, name, student_id, gpa):
        self.name = name
        self.id = student_id
        self.gpa = gpa
    
    # Getter methods (Python properties)
    @property
    def name(self):
        return self._name
    
    @name.setter
    def name(self, value):
        self._name = value
    
    @property
    def id(self):
        return self._id
    
    @id.setter
    def id(self, value):
        self._id = value
    
    @property
    def gpa(self):
        return self._gpa
    
    @gpa.setter
    def gpa(self, value):
        self._gpa = value
        print(f"GPA updated to {value} for {self.name}")
    
    def display(self):
        print(f"Student: {self.name} (ID: {self.id}, GPA: {self.gpa})")
    
    def is_honor_student(self):
        return self.gpa >= 3.5
    
    def __str__(self):
        return f"Student(name='{self.name}', id={self.id}, gpa={self.gpa})"

# Usage example
if __name__ == "__main__":
    student1 = Student("Alice Johnson", 12345, 3.8)
    
    student1.display()
    
    if student1.is_honor_student():
        print(f"{student1.name} is an honor student!")
    
    student1.gpa = 3.9
    student1.display()