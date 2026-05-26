# FLAPPY BIRD GAME USING STM32

## Giới thiệu

Đây là project xây dựng game Flappy Bird sử dụng KIT STM32F401RE và màn hình LCD TFT ST7735.

Game được phát triển bằng ngôn ngữ C trên STM32 SPL SDK.

---

## Chức năng chính

- Điều khiển chim bằng nút nhấn
- Có 2 level:
  - Easy
  - Hard
- Tốc độ ống thay đổi theo level
- Phát âm thanh khi nhấn nút điều khiển
- LED nhấp nháy khi game over
- Hiển thị điểm số trên LCD

---

## Phần cứng sử dụng

| Thiết bị | Mô tả |
|---|---|
| STM32F401RE | Vi điều khiển chính |
| LCD ST7735 | Hiển thị game |
| Push Button | Điều khiển |
| LED | Báo hiệu game over |
| Buzzer | Phát âm thanh |

---

## Thư viện sử dụng

- STM32 SPL
- ucglib

---

## Cấu trúc project

```text
Inc/
├── main.h
├── bird.h
├── pipe.h
├── game.h
└── buzzer.h

Src/
├── main.c
├── bird.c
├── pipe.c
├── game.c
└── buzzer.c
```

---

## Thuật toán hoạt động

### Luồng chính

1. Khởi tạo GPIO
2. Khởi tạo LCD
3. Khởi tạo game
4. Hiển thị menu
5. Chọn level
6. Bắt đầu game
7. Điều khiển chim
8. Kiểm tra va chạm
9. Game over
10. Nhấp nháy LED

---

## Lưu đồ thuật toán

```text
START
  |
INIT SYSTEM
  |
INIT LCD
  |
INIT GAME
  |
SHOW MENU
  |
SELECT LEVEL
  |
START GAME
  |
READ BUTTON
  |
UPDATE BIRD
  |
UPDATE PIPE
  |
CHECK COLLISION
  |
+----NO----+
|          |
|       DRAW GAME
|          |
+<---------+
|
YES
|
GAME OVER
|
LED BLINK
|
RESTART
```

---

## Điều khiển

| Nút | Chức năng |
|---|---|
| BTN1 | Jump / Start |
| BTN2 | Change Level |

---

## Các level

### Easy
- Pipe speed = 2

### Hard
- Pipe speed = 4

---

## Hướng dẫn build project

### Bước 1
Clone project:

```bash
git clone <your-github-link>
```

### Bước 2
Mở bằng STM32CubeIDE.

### Bước 3
Build project.

### Bước 4
Nạp chương trình vào KIT STM32.

---

## Demo game

Thêm ảnh game tại đây:

```markdown
![demo](images/demo.jpg)
```

---

## Kết quả đạt được

- Game hoạt động ổn định trên STM32
- LCD hiển thị mượt
- Điều khiển thời gian thực
- Hoàn thành đầy đủ yêu cầu đề bài

---

## Tác giả
Nguyễn Văn Quang + Nguyễn Thành Nam
