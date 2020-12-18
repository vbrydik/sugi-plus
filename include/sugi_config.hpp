#pragma once
#include <map>
#include <string>
#include <fstream>


std::map<std::string, std::string> read_config(std::string filename)
{
    std::map<std::string, std::string> config_map;

    std::fstream filestream;
    filestream.open(filename);

    if (filestream.is_open())
    {
        std::string line;
        std::string section = "";

        while (std::getline(filestream, line))
        {
            bool is_value = false;
            bool is_section = false;
            std::string key = "";
            std::string value = "";

            // Section
            if (line[0] == '[')
            {
                int j;
                for (j = 1; j < line.length(); j++)
                {
                    if (line[j] == ']')
                    {
                        is_section = true;
                        break;
                    }
                }

                if (is_section)
                {
                    section = "";
                    for (int i = 1; i < j; i++)
                        section += line[i];
                    if (section.length() > 0)
                        section += '.';
                }
            }

            //  Key-value pair
            if (!is_section)
            {
                for (int i = 0; i < line.length(); i++)
                {
                    if (line[i] == '=')
                        is_value = true;
                    else if (line[i] == '#')
                        break;
                    else if (line[i] == ' ' && !is_value)
                        continue;
                    else
                    {
                        if (is_value)
                            value += line[i];
                        else
                            key += line[i];
                    }
                }

                if (value.length() > 0)
                    config_map[section + key] = value;
            }
        }
        filestream.close();
    }

    return config_map;
}
