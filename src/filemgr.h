#ifndef __FILEMGR_H_INCLUDED__
#define __FILEMGR_H_INCLUDED__

#include <vector>
#include <fstream>

class File_Manager
{
private:
    std::vector<std::string> &todos_ref;
    std::string file_name = "todos.txt";
    std::string file_path = "../todos/" + file_name;

public:
    File_Manager(std::vector<std::string> &todos) : todos_ref(todos) {}

    void read_from_file()
    {
        std::ifstream todo_file_read(file_path);
        if (!todo_file_read)
        {
            std::cout << "Failed to read " << file_name << '\n';
            std::cout << "Program terminated\n";
            exit(1);
        }
        std::string line;
        while (std::getline(todo_file_read, line))
        {
            todos_ref.push_back(line + '\n');
        }
        todo_file_read.close();
    }

    void write_to_file()
    {
        std::ofstream todo_file_write(file_path);
        if (!todo_file_write)
        {
            std::cout << "Failed while writing to " << file_name << '\n';
            std::cout << "Program terminated\n";
            exit(1);
        }
        std::string text = "";
        for (std::string todo : todos_ref)
        {
            text += todo;
        }
        todo_file_write << text;
        todo_file_write.close();
    }

    void append_to_file()
    {
        std::ofstream todo_file_append(file_path, std::ios_base::app);
        if (!todo_file_append)
        {
            std::cout << "Failed while appending to " << file_name << '\n';
            std::cout << "Program terminated\n";
            exit(1);
        }
        todo_file_append << todos_ref.at(todos_ref.size() - 1);
        todo_file_append.close();
    }
};

#endif