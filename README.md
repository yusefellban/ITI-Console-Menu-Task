# ITI-Console-Menu-Task
# 🎨 Interactive Console Menu in C++

A colorful, interactive **console menu system** built with C++ for Windows.  
This project demonstrates cursor movement, keyboard input handling, text coloring, and basic multithreading — all within the console environment.

---

## 🚀 Features

✅ **Keyboard navigation** using arrow keys (`↑`, `↓`, `Home`, `End`)  
✅ **Dynamic highlighting** of selected menu items  
✅ **Animated background message** moving across the console  
✅ **Windows-specific cursor control** using `gotoxy()`  
✅ **Multi-threaded design** with real-time updates  

---

## 🖥️ Menu Options

| Option | Description |
|:--------|:-------------|
| **File** | Displays “File Entered” |
| **Edit** | Displays “Edit Entered” |
| **Save** | Displays “Save Entered” |
| **Exit** | Displays “Exit Entered” |

---

## ⚙️ Requirements

- **Operating System:** Windows  
- **Compiler:** Any C++ compiler supporting `<windows.h>` and `<conio.h>`  
  - Examples: MinGW (g++), Microsoft Visual Studio, or Dev-C++  

---

## 🧩 How to Build and Run

### 🔧 Using MinGW (g++)
```bash
g++ main.cpp -o ConsoleMenu -std=c++11
ConsoleMenu.exe
```

# 🧵 Code Highlights

##  gotoxy() Function  
Moves the cursor to a specific location in the console window:  

```cpp
void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
```


## 🧑‍💻 Author
### Yousef Ellban
