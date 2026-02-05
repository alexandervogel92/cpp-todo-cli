#pragma once

class TodoList;

enum class Screen {
    Main,
    Add,
    List,
    Exit
};

Screen runMainMenu();
Screen runAddScreen(TodoList& todos);
Screen runListScreen(TodoList& todos);
