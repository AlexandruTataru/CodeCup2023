#!/usr/bin/python3

from tkinter import CURRENT
from graphics import *

BLOCK_SIZE = 50
CURRENT_COLOR = 1

win = GraphWin("CodeCup 2023 - Algorithm Visualizer", 10 * BLOCK_SIZE, 10 * BLOCK_SIZE)
win.setBackground("white")

COLORS = ["", "white", "#ffff43", "#ff8800", "#bb0100", "#bb01bb", "#0088ff", "black"]

ds = [  [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0] ]

ROW_SCORES = []
COL_SCORES = []

for i in range(0, 7):
    row = Text(Point(BLOCK_SIZE * 8.5, BLOCK_SIZE * (i + 2.5)), "0")
    row.setSize(20)
    ROW_SCORES.append(row)
    col = Text(Point(BLOCK_SIZE * (i + 1.5), BLOCK_SIZE * 9.5), "0")
    col.setSize(20)
    COL_SCORES.append(col)

def mouseCallback(clickedPoint):
    global CURRENT_COLOR
    global ds
    column = int(clickedPoint.x/BLOCK_SIZE)
    row = int(clickedPoint.y/BLOCK_SIZE)

    if row == 0:
        CURRENT_COLOR = column

    row = row - 2
    column = column - 1
    if row in range(0, 7) and column in range(0, 7):
        c = Circle(Point((column + 1) * BLOCK_SIZE + BLOCK_SIZE/2, (row + 2) * BLOCK_SIZE + BLOCK_SIZE/2), BLOCK_SIZE * 0.4)
        c.setFill(COLORS[CURRENT_COLOR])
        c.draw(win)
        ds[row][column] = CURRENT_COLOR

    update_scores()

class Cell:
    def __init__(self, topLeft, size):
        self.topLeft = topLeft
        self.size = size

        self.shape = Rectangle(topLeft, Point(topLeft.x + size, topLeft.y + size))
        self.shape.setWidth(1)
        self.shape.setFill("#dddddd")

    def Draw(self, window):
        self.shape.draw(window)

def draw_color_picker():
    for p in range(1, 8):
        c = Circle(Point(BLOCK_SIZE * (p + 0.5), BLOCK_SIZE/2), BLOCK_SIZE * 0.4)
        c.setFill(COLORS[p])
        c.draw(win)

def draw_static_elements():
    draw_color_picker()

    Text(Point(BLOCK_SIZE * 1.5, BLOCK_SIZE * 1.8), "a").draw(win)
    Text(Point(BLOCK_SIZE * 2.5, BLOCK_SIZE * 1.8), "b").draw(win)
    Text(Point(BLOCK_SIZE * 3.5, BLOCK_SIZE * 1.8), "c").draw(win)
    Text(Point(BLOCK_SIZE * 4.5, BLOCK_SIZE * 1.8), "d").draw(win)
    Text(Point(BLOCK_SIZE * 5.5, BLOCK_SIZE * 1.8), "e").draw(win)
    Text(Point(BLOCK_SIZE * 6.5, BLOCK_SIZE * 1.8), "f").draw(win)
    Text(Point(BLOCK_SIZE * 7.5, BLOCK_SIZE * 1.8), "g").draw(win)

    Text(Point(BLOCK_SIZE * 0.8, BLOCK_SIZE * 1.5 + BLOCK_SIZE), "A").draw(win)
    Text(Point(BLOCK_SIZE * 0.8, BLOCK_SIZE * 2.5 + BLOCK_SIZE), "B").draw(win)
    Text(Point(BLOCK_SIZE * 0.8, BLOCK_SIZE * 3.5 + BLOCK_SIZE), "C").draw(win)
    Text(Point(BLOCK_SIZE * 0.8, BLOCK_SIZE * 4.5 + BLOCK_SIZE), "D").draw(win)
    Text(Point(BLOCK_SIZE * 0.8, BLOCK_SIZE * 5.5 + BLOCK_SIZE), "E").draw(win)
    Text(Point(BLOCK_SIZE * 0.8, BLOCK_SIZE * 6.5 + BLOCK_SIZE), "F").draw(win)
    Text(Point(BLOCK_SIZE * 0.8, BLOCK_SIZE * 7.5 + BLOCK_SIZE), "G").draw(win)

def start():
    draw_static_elements()
    update_scores()
    win.setMouseHandler(mouseCallback)
    for i in range(1, 8):
        for j in range(1, 8):
            Cell(Point(BLOCK_SIZE * i, BLOCK_SIZE * j + BLOCK_SIZE), BLOCK_SIZE).Draw(win)
    win.mainloop()

def get_score_on_line(game_line):
    score = 0
    for s in range(0, 6):
        for e in range(s + 2, 8):
            if 0 in game_line[s:e]:
                continue
            lr = game_line[s:e]
            rl = game_line[s:e]
            rl.reverse()
            if lr == rl:
                score = score + (e - s)
    return score

def update_scores():
    global ds
    global ROW_SCORES
    global COL_SCORES

    for i in range(0, 7):
        ROW_SCORES[i].setText(str(get_score_on_line(ds[i])))
        ROW_SCORES[i].undraw()
        ROW_SCORES[i].draw(win)
        COL_SCORES[i].setText(str(get_score_on_line([row[i] for row in ds])))
        COL_SCORES[i].undraw()
        COL_SCORES[i].draw(win)

if __name__ == "__main__":
    start()