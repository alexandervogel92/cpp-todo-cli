#include "todo.hpp"
#include "ui.hpp"

int main() {
    TodoList todos;
    Screen screen = Screen::Main;

    while (screen != Screen::Exit) {
        if (screen == Screen::Main) screen = runMainMenu();
        else if (screen == Screen::Add) screen = runAddScreen(todos);
        else if (screen == Screen::List) screen = runListScreen(todos);
    }

    return 0;
}
