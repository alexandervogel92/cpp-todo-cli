#include "todo.hpp"
#include "ui.hpp"

#include <string>

int main() {
    TodoList todos;
    const std::string todoFile = "todos.txt";
    todos.loadFromFile(todoFile);
    Screen screen = Screen::Main;

    while (screen != Screen::Exit) {
        if (screen == Screen::Main) screen = runMainMenu();
        else if (screen == Screen::Add) screen = runAddScreen(todos, todoFile);
        else if (screen == Screen::List) screen = runListScreen(todos);
        else if (screen == Screen::Toggle) screen = runToggleScreen(todos, todoFile);
    }

    return 0;
}
