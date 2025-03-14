#ifndef __TODO_H_INCLUDED__
#define __TODO_H_INCLUDED__

#include "io.h"
#include "filemgr.h"

class Todo
{
private:
    std::vector<std::string> todos;
    IO io;
    File_Manager file_mgr{todos};

public:
    Todo()
    {
        // Create 'todos' folder if not exists

        // Read todos.txt file and populate
        // 'todos' vector with tasks
        file_mgr.read_from_file();
    }

    std::vector<std::string> &get_todos_ref()
    {
        return todos;
    }

    std::vector<std::string> get_todos()
    {
        return todos;
    }

    bool empty()
    {
        return todos.empty();
    }

    void greet(bool *first_iteration)
    {
        if (*first_iteration)
        {
            std::string welcome_message = "Todo app\n";
            int welcome_message_length = welcome_message.length();

            std::cout << welcome_message;
            for (int i = 0; i < welcome_message_length - 1; i++)
            {
                std::cout << "=";
            }
            *first_iteration = false;
        }

        std::cout << "\n\nPlease choose from one of the options below\n\n";
        std::cout << "1. Create new todo\n";
        std::cout << "2. View your todos\n";
        std::cout << "3. Check-off a task\n";
        std::cout << "4. Uncheck a task\n";
        std::cout << "5. Modify a todo\n";
        std::cout << "6. Delete a todo\n";
        std::cout << "7. Exit\n\n";
    }

    void create_todo()
    {
        std::string todo_item;

        std::cout << "Todo item: ";
        todo_item = io.get_line();

        todos.push_back(todo_item + '\n');

        file_mgr.append_to_file();
    }

    void view_todos(bool wait = true)
    {
        std::cout << '\n';
        if (empty())
        {
            std::cout << "No todos yet\n";
        }
        else
        {
            for (int i = 0; i < todos.size(); i++)
            {
                std::cout << '(' << i + 1 << ") " << todos.at(i);
            }
        }
        std::cout << '\n';

        if (wait)
            io.wait_till_enter();
    }

    void task_checkoff(int task_number)
    {
        std::string todo_item;
        std::string tick_expr = " ✅\n";

        todo_item = todos.at(task_number - 1);
        todos.at(task_number - 1) = todo_item.substr(0, todo_item.length() - 1) + tick_expr;

        file_mgr.write_to_file();
    }

    void task_uncheck(int task_number)
    {
        std::string todo_item;
        std::string tick_expr = " ✅\n";
        int tick_expr_length = tick_expr.length();

        todo_item = todos.at(task_number - 1);
        if (todo_item.find("✅") != -1)
        {
            todos.at(task_number - 1) = todo_item.substr(0, todo_item.length() - tick_expr_length) + '\n';
            file_mgr.write_to_file();
        }
    }

    void modify_task(int task_number)
    {
        std::string new_task;

        std::cout << "New todo: ";
        new_task = io.get_line() + '\n';

        todos.at(task_number - 1) = new_task;
        file_mgr.write_to_file();
    }

    void delete_task(int task_number)
    {
        if (task_number == todos.size())
        {
            todos.pop_back();
        }
        else
        {
            for (int i = task_number; i < todos.size(); i++)
            {
                todos.at(i - 1) = todos.at(i);
            }
            todos.pop_back();
        }

        file_mgr.write_to_file();

        std::cout << "Item #" << task_number << " deleted\n";
        io.wait_till_enter();
    }
};

#endif