#!/usr/bin/python3

from tkinter import CURRENT
from graphics import *

BLOCK_SIZE = 50
CURRENT_COLOR = '1'
CELL_COLOR = '#e43326'

COLORS = ["", "red", "green", "blue", "white", "black", "pink", "cyan"]

ds = [  [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0] ]

SCORE_ROW_0 = Text(Point(BLOCK_SIZE * 8.5, BLOCK_SIZE * 2.5), "0")
SCORE_ROW_1 = Text(Point(BLOCK_SIZE * 8.5, BLOCK_SIZE * 3.5), "0")
SCORE_ROW_2 = Text(Point(BLOCK_SIZE * 8.5, BLOCK_SIZE * 4.5), "0")
SCORE_ROW_3 = Text(Point(BLOCK_SIZE * 8.5, BLOCK_SIZE * 5.5), "0")
SCORE_ROW_4 = Text(Point(BLOCK_SIZE * 8.5, BLOCK_SIZE * 6.5), "0")
SCORE_ROW_5 = Text(Point(BLOCK_SIZE * 8.5, BLOCK_SIZE * 7.5), "0")
SCORE_ROW_6 = Text(Point(BLOCK_SIZE * 8.5, BLOCK_SIZE * 8.5), "0")

SCORE_COL_0 = Text(Point(BLOCK_SIZE * 1.5, BLOCK_SIZE * 9.5), "0")
SCORE_COL_1 = Text(Point(BLOCK_SIZE * 2.5, BLOCK_SIZE * 9.5), "0")
SCORE_COL_2 = Text(Point(BLOCK_SIZE * 3.5, BLOCK_SIZE * 9.5), "0")
SCORE_COL_3 = Text(Point(BLOCK_SIZE * 4.5, BLOCK_SIZE * 9.5), "0")
SCORE_COL_4 = Text(Point(BLOCK_SIZE * 5.5, BLOCK_SIZE * 9.5), "0")
SCORE_COL_5 = Text(Point(BLOCK_SIZE * 6.5, BLOCK_SIZE * 9.5), "0")
SCORE_COL_6 = Text(Point(BLOCK_SIZE * 7.5, BLOCK_SIZE * 9.5), "0")

def mouseCallback(clickedPoint):
    global CURRENT_COLOR
    global ds
    column = int(clickedPoint.x/BLOCK_SIZE)
    row = int(clickedPoint.y/BLOCK_SIZE)

    if row == 0:
        CURRENT_COLOR = str(column)

    row = row - 1
    column = column - 1
    if row in range(0, 7) and column in range(0, 7):
        c = Circle(Point(column * BLOCK_SIZE + BLOCK_SIZE + BLOCK_SIZE/2, row * BLOCK_SIZE + BLOCK_SIZE + BLOCK_SIZE/2), BLOCK_SIZE * 0.4)
        c.setFill(COLORS[int(CURRENT_COLOR)])
        c.draw(win)
        ds[row][column] = int(CURRENT_COLOR)

    update_scores()

win = GraphWin("CodeCup 2023 - Algorithm Visualizer", 10 * BLOCK_SIZE, 10 * BLOCK_SIZE)
win.setMouseHandler(mouseCallback)

class Cell:
    def __init__(self, topLeft, size):
        self.topLeft = topLeft
        self.size = size

        self.shape = Rectangle(topLeft, Point(topLeft.x + size, topLeft.y + size))
        self.shape.setWidth(1)
        self.shape.setFill("grey")

    def Draw(self, window):
        self.shape.draw(window)

def draw_static_elements():
    c = Circle(Point(BLOCK_SIZE * 1.5, BLOCK_SIZE/2), BLOCK_SIZE * 0.4)
    c.setFill("red")
    c.draw(win)

    c = Circle(Point(BLOCK_SIZE * 2.5, BLOCK_SIZE/2), BLOCK_SIZE * 0.4)
    c.setFill("green")
    c.draw(win)

    c = Circle(Point(BLOCK_SIZE * 3.5, BLOCK_SIZE/2), BLOCK_SIZE * 0.4)
    c.setFill("blue")
    c.draw(win)

    c = Circle(Point(BLOCK_SIZE * 4.5, BLOCK_SIZE/2), BLOCK_SIZE * 0.4)
    c.setFill("white")
    c.draw(win)

    c = Circle(Point(BLOCK_SIZE * 5.5, BLOCK_SIZE/2), BLOCK_SIZE * 0.4)
    c.setFill("black")
    c.draw(win)

    c = Circle(Point(BLOCK_SIZE * 6.5, BLOCK_SIZE/2), BLOCK_SIZE * 0.4)
    c.setFill("pink")
    c.draw(win)

    c = Circle(Point(BLOCK_SIZE * 7.5, BLOCK_SIZE/2), BLOCK_SIZE * 0.4)
    c.setFill("cyan")
    c.draw(win)

    Text(Point(BLOCK_SIZE * 1.5, BLOCK_SIZE/2 + BLOCK_SIZE), "a").draw(win)
    Text(Point(BLOCK_SIZE * 2.5, BLOCK_SIZE/2 + BLOCK_SIZE), "b").draw(win)
    Text(Point(BLOCK_SIZE * 3.5, BLOCK_SIZE/2 + BLOCK_SIZE), "c").draw(win)
    Text(Point(BLOCK_SIZE * 4.5, BLOCK_SIZE/2 + BLOCK_SIZE), "d").draw(win)
    Text(Point(BLOCK_SIZE * 5.5, BLOCK_SIZE/2 + BLOCK_SIZE), "e").draw(win)
    Text(Point(BLOCK_SIZE * 6.5, BLOCK_SIZE/2 + BLOCK_SIZE), "f").draw(win)
    Text(Point(BLOCK_SIZE * 7.5, BLOCK_SIZE/2 + BLOCK_SIZE), "g").draw(win)

    Text(Point(BLOCK_SIZE/2, BLOCK_SIZE * 1.5 + BLOCK_SIZE), "A").draw(win)
    Text(Point(BLOCK_SIZE/2, BLOCK_SIZE * 2.5 + BLOCK_SIZE), "B").draw(win)
    Text(Point(BLOCK_SIZE/2, BLOCK_SIZE * 3.5 + BLOCK_SIZE), "C").draw(win)
    Text(Point(BLOCK_SIZE/2, BLOCK_SIZE * 4.5 + BLOCK_SIZE), "D").draw(win)
    Text(Point(BLOCK_SIZE/2, BLOCK_SIZE * 5.5 + BLOCK_SIZE), "E").draw(win)
    Text(Point(BLOCK_SIZE/2, BLOCK_SIZE * 6.5 + BLOCK_SIZE), "F").draw(win)
    Text(Point(BLOCK_SIZE/2, BLOCK_SIZE * 7.5 + BLOCK_SIZE), "G").draw(win)

def start():
    draw_static_elements()
    update_scores()

    for i in range(1, 8):
        for j in range(1, 8):
            Cell(Point(BLOCK_SIZE * i, BLOCK_SIZE * j + BLOCK_SIZE), BLOCK_SIZE).Draw(win)

    win.mainloop()

def update_scores():
    global ds
    SCORE_ROW_0.setText(str(ds[0][0] + ds[0][1] + ds[0][2] + ds[0][3] + ds[0][4] + ds[0][5] + ds[0][6]))

    SCORE_ROW_0.undraw()
    SCORE_ROW_0.draw(win)
    SCORE_ROW_1.undraw()
    SCORE_ROW_1.draw(win)
    SCORE_ROW_2.undraw()
    SCORE_ROW_2.draw(win)
    SCORE_ROW_3.undraw()
    SCORE_ROW_3.draw(win)
    SCORE_ROW_4.undraw()
    SCORE_ROW_4.draw(win)
    SCORE_ROW_5.undraw()
    SCORE_ROW_5.draw(win)
    SCORE_ROW_6.undraw()
    SCORE_ROW_6.draw(win)

    SCORE_COL_0.draw(win)
    SCORE_COL_1.draw(win)
    SCORE_COL_2.draw(win)
    SCORE_COL_3.draw(win)
    SCORE_COL_4.draw(win)
    SCORE_COL_5.draw(win)
    SCORE_COL_6.draw(win)

if __name__ == "__main__":
    start()