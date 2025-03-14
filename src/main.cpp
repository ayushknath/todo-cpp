#include "todo.h"
#include "validator.h"

using namespace std;

int main()
{
    IO io;
    Todo todo;
    Validator validate{todo.get_todos_ref()};
    int user_choice;
    int exit_code = 7;
    int task_number;
    string task_number_str;
    bool first_iteration = true;

    do
    {
        todo.greet(&first_iteration);

        cout << ": ";
        cin >> user_choice;

        // Input validation stage
        if (user_choice == 3 || user_choice == 4 || user_choice == 5 || user_choice == 6)
        {
            todo.view_todos(false);

            if (todo.empty())
                continue;

            switch (user_choice)
            {
            case 3:
                cout << "Task to check-off: ";
                break;
            case 4:
                cout << "Task to uncheck: ";
                break;
            case 5:
                cout << "Task to modify: ";
                break;
            case 6:
                cout << "Task to delete: ";
                break;
            }
            cin >> task_number_str;

            // check for valid integer
            if ((task_number = validate.valid_integer(task_number_str)) == -1)
            {
                cout << "Invalid number!\n";
                cout << "Program terminated\n";
                exit(1);
            }

            // check if item_number is in range
            if (!validate.in_range(task_number))
            {
                cout << "No such task exist\n";
                continue;
            }
        }

        // Perform desried action
        switch (user_choice)
        {
        case 1:
            todo.create_todo();
            break;
        case 2:
            todo.view_todos();
            break;
        case 3:
            todo.task_checkoff(task_number);
            break;
        case 4:
            todo.task_uncheck(task_number);
            break;
        case 5:
            todo.modify_task(task_number);
            break;
        case 6:
            todo.delete_task(task_number);
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
            exit(1);
        }
    } while (user_choice != exit_code);

    return 0;
}
