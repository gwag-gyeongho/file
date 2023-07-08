import tkinter
from tkinter import messagebox

class BrickBreakerGame:
    def __init__(self, window):
        self.window = window
        self.canvas = tkinter.Canvas(window, width=800, height=600, bg="black")
        self.canvas.pack()
        self.paddle_start_x = 350  # 패들의 시작 x 좌표
        self.paddle = self.canvas.create_rectangle(self.paddle_start_x, 550, self.paddle_start_x + 100, 570, fill="white")
        self.ball_start_x = self.paddle_start_x + 20  # 공의 시작 x 좌표 (패들 위에 위치)
        self.ball = self.canvas.create_oval(self.ball_start_x, 535, self.ball_start_x + 20, 555, fill="white")
        self.canvas.bind("<KeyPress-Left>", self.move_paddle_left)
        self.canvas.bind("<KeyPress-Right>", self.move_paddle_right)
        self.canvas.focus_set()
        self.ball_speed_x = 3
        self.ball_speed_y = -3
        self.bricks = []
        for row in range(5):
            for col in range(10):
                x = col * 75
                y = row * 25
                brick = self.canvas.create_rectangle(x, y, x + 70, y + 20, fill="blue")
                self.bricks.append(brick)
        self.canvas_width = 800
        self.canvas_height = 600
        self.score = 0
        self.lives = 3
        self.score_label = tkinter.Label(window, text="점수: 0", font=("Arial", 16), fg="white", bg="black")
        self.score_label.pack()
        self.lives_label = tkinter.Label(window, text="공의 개수: 3", font=("Arial", 16), fg="white", bg="black")
        self.lives_label.pack()

    def run_game(self):
        self.move_ball()
        self.check_collision()
        self.window.after(10, self.run_game)

    def move_paddle_left(self, event):
        if self.canvas.coords(self.paddle)[0] > 0:
            self.canvas.move(self.paddle, -20, 0)

    def move_paddle_right(self, event):
        if self.canvas.coords(self.paddle)[2] < self.canvas_width:
            self.canvas.move(self.paddle, 20, 0)

    def move_ball(self):
        ball_coords = self.canvas.coords(self.ball)
        if ball_coords[0] <= 0 or ball_coords[2] >= self.canvas_width:
            self.ball_speed_x *= -1
        if ball_coords[1] <= 0:
            self.ball_speed_y *= -1
        elif ball_coords[3] >= self.canvas_height:
            self.lives -= 1
            self.lives_label.config(text="공의 개수: {}".format(self.lives))
            if self.lives > 0:
                self.canvas.move(self.ball, self.ball_start_x - ball_coords[0], 535 - ball_coords[1])  # 패들 위로 공 이동
                self.ball_speed_y *= -1
            else:
                self.end_game()
        self.canvas.move(self.ball, self.ball_speed_x, self.ball_speed_y)

    def check_collision(self):
        ball_coords = self.canvas.coords(self.ball)
        paddle_coords = self.canvas.coords(self.paddle)
        if ball_coords[2] >= paddle_coords[0] and ball_coords[0] <= paddle_coords[2] and ball_coords[3] >= paddle_coords[1]:
            self.ball_speed_y *= -1
        for brick in self.bricks:
            brick_coords = self.canvas.coords(brick)
            if ball_coords[2] >= brick_coords[0] and ball_coords[0] <= brick_coords[2] and ball_coords[3] >= brick_coords[1] and ball_coords[1] <= brick_coords[3]:
                self.canvas.delete(brick)
                self.bricks.remove(brick)
                self.ball_speed_y *= -1
                self.score += 1
                self.update_score()

    def update_score(self):
        self.score_label.config(text="점수: {}".format(self.score))

    def end_game(self):
        messagebox.showinfo("Game Over", "Game Over")
        self.window.quit()

window = tkinter.Tk()
window.title("Brick Breaker Game")
game = BrickBreakerGame(window)
game.run_game()
window.mainloop()
