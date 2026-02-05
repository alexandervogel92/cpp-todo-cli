# ToDo (CLI)

Small CLI tool for managing tasks in the terminal.

## Features
- Add, list, and toggle tasks as done
- Tasks are saved in `todos.txt`
- Colored output (ANSI)

## Build

### Linux/macOS
```bash
cmake -S . -B build
cmake --build build
./build/ToDo
```

### Windows (MSVC)
```powershell
cmake -S . -B build
cmake --build build --config Release
.\build\Release\ToDo.exe
```

### Windows (MinGW)
```powershell
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
.\build\ToDo.exe
```

## Notes
- C++20 is required.
- CMake is required.

