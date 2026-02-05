#include "ui.hpp"
#include "todo.hpp"
#include "colors.hpp"

#include <iostream>
#include <string>

namespace {
    constexpr int HEADER_WIDTH = 18;

    void clearScreen() {
        std::cout << "\033[2J\033[1;1H" << std::flush;
    }

    std::string readLine() {
        std::string input;
        std::getline(std::cin, input);
        return input;
    }

    void printHeader(const std::string& title) {
        std::string line(HEADER_WIDTH, '=');
        std::string inner = " " + title + " ";
            if (static_cast<int>(inner.size()) > HEADER_WIDTH) {
                inner.resize(HEADER_WIDTH);
            }

            const int padding = HEADER_WIDTH - static_cast<int>(inner.size());
            const int left = padding / 2;
            const int right = padding - left;
            std::string middle = std::string(left, '=') + inner + std::string(right, '=');

            std::cout << ansi::BOLD << ansi::CYAN
                      << line << "\n"
                      << middle << "\n"
                  << line << ansi::RESET << "\n\n";
    }

    void updateStatusAndResetPrompt(const std::string& msg, const char* color) {
        std::cout << "\033[2A"; // up to status line
        std::cout << "\033[2K\r";
        if (!msg.empty()) {
            std::cout << color << msg << ansi::RESET;
        }
        std::cout << "\033[1B"; // down to prompt line
        std::cout << "\033[2K\r";
    }
} // namespace

Screen runMainMenu() {
    while (true) {
        clearScreen();
        printHeader("TODO");
        std::cout << ansi::YELLOW << "1" << ansi::RESET << " Add\n";
        std::cout << ansi::YELLOW << "2" << ansi::RESET << " List\n";
        std::cout << ansi::RED << "0" << ansi::RESET << " Exit\n";
        std::cout << ansi::DIM << " > " << ansi::RESET;

        const std::string input = readLine();
        if (input == "1") return Screen::Add;
        if (input == "2") return Screen::List;
        if (input == "0") return Screen::Exit;
    }
}

Screen runAddScreen(TodoList& todos) {
    clearScreen();
    printHeader("ADD TASK");
    std::cout << ansi::DIM << "enter task, back with !" << ansi::RESET << "\n";
    std::cout << "\n";

    while (true) {
        std::cout << ansi::DIM << "> " << ansi::RESET;
        const std::string text = readLine();
        if (text == "!") return Screen::Main;

        if (!text.empty()) {
            todos.add(text);
            updateStatusAndResetPrompt("Added: " + text, ansi::GREEN);
        } else {
            updateStatusAndResetPrompt("Empty input", ansi::YELLOW);
        }
    }
}

Screen runListScreen(TodoList& todos) {
    clearScreen();
    printHeader("LIST");
    todos.list();
    std::cout << "\n" << ansi::DIM << "back with !" << ansi::RESET << "\n";
    std::cout << ansi::DIM << "> " << ansi::RESET;

    readLine();
    return Screen::Main;
}
