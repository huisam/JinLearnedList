class Rectangle:
    count = 0
    def __init__(self,width,height):
        self.width = width
        self.height = height
        Rectangle.count += 1

    def calcArea(self):
        area = self.width * self.height
        return area

    @staticmethod
    def isSquare(rectwidth,rectheight):
        return rectwidth == rectheight

    @classmethod
    def printcount(cls):
        print(cls.count)

class shape(Rectangle):
    def __init__(self,name):
        self.name = name
class Cover(Rectangle):
    def __init__(self,obtion):
        self.obtion = obtion

if '__main__':
    square = Rectangle.isSquare(5,5)
    print(square)

    rect1 = Rectangle(5,5)
    rect2 = Rectangle(2,5)
    Rectangle.count = 10
    rect1.count = 22
    rect1.printcount()
    Rectangle.printcount()
    mydream = Cover('hhj')
    mydream.width = 1
    mydream.height = 1
    print(mydream.obtion)
    print(mydream.calcArea())
