#pragma once

#include <string>

class TodoList;

enum class Screen {
    Main,
    Add,
    List,
    Toggle,
    Exit
};

Screen runMainMenu();
Screen runAddScreen(TodoList& todos, const std::string& storagePath);
Screen runListScreen(TodoList& todos);
Screen runToggleScreen(TodoList& todos, const std::string& storagePath);
