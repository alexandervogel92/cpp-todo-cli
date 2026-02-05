#include "todo.hpp"
#include "colors.hpp"

#include <fstream>
#include <iomanip>
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

bool TodoList::toggleDone(size_t index1based) {
    if (index1based == 0 || index1based > tasks.size()) return false;
    tasks[index1based - 1].done = !tasks[index1based - 1].done;
    return true;
}

bool TodoList::loadFromFile(const std::string& path) {
    std::ifstream in(path);
    if (!in) return false;

    tasks.clear();
    int done = 0;
    std::string text;
    while (in >> done >> std::quoted(text)) {
        tasks.push_back({text, done != 0});
    }
    return true;
}

bool TodoList::saveToFile(const std::string& path) const {
    std::ofstream out(path);
    if (!out) return false;

    for (const auto& task : tasks) {
        out << (task.done ? 1 : 0) << ' ' << std::quoted(task.text) << "\n";
    }
    return true;
}
