#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <sys/stat.h>

#include "pokedex.h"

using namespace std;

void printData(char filename[50])
{
    struct stat buf;
    std::string path = "/share/cs327/pokedex/pokedex/data/csv/";
    string home = "/.poke327/pokedex/pokedex/data/csv/";

    // check if /share/cs327 exist
   if (stat(path.c_str(), &buf) == -1)
    {
        path = getenv("HOME") + home;
    }

    // if not, then do home pathway
    // if (!stat(path.c_str(), &buf))
    // {
    //     path += home;
    // }

    // if (stat(path.c_str(), &buf))
    // {
    //     path = "";
    // }

    // if (path != "" && !stat("/share/cs327", &buf)) {
    //     path += share;
    // }

    // error checking for file pathway
    if (stat(path.c_str(), &buf))
    {
        printf("Pathway not found\n");
        return;
    }

    std::ifstream file(path);

    std::string line;

    std::vector<std::string> pokedex;
    int i = 0;

    // pokemon.csv
    if (strcmp(filename, "pokemon") == 0)
    {
        path += "pokemon.csv";
        std::ifstream file(path);

        while (getline(file, line))
        {
            std::stringstream sstr(line);
            std::string word;

            while (getline(sstr, word, ','))
            {
                if (!word.empty())
                {
                    pokedex.push_back(word);
                }
                else
                {
                    pokedex.push_back("INT_MAX");
                }
                i++;
            }

            if (i == 7)
            {
                pokedex.push_back("INT_MAX");
            }

            i = 0;
        }
        file.close();

        for (size_t i = 0; i < pokedex.size(); ++i)
        {
            if (pokedex[i] == "INT_MAX")
            {
                std::cout << " "
                          << " ";
            }
            else
            {
                std::cout << pokedex[i] << " ";
            }
            if ((i + 1) % 8 == 0)
                std::cout << std::endl;
        }
    }

    // moves.csv
    if (strcmp(filename, "moves") == 0)
    {
        path += "moves.csv";
        std::ifstream file(path);

        while (getline(file, line))
        {
            std::stringstream sstr(line);
            std::string word;

            while (getline(sstr, word, ','))
            {
                if (!word.empty())
                {
                    pokedex.push_back(word);
                }
                else
                {
                    pokedex.push_back("INT_MAX");
                }
                i++;
            }

            if (i == 14)
            {
                pokedex.push_back("INT_MAX");
            }

            i = 0;
        }
        file.close();

        for (size_t i = 0; i < pokedex.size(); ++i)
        {
            if (pokedex[i] == "INT_MAX")
            {
                std::cout << " "
                          << " ";
            }
            else
            {
                std::cout << pokedex[i] << " ";
            }
            if ((i + 1) % 15 == 0)
                std::cout << std::endl;
        }
    }

    // pokemon_moves.csv
    if (strcmp(filename, "pokemon_moves") == 0)
    {
        path += "pokemon_moves.csv";
        std::ifstream file(path);

        while (getline(file, line))
        {
            std::stringstream sstr(line);
            std::string word;

            while (getline(sstr, word, ','))
            {
                if (!word.empty())
                {
                    pokedex.push_back(word);
                }
                else
                {
                    pokedex.push_back("INT_MAX");
                }
                i++;
            }

            if (i == 5)
            {
                pokedex.push_back("INT_MAX");
            }

            i = 0;
        }
        file.close();

        for (size_t i = 0; i < pokedex.size(); ++i)
        {
            if (pokedex[i] == "INT_MAX")
            {
                std::cout << " "
                          << " ";
            }
            else
            {
                std::cout << pokedex[i] << " ";
            }
            if ((i + 1) % 6 == 0)
                std::cout << std::endl;
        }
    }

    // pokemon_species.csv
    if (strcmp(filename, "pokemon_species") == 0)
    {
        path += "pokemon_species.csv";
        std::ifstream file(path);

        while (getline(file, line))
        {
            std::stringstream sstr(line);
            std::string word;

            while (getline(sstr, word, ','))
            {
                if (!word.empty())
                {
                    pokedex.push_back(word);
                }
                else
                {
                    pokedex.push_back("INT_MAX");
                }
                i++;
            }

            if (i == 19)
            {
                pokedex.push_back("INT_MAX");
            }

            i = 0;
        }
        file.close();

        for (size_t i = 0; i < pokedex.size(); ++i)
        {
            if (pokedex[i] == "INT_MAX")
            {
                std::cout << " "
                          << " ";
            }
            else
            {
                std::cout << pokedex[i] << " ";
            }
            if ((i + 1) % 20 == 0)
                std::cout << std::endl;
        }
    }

    // experience.csv
    if (strcmp(filename, "experience") == 0)
    {
        path += "experience.csv";
        std::ifstream file(path);

        while (getline(file, line))
        {
            std::stringstream sstr(line);
            std::string word;

            while (getline(sstr, word, ','))
            {
                if (!word.empty())
                {
                    pokedex.push_back(word);
                }
                else
                {
                    pokedex.push_back("INT_MAX");
                }
                i++;
            }

            if (i == 2)
            {
                pokedex.push_back("INT_MAX");
            }

            i = 0;
        }
        file.close();

        for (size_t i = 0; i < pokedex.size(); ++i)
        {
            if (pokedex[i] == "INT_MAX")
            {
                std::cout << " "
                          << " ";
            }
            else
            {
                std::cout << pokedex[i] << " ";
            }
            if ((i + 1) % 3 == 0)
                std::cout << std::endl;
        }
    }

    // type_names.csv
    if (strcmp(filename, "type_names") == 0)
    {
        path += "type_names.csv";
        std::ifstream file(path);

        while (getline(file, line))
        {
            std::stringstream sstr(line);
            std::string word;

            while (getline(sstr, word, ','))
            {
                if (!word.empty())
                {
                    pokedex.push_back(word);
                }
                else
                {
                    pokedex.push_back("INT_MAX");
                }
                i++;
            }

            if (i == 2)
            {
                pokedex.push_back("INT_MAX");
            }

            i = 0;
        }
        file.close();

        for (size_t i = 0; i < pokedex.size(); ++i)
        {
            if (pokedex[i] == "INT_MAX")
            {
                std::cout << " "
                          << " ";
            }
            else
            {
                std::cout << pokedex[i] << " ";
            }
            if ((i + 1) % 3 == 0)
                std::cout << std::endl;
        }
    }

    // pokemon_stats.csv
    if (strcmp(filename, "pokemon_stats") == 0)
    {
        path += "pokemon_stats.csv";
        std::ifstream file(path);

        while (getline(file, line))
        {
            std::stringstream sstr(line);
            std::string word;

            while (getline(sstr, word, ','))
            {
                if (!word.empty())
                {
                    pokedex.push_back(word);
                }
                else
                {
                    pokedex.push_back("INT_MAX");
                }
                i++;
            }

            if (i == 3)
            {
                pokedex.push_back("INT_MAX");
            }

            i = 0;
        }
        file.close();

        for (size_t i = 0; i < pokedex.size(); ++i)
        {
            if (pokedex[i] == "INT_MAX")
            {
                std::cout << " "
                          << " ";
            }
            else
            {
                std::cout << pokedex[i] << " ";
            }
            if ((i + 1) % 4 == 0)
                std::cout << std::endl;
        }
    }

    // stats.csv
    if (strcmp(filename, "stats") == 0)
    {
        path += "stats.csv";
        std::ifstream file(path);

        while (getline(file, line))
        {
            std::stringstream sstr(line);
            std::string word;

            while (getline(sstr, word, ','))
            {
                if (!word.empty())
                {
                    pokedex.push_back(word);
                }
                else
                {
                    pokedex.push_back("INT_MAX");
                }
                i++;
            }

            if (i == 4)
            {
                pokedex.push_back("INT_MAX");
            }

            i = 0;
        }
        file.close();

        for (size_t i = 0; i < pokedex.size(); ++i)
        {
            if (pokedex[i] == "INT_MAX")
            {
                std::cout << " "
                          << " ";
            }
            else
            {
                std::cout << pokedex[i] << " ";
            }
            if ((i + 1) % 5 == 0)
                std::cout << std::endl;
        }
    }

    // pokemon_types.csv
    if (strcmp(filename, "pokemon_types") == 0)
    {
        path += "pokemon_types.csv";
        std::ifstream file(path);

        while (getline(file, line))
        {
            std::stringstream sstr(line);
            std::string word;

            while (getline(sstr, word, ','))
            {
                if (!word.empty())
                {
                    pokedex.push_back(word);
                }
                else
                {
                    pokedex.push_back("INT_MAX");
                }
                i++;
            }

            if (i == 2)
            {
                pokedex.push_back("INT_MAX");
            }

            i = 0;
        }
        file.close();

        for (size_t i = 0; i < pokedex.size(); ++i)
        {
            if (pokedex[i] == "INT_MAX")
            {
                std::cout << " "
                          << " ";
            }
            else
            {
                std::cout << pokedex[i] << " ";
            }
            if ((i + 1) % 3 == 0)
                std::cout << std::endl;
        }
    }

    /*
    These methods are alternatives methods of parsing the files
    if the above do not work
    */
   
    // //pokemon.csv
    // if (strcmp(filename, "pokemon") == 0)
    // {
    //     path = strcat(path, "pokemon.csv");
    //     file = fopen(path, "r");

    //     char pokemon[1093];
    //     while (fgets(pokemon, 1093, file))
    //     {
    //         char *v = strtok(pokemon, ",");
    //         while (v)
    //         {
    //             printf("%s ", v);
    //             v = strtok(NULL, ",");
    //         }
    //         printf("\n");
    //     }
    //     fclose(file);
    // }

    // //moves.csv
    // if (strcmp(filename, "moves") == 0)
    // {
    //     path = strcat(path, "moves.csv");
    //     file = fopen(path, "r");

    //     char moves[845];
    //     while (fgets(moves, 845, file))
    //     {
    //         char *v = strtok(pokemon_moves, ",");
    //         while (v)
    //         {
    //             printf("%s ", v);
    //             v = strtok(NULL, ",");
    //         }
    //         printf("\n");
    //     }
    //     fclose(file);
    // }

    // // pokemon_moves.csv
    // if (strcmp(filename, "pokemon_moves") == 0)
    // {
    //     path = strcat(path, "pokemon_moves.csv");
    //     file = fopen(path, "r");

    //     char pokemon_moves[528239];
    //     while (fgets(pokemon_moves, 528239, file))
    //     {
    //         char *v = strtok(pokemon_moves, ",");
    //         while (v)
    //         {
    //             printf("%s ", v);
    //             v = strtok(NULL, ",");
    //         }
    //         printf("\n");
    //     }
    //     fclose(file);
    // }

    // // pokemon_species.csv
    // if (strcmp(filename, "pokemon_species") == 0)
    // {
    //     path = strcat(path, "pokemon_species.csv");
    //     file = fopen(path, "r");

    //     char pokemon_species[899];
    //     while (fgets(pokemon_species, 899, file))
    //     {
    //         char *v = strtok(pokemon_species, ",");
    //         while (v)
    //         {
    //             printf("%s ", v);
    //             v = strtok(NULL, ",");
    //         }
    //         printf("\n");
    //     }
    //     fclose(file);
    // }

    // // experience.csv
    // if (strcmp(filename, "experience") == 0)
    // {
    //     path = strcat(path, "experience.csv");
    //     file = fopen(path, "r");

    //     char experience[601];
    //     while (fgets(experience, 601, file))
    //     {
    //         char *v = strtok(experience, ",");
    //         while (v)
    //         {
    //             printf("%s ", v);
    //             v = strtok(NULL, ",");
    //         }
    //         printf("\n");
    //     }
    //     fclose(file);
    // }

    // // type_names.csv
    // if (strcmp(filename, "type_names") == 0)
    // {
    //     path = strcat(path, "type_names.csv");
    //     file = fopen(path, "r");

    //     char type_names[194];
    //     while (fgets(type_names, 194, file))
    //     {
    //         char *v = strtok(type_names, ",");
    //         while (v)
    //         {
    //             printf("%s ", v);
    //             v = strtok(NULL, ",");
    //         }
    //         printf("\n");
    //     }
    //     fclose(file);
    // }

    // // pokemon_stats.csv
    // if (strcmp(filename, "pokemon_stats") == 0)
    // {
    //     path = strcat(path, "pokemon_stats.csv");
    //     file = fopen(path, "r");

    //     char pokemon_stats[6553];
    //     while (fgets(pokemon_stats, 6553, file))
    //     {
    //         char *v = strtok(pokemon_stats, ",");
    //         while (v)
    //         {
    //             printf("%s ", v);
    //             v = strtok(NULL, ",");
    //         }
    //         printf("\n");
    //     }
    //     fclose(file);
    // }

    // // stats.csv
    // if (strcmp(filename, "stats") == 0)
    // {
    //     path = strcat(path, "stats.csv");
    //     file = fopen(path, "r");

    //     char stats[90];
    //     while (fgets(stats, 90, file))
    //     {
    //         char *v = strtok(stats, ",");
    //         while (v)
    //         {
    //             printf("%s ", v);
    //             v = strtok(NULL, ",");
    //         }
    //         printf("\n");
    //     }
    //     fclose(file);
    // }

    // // pokemon_types.csv
    // if (strcmp(filename, "pokemon_types") == 0)
    // {
    //     path = strcat(path, "pokemon_types.csv");
    //     file = fopen(path, "r");

    //     char pokemon_types[1676];
    //     while (fgets(pokemon_types, 1676, file))
    //     {
    //         char *v = strtok(pokemon_types, ",");
    //         while (v)
    //         {
    //             printf("%s ", v);
    //             v = strtok(NULL, ",");
    //         }
    //         printf("\n");
    //     }
    //     fclose(file);
    // }
}
