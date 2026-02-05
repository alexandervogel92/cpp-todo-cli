#include "todo.hpp"
#include "colors.hpp"
#include <iostream>

void TodoList::add(const std::string& text) {
    tasks.push_back({text, false});
}

void TodoList::list() const {
    for (size_t i = 0; i < tasks.size(); ++i) {
        const char* stateColor = tasks[i].done ? ansi::GREEN : ansi::RED;
        const char* stateText = tasks[i].done ? "[x] " : "[ ] ";
        std::cout << i + 1 << ". "
                  << stateColor << stateText << ansi::RESET
                  << tasks[i].text << "\n";
    }
}
